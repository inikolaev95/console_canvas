 #include "Shapes.h"

void CoordinateAxes::paint(Canvas &c) const
{

    for(double i = c.bottomLeft().x; i<= c.topRight().x;i = i + c.pixelWidth())
    {
    c.setColor(i,0);
    }
    for(double j = c.bottomLeft().y; j<= c.topRight().y;j = j + c.pixelHeight())
    {
    c.setColor(0,j);
    }
}


