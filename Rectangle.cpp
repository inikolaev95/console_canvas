#include "Rectangle.h"

Rectangle::Rectangle() {}

Rectangle::Rectangle(
        const PointF& bottomLeft,
        const PointF& topRight) :
    m_bottomLeft(bottomLeft),
    m_topRight(topRight)
{
}

void Rectangle::paint(Canvas& c) const
{
    double ymax,ymin,xmax,xmin;
        if(this->m_topRight.y>m_bottomLeft.y)
        {
            ymax=this->m_topRight.y;
            ymin=this->m_bottomLeft.y;
        }
        else
        {
            ymin=this->m_topRight.y;
            ymax=this->m_bottomLeft.y;
        }
        if(m_topRight.x>m_bottomLeft.x)
        {
            xmax=this->m_topRight.x;
            xmin=this->m_bottomLeft.x;
        }
        else
        {
            xmin=this->m_topRight.x;
            xmax=this->m_bottomLeft.x;
        }
        for(int i=0;i<(ymax-ymin)/c.pixelHeight();i++)
            for(int j=0;j<(xmax-xmin)/c.pixelWidth();j++)
            {
                if((i>0&&i<(ymax-ymin)/c.pixelHeight()-1)&&(j>1&&
                        j<(xmax-xmin)/c.pixelWidth()-1))
                {
                    c.setColor(xmin+j*c.pixelWidth(),ymin+i*c.pixelHeight(),this->fillColor());
                }
                else
                {
                    c.setColor(xmin+j*c.pixelWidth(),ymin+i*c.pixelHeight(),this->outlineColor());
                }
            }
        /*for(int i=0;i<(ymax-ymin)/c.pixelHeight();i++)
        {
                c.setColor(xmin+0*c.pixelWidth(),ymin+i*c.pixelHeight(),this->outlineColor());
                c.setColor(xmin+((xmax-xmin)/c.pixelWidth()-1)*c.pixelWidth(),ymin+i*c.pixelHeight(),this->outlineColor());
        }
        for(int j=0;j<(xmax-xmin)/c.pixelWidth();j++)
        {
            c.setColor(xmin+j*c.pixelWidth(),ymin+0*c.pixelHeight(),this->outlineColor());
            c.setColor(xmin+j*c.pixelWidth(),ymin+((ymax-ymin)/c.pixelHeight())*c.pixelHeight(),this->outlineColor());
        }
        for(int i=1;i<(ymax-ymin)/c.pixelHeight()-1;i++)
            for(int j=2;j<(xmax-xmin)/c.pixelWidth()-1;j++)
            {
                c.setColor(xmin+j*c.pixelWidth(),ymin+i*c.pixelHeight(),this->fillColor());
            }*/
}

void Rectangle::load(const VariantMap& m)
{
    m_bottomLeft.load(m.get<VariantMap>("bottomLeft"));
    m_topRight.load(m.get<VariantMap>("topRight"));
}

VariantMap Rectangle::save() const
{
    return VariantMap()
            << VariantMap::Item("bottomLeft", m_bottomLeft.save())
            << VariantMap::Item("topRight", m_topRight.save());
}

DECL_FACTORY_TYPE(Paintable, Rectangle, "rectangle")
