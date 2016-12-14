 #include "Shapes.h"

void CoordinateAxes::paint(Canvas &c) const
{

    for(double i = c.bottomLeft().x+c.pixelWidth(); i< c.topRight().x;i = i + c.pixelWidth())
    {
        c.setColor(i,0, '-');
    }
    for(double j = c.bottomLeft().y+c.pixelHeight(); j< c.topRight().y;j = j + c.pixelHeight())
    {
        c.setColor(0,j,'|');
    }
    c.setColor(c.bottomLeft().x,c.topRight().y,'^');
    c.setColor(c.topRight().x,c.bottomLeft().y,'>');
    c.setColor(c.bottomLeft().x,c.bottomLeft().y,'+');
}


void CoordinateAxes::load(const VariantMap& m)
{
}

VariantMap CoordinateAxes::save() const
{
    return VariantMap();
}

DECL_FACTORY_TYPE(Paintable,CoordinateAxes, "coordinate_axes")

