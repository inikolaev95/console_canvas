#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

#include "Paintable.h"
#include "Shapes.h"


using namespace std;



void plot(Canvas& c,
          function<double(double)> f,
          char color='*')
{
    auto h = c.pixelWidth();
    auto x2 = c.topRight().x + 0.5;
    for(auto x=c.bottomLeft().x; x<x2; x+=h)
        c.setColor(x, f(x), color);
}

void plot(Canvas& c, double (*f)(double), char color='*')
{
    plot(c, function<double(double)>(f), color);
}

template< typename T >
void plot(Canvas& c, T f, char color='*')
{
    plot(c, function<double(double)>(f), color);
}


double f(double x, double y) {
    return x-y;
}

void helloBind()
{
    using namespace placeholders;
    auto g = bind(f, _2, _1);

    cout << f(1, 2) << endl;
    cout << g(1, 2) << endl;

    auto fff = bind(&PointF::infNorm, PointF(5, -6.6));
    cout << fff() << endl;
}

int main()
{
    try {
        // p1(1,2);
        //PointF p2 = p1.convertTo<double>();
        // cout << p2;

        ScreenBuffer sb(79, 23);
        Canvas c(&sb,
               PointF(0, 0), PointF(1, 1));


        auto r = Paintable::newInstance("line");




        load(r, VariantMap()
             << VariantMap::Item( "p1", VariantMap() << VariantMap::Item("p1", PointF(0.1,0.1)))
             << VariantMap::Item( "p2", VariantMap() << VariantMap::Item("p2", PointF(0.9,0.9))));

        r->paint(c);



//        CoordinateAxes().paint(c);
        // FunctionPlot(sin, '*').paint(c);

        /*
        c.setColor(0, 0);
        c.setColor(0.5, 0.5, '+');
        c.setColor(c.bottomLeft(), '<');
        c.setColor(c.topRight(), '>');

        plot(c, [](double x) -> double {
            return sin(1/x);
        });

        plot(c, sin, 'O');

        auto f = [](double x, double y) -> double {
            return x*y;
        };

        using namespace placeholders;
        plot(c, bind(f, _1, 1), '-');
        plot(c, bind(f, _1, 0.5), '+');
        plot(c, bind(f, _1, 2), '/');
        */

        cout << *c.screenBuffer();
        // c.setColor(0, 1.5);
        // c.color(33, 34);
        // helloBind();
    }
    catch(int x) {
        cerr << "caught int = " << x << endl;
    }
    catch(double x) {
        cerr << "caught double = " << x << endl;
    }
    catch(string s) {
        cerr << "ERROR: " << s << endl;
    }
    return 0;
}


struct B {
    int b;
};
