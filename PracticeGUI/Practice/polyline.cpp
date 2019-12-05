#include "polyline.h"

Polyline::Polyline(RenderArea *r)
    :shapes(r)
{
    type = static_cast<Shape>(1);
}
