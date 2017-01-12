#include "Shapes.h"

void CoordinateAxes::paint(Canvas &c) const
{
    c.setColor(0, 0, '0');
    c.setColor(0, 1, '1');
    c.setColor(1, 0, '1');
    double hX = fabs((c.topRight().x - c.bottomLeft().x) / 10);
    double hY = fabs((c.topRight().y - c.bottomLeft().y) / 10);
    for(int i = 1; i < 10; i++ ){
        /*
        c.setColor(i * hX - c.pixelWidth() * 3, c.bottomLeft().y, '0');
        c.setColor(i * hX - c.pixelWidth() * 2, c.bottomLeft().y, ',');
        c.setColor(i * hX -  c.pixelWidth(), c.bottomLeft().y, (int)(i * hX / 0.1) + 48);
        */

        c.setColor(i * hX - c.pixelWidth() * 2, c.bottomLeft().y, '0');
        c.setColor(i * hX - c.pixelWidth() * 1, c.bottomLeft().y, ',');
        c.setColor(i * hX, c.bottomLeft().y, (int)(i * hX / 0.1) + 48);

        c.setColor(c.bottomLeft().x, i * hY, '0');
        c.setColor(c.bottomLeft().x + c.pixelWidth() * 2, i * hY ,',');
        c.setColor(c.bottomLeft().x + c.pixelWidth() * 3, i * hY, (int)(i * hY / 0.1) + 48);
    }
    for(double i = 0; i <= 1 + c.pixelWidth(); i += c.pixelWidth()){
        c.setColor(i, c.bottomLeft().y + c.pixelWidth(), '_');
        c.setColor(c.bottomLeft().x + c.pixelWidth() * 4, i,'|');
    }
}


