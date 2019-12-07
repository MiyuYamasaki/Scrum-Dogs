#include "square.h"

Square::Square(RenderArea *r)
    :shapes(r)
{
    type = static_cast<Shape>(4);
}

double Square::get_perimeter()
{
    return (outline.height() * 2) + (outline.width() + 2);
}

double Square::get_area()
{
    return outline.height() * outline.width();
}
