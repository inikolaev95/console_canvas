#ifndef FACTORY_H
#define FACTORY_H

#include <string>
#include <memory>
#include <functional>
#include <map>
#include <cassert>

template< class Interface >
class Factory
{
public:
    typedef std::string TypeId;
    typedef std::shared_ptr<Interface> Ptr;

    static Ptr newInstance(const TypeId& typeId)
    {
        auto it = registry().find(typeId);
        if (it == registry().end())
            throw 123;  // TODO better
        return it->second();
    }

    typedef std::function<Ptr()> Generator;
    static void registerType(
            const TypeId& typeId,
            Generator generator)
    {
        assert(registry().count(typeId) == 0);
        registry()[typeId] = generator;
    }

private:
    typedef std::map<TypeId, Generator> Registry;

    static Registry& registry()
    {
        static Registry r;
        return r;
    }
};

template< class Interface, class Implementation >
struct FactoryRegistrator
{
    FactoryRegistrator(
            const typename Factory<Interface>::TypeId& typeId) {
        Interface::registerType(
                    typeId,
                    []() -> typename Interface::Ptr {
                        return std::make_shared<Implementation>();
                    });
    }
};

#define DECL_FACTORY_TYPE(Interface, Implementation, TypeId) \
    FactoryRegistrator<Interface, Implementation> Implementation##Registrator(TypeId);

#endif // FACTORY_H
