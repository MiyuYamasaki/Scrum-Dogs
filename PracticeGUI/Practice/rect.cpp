#include "rect.h"

/* An alternate constuctor */
/*! The alternate constructor sets the type to 3 (Rectangle).*/
Rect::Rect(RenderArea *r)
    :shapes(r)
{
    type = static_cast<Shape>(3);
}

/* Returns the perimeter of the Rectangle */
/*!  Calculates and then returns a double (perimeter).*/
double Rect::get_perimeter()
{
    return (outline.height() * 2) + (outline.width() * 2);
}

/* Returns the area of the Rectangle */
/*!  Calculates and then returns a double (area).*/
double Rect::get_area()
{
    return outline.height() * outline.width();
}
