#include "ellipse.h"

Ellipse::Ellipse(RenderArea *r)
    :shapes(r)
{
    type = static_cast<Shape>(5);
}

double Ellipse::get_perimeter()
{
    if (outline.height() == outline.width()) return 2 * 3.14 * (outline.height() / 2);
    else return 0;
}

double Ellipse::get_area()
{
    return 3.14 * (outline.height() / 2) * (outline.width() / 2);
}
