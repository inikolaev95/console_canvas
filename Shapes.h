#ifndef SHAPES_H
#define SHAPES_H

#include "Paintable.h"
#include <functional>

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

class Rectangle : public Shape
{
public:
    Rectangle(
            const PointF& bottomLeft,
            const PointF& topRight);
    void paint(Canvas& c) const;
private:
    PointF m_bottomLeft;
    PointF m_topRight;
};

class Ellipse : public Shape
{
public:
    Ellipse(
            const PointF& bottomLeft,
            const PointF& topRight);
    void paint(Canvas& c) const;
private:
    PointF m_bottomLeft;
    PointF m_topRight;
};

class Triangle : public Shape
{
public:
    Triangle(
            const PointF& v1,
            const PointF& v2,
            const PointF& v3);
    void paint(Canvas& c) const;
private:
    PointF m_v1;
    PointF m_v2;
    PointF m_v3;
};

class CoordinateAxes : public Paintable
{
public:
    void paint(Canvas &c) const;
};

class FunctionPlot : public Paintable
{
public:
    FunctionPlot(
            std::function<double(double)> f,
            char color);
    void paint(Canvas &c) const;
private:
    std::function<double(double)> m_f;
    char m_color;
};

#endif // SHAPES_H
