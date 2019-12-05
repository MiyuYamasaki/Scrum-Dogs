#include "rect.h"

Rect::Rect(RenderArea *r)
    :shapes(r)
{
    type = static_cast<Shape>(3);
}

void Rect::set_Rect(QRect r)
{
    outline = r;
}

QRect Rect::get_Rect()
{
    return outline;
}

double Rect::get_perimeter()
{
    return (outline.height() * 2) + (outline.width() + 2);
}

double Rect::get_area()
{
    return outline.height() * outline.width();
}
