#include "line.h"

/*!< alternate constructor */
/*!  Initializes the type data member*/
Line::Line(RenderArea *r)
    :gProject::shapes(r)
{
    type = static_cast<Shape>(0);
}

/*void Line::set_points(QPoint* points)
{
    this->points = points;
}

QPoint* Line::get_points()
{
    return this->points;
}*/
