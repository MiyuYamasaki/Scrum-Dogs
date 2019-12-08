#include "circle.h"

Circle::Circle(RenderArea *r)  /*!< alternate constructor */
    :shapes(r)
/*!< circle class that inherits rendered area from shapes class */
{
    type = static_cast<Shape>(6);
//! Shape is type cast
}

double Circle::get_perimeter()  /*!< Getter function */
 /*! Function gets perimeter */
{
    if (outline.height() == outline.width()) return 2 * 3.14 * (outline.height() / 2);
    else return 0;
}

double Circle::get_area()  /*!< Getter function */
/*! Function gets area */
{
    return 3.14 * (outline.height() / 2) * (outline.width() / 2);
}
