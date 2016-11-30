#include "ScreenBuffer.h"
#include <cassert>

using namespace std;

ScreenBuffer::ScreenBuffer(int width, int height) :
    m_width(width),
    m_height(height),
    m_data(m_height,
           vector<char>(m_width, ' '))
{
}

// TODO
void ScreenBuffer::setColor(
        const Point& p, char color)
{
    if(p.y < m_height && p.x < m_width &&
       p.y >= 0   &&   p.x >= 0)
        m_data[p.y][p.x] = color;
}

void ScreenBuffer::setColor(int x, int y, char color)
{
    setColor(Point(x, y), color);
}

char ScreenBuffer::color(const Point& p) const
{
    assert(p.y < m_height && p.x < m_width &&
       p.y >= 0   &&   p.x >= 0);
        return m_data[p.y][p.x];
}

char ScreenBuffer::color(int x, int y) const
{
    return color(Point(x, y));
}

int ScreenBuffer::height() const
{
    return m_height;
}

int ScreenBuffer::width() const
{
    return m_width;
}
