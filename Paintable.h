#ifndef PAINTABLE_H
#define PAINTABLE_H

#include "Canvas.h"
#include "Factory.h"

struct Paintable :
    public Factory< Paintable >
{
    virtual ~Paintable() {}
    virtual void paint(Canvas& c) const = 0;
};


#endif // PAINTABLE_H
