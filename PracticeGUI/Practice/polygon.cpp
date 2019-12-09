#include "polygon.h"

Polygon::Polygon(RenderArea *r)
        :shapes(r)
{
    type = static_cast<Shape>(2);
}
