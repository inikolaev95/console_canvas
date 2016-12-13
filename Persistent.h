#ifndef PERSISTENT_H
#define PERSISTENT_H

#include "VariantMap.h"
#include <memory>

struct Persistent
{
    virtual ~Persistent() {}
    virtual void load(const VariantMap&) = 0;
    virtual VariantMap save() const = 0;
};

template< class T >
inline void load(const std::shared_ptr<T>& p, const VariantMap& m)
{
    auto persistent = dynamic_cast<Persistent*>(p.get());
    assert(persistent);
    persistent->load(m);
}

template< class T >
inline VariantMap save(const std::shared_ptr<T>& p)
{
    auto persistent = dynamic_cast<const Persistent*>(p.get());
    assert(persistent);
    return persistent->save();
}

#endif // PERSISTENT_H
