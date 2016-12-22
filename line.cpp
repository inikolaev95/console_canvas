<<<<<<< HEAD
#include "line.h"
#include "Variant.h"
#include "VariantMap.h"


Line::Line() {}

Line::Line(
        const PointF& p1,
        const PointF& p2):
    m_p1(p1),
    m_p2(p2)
        {}


void Line::paint(Canvas& c) const
{
    int A, B, sign;
    A = m_p2.y - m_p1.y;
    B = m_p1.x - m_p2.x;
    if (abs(A) > abs(B)) sign = 1;
    else sign = -1;
    int signa, signb;
    if (A < 0) signa = -1;
    else signa = 1;
    if (B < 0) signb = -1;
    else signb = 1;
    int f = 0;
    //c[m_p1.y][m_p1.x] = '*';
    auto x = m_p1.x, y = m_p1.y;
    if (sign == -1) {
      do {
        f += A*signa;
        if (f > 0) {
          f -= B*signb;
          y+=signa;
        }
        x-=signb;
        c.setColor(x,y);
      } while (x != m_p2.x || y != m_p2.y);
    } else {
      do {
        f += B*signb;
        if (f > 0) {
          f -= A*signa;
          x-=signb;
        }
        y+=signa;
       c.setColor(x,y);
      } while (x != m_p2.x || y != m_p2.y);
    }
  }


// Не понимаю, что просит. m_p1 существует.

void Line::load(const VariantMap& m)
{
    m_p1.load(m.get<VariantMap>("p1"));
    m_p2.load(m.get<VariantMap>("p2"));
}

VariantMap Line::save() const
{
    return VariantMap()
            << VariantMap::Item("p1", m_p1.save())
            << VariantMap::Item("p2", m_p2.save());
}


DECL_FACTORY_TYPE(Paintable, Line, "line")
=======
>>>>>>> parent of 7a43a0e... Add class "Line"
