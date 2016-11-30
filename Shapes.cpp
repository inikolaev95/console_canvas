#include "Shapes.h"

Shape::Shape() :
    m_fillColor('.'),
    m_outlineColor('#')
{}

char Shape::fillColor() const
{
    return m_fillColor;
}

void Shape::setFillColor(char fillColor)
{
    m_fillColor = fillColor;
}

char Shape::outlineColor() const
{
    return m_outlineColor;
}

void Shape::setOutlineColor(char outlineColor)
{
    m_outlineColor = outlineColor;
}
