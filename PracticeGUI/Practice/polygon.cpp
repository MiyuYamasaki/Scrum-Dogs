#include "polygon.h"

Polygon::Polygon(RenderArea *r)
        :shapes(r)
{
    type = static_cast<Shape>(2);
}

double Polygon::get_perimeter()
{
    return 0;
}

double Polygon::get_area()
{
    return 0;
}
