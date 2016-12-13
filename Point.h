#ifndef POINT_H
#define POINT_H

#include <algorithm>
#include "Persistent.h"

template< class T >
struct PointTemplate : public Persistent
{
    T x;
    T y;

//    template< class T2 >
//    PointTemplate(
//        const PointTemplate<T2>& that) :
//            x(that.x), y(that.y) {}

    PointTemplate() : x(0), y(0) {}
    PointTemplate(T x, T y) :
        x(x), y(y) {}

    template< class T2 >
    PointTemplate<T2> convertTo() const {
        return PointTemplate<T2>(x, y);
    }

    T infNorm() const {
        return std::max(std::abs(x), std::abs(y));
    }

    void load(const VariantMap& m) {
        x = m.get<T>("x");
        y = m.get<T>("y");
    }

    VariantMap save() const {
        return VariantMap()
                << VariantMap::Item("x", x)
                << VariantMap::Item("y", y);

    }
};

typedef PointTemplate<int> Point;
typedef PointTemplate<double> PointF;

template< class Stream, class T >
Stream& operator<<(
        Stream& s,
        const PointTemplate<T>& p)
{
    s << '(' << p.x << ", "
      << p.y << ')';
    return s;
}

#endif // POINT_H
