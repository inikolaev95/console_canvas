#ifndef SHAPE_H
#define SHAPE_H

#include "Paintable.h"

class Shape : public Paintable
{
public:
    Shape();
    char fillColor() const;
    void setFillColor(char fillColor);
    char outlineColor() const;
    void setOutlineColor(char outlineColor);
private:
    char m_fillColor;
    char m_outlineColor;
};

#endif // SHAPE_H
