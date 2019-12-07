#include "text.h"

Text::Text(RenderArea* r)
    :shapes(r)
{
    type = static_cast<Shape>(7);
}
