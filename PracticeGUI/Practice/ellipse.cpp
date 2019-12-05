#include "ellipse.h"

Ellipse::Ellipse(RenderArea *r)
    :shapes(r)
{
    type = static_cast<Shape>(4);
}

void Ellipse::set_Rect(QRect r)
{
    outline = r;
}

QRect Ellipse::get_Rect()
{
    return outline;
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
