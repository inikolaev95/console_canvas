#ifndef COORDINATEAXES_H
#define COORDINATEAXES_H

#include "Paintable.h"
#include "Persistent.h"

class CoordinateAxes :
        public Paintable,
        public Persistent
{
public:
    void paint(Canvas &c) const;
    void load(const VariantMap&);
    VariantMap save() const;
};

#endif // COORDINATEAXES_H
