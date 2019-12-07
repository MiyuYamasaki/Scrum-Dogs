#include "circle.h"

Circle::Circle(RenderArea *r)
    :shapes(r)
{
    type = static_cast<Shape>(6);
}

double Circle::get_perimeter()
{
    if (outline.height() == outline.width()) return 2 * 3.14 * (outline.height() / 2);
    else return 0;
}

double Circle::get_area()
{
    return 3.14 * (outline.height() / 2) * (outline.width() / 2);
}
