#ifndef SCREENBUFFER_H
#define SCREENBUFFER_H

#include <vector>
#include <iostream>
#include "Point.h"

class ScreenBuffer
{
public:
    ScreenBuffer(int width, int height);
    void setColor(const Point& p, char color='*');
    void setColor(int x, int y, char color='*');

    /**
     * @brief returns color of a point
     * @param p Point to get clor at.
     * The x coordinate must be between
     * 0 and width()-1.
     * The y coordinate must be between
     * 0 and height()-1.
     * @return color of point @a p.
     */
    char color(const Point& p) const;
    char color(int x, int y) const;
    int height() const;
    int width() const;
    char operator()(int x, int y) const {
        return color(x, y);
    }

private:
    int m_width;
    int m_height;
    std::vector< std::vector<char> > m_data;
};

template< class Stream >
Stream& operator<<(
        Stream& s, const ScreenBuffer& c)
{
    for (int row=0; row<c.height(); ++row)
    {
        for (int col=0; col<c.width(); ++col)
            s << c.color(col, row);
        s << std::endl;
    }
    return s;
}

#endif // SCREENBUFFER_H
