#include "ellipse.h"

/*!< Alternate Constructuor */
//!  Initializes the type data member
Ellipse::Ellipse(RenderArea *r)
    :shapes(r)
{
    type = static_cast<Shape>(5);
}

/*!< Function that returns the perimeter of the
                                     ellipse */
                                //!  Perimeter is calculated and then returned
double Ellipse::get_perimeter()
{
    if (outline.height() == outline.width()) return 2 * 3.14 * (outline.height() / 2);
    else return 0;
}

/*!< Function that returns the area of the
                                ellipse */
                                //!  Area is calculated and then returned
double Ellipse::get_area()
{
    return 3.14 * (outline.height() / 2) * (outline.width() / 2);
}
