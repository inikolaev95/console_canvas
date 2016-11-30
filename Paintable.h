#ifndef PAINTABLE_H
#define PAINTABLE_H

#include "Canvas.h"

struct Paintable
{
    virtual ~Paintable() {}
    virtual void paint(Canvas& c) const = 0;
};

#endif // PAINTABLE_H
