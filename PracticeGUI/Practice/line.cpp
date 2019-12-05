#include "line.h"

Line::Line(RenderArea *r)
    :shapes(r)
{
    type = static_cast<Shape>(0);
}

void Line::set_points(QPoint* points)
{
    this->points = points;
}
