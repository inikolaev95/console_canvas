#ifndef VARIANTMAP_H
#define VARIANTMAP_H

#include "Variant.h"
#include <map>

class VariantMap
{
public:
    typedef std::map< std::string, Variant > Data;
    typedef Data::value_type Item;

    VariantMap& operator<<(const Item& item) {
        m_data.insert(item);
        return *this;
    }

    template<class T>
    T& get(const std::string& key)
    {
        auto it = m_data.find(key);
        assert(it != m_data.end());
        return it->second.get<T>();
    }

    template<class T>
    T cget(const std::string& key, const T& defaultValue = T()) const
    {
        auto it = m_data.find(key);
        return it == m_data.end() ?   defaultValue :   it->second.get<T>();
    }

    template<class T>
    T get(const std::string& key, const T& defaultValue = T()) const {
        return cget(key, defaultValue);
    }

//    using getMap = get<VariantMap>;
//    using cgetMap = cget<VariantMap>;

private:
    Data m_data;
};

#endif // VARIANTMAP_H

