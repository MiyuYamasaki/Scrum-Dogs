#include "polygon.h"

/* An alternate constructor */
/*! This constructor sets the type to a 2 (a polygon).*/
Polygon::Polygon(RenderArea *r)
        :shapes(r)
{
    type = static_cast<Shape>(2);
}
