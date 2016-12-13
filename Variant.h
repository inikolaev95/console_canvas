#ifndef VARIANT_H
#define VARIANT_H

#include <string>
#include <functional>
#include <typeinfo>
#include <cassert>

class Variant
{
public:
    Variant() : m_data(nullptr) {}

    template< class T >
    Variant(const T& that) {
        init<T>(new T(that));
    }

    Variant(const Variant& that) :
        m_data(that.m_clone(that.m_data)),
        m_type(that.m_type),
        m_destroy(that.m_destroy),
        m_clone(that.m_clone)
    {

    }

    ~Variant()
    {
        clear();
    }

    Variant& operator=(const Variant& that)
    {
        if (&that != this) {
            clear();
            m_data = that.m_clone(that.m_data);
            m_type = that.m_type;
            m_destroy = that.m_destroy;
            m_clone = that.m_clone;
        }
        return *this;
    }

    template< class T >
    T& get() {
        assert( isOfType<T>() );
        return *reinterpret_cast<T*>(m_data);
    }

    template< class T >
    const T& cget() const {
        return const_cast<Variant*>(this)->get<T>();
    }

    template< class T >
    const T& get() const {
        return cget<T>();
    }

    bool isValid() const {
        return m_data != nullptr;
    }

    template< class T >
    bool isOfType() const {
        return m_type == typeid(T).name();
    }

private:
    void *m_data;
    std::string m_type;
    std::function<void(const void*)> m_destroy;
    std::function<void*(const void*)> m_clone;

    template< class T >
    void init(void *data)
    {
        m_data = data;
        m_type = typeid(T).name();
        m_destroy = [](const void * data) {
            delete reinterpret_cast<const T*>(data);
        };
        m_clone = [](const void *data) -> void* {
            return new T(*reinterpret_cast<const T*>(data));
        };
    }

    void clear()
    {
        if (m_data) {
            m_destroy(m_data);
            m_data = nullptr;
        }
    }
};

#endif // VARIANT_H

