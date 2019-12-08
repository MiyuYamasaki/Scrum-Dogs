#include "square.h"
Square::Square(RenderArea *r)
    :shapes(r)	/*! Alternate constructor renders the area */
{
    type = static_cast<Shape>(4);
    //type cast type as a shape object as a Square
}

double Square::get_perimeter() /*!< Gets the perimeter */
{
    return (outline.height() * 2) + (outline.width() + 2);
    //! returns the perimeter of the outline
}

double Square::get_area()      /*!< Gets the area      */
{
    return outline.height() * outline.width();
    //! returns the area of the outline
}
