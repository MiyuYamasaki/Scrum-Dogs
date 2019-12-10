#include "polyline.h"

/* An Alternate Constructor */
/*! This sets the type to 1 a polyline.*/
Polyline::Polyline(RenderArea *r)
    :shapes(r)
{
    type = static_cast<Shape>(1);
}
