#include "text.h"

Text::Text(RenderArea* r)	/*!< alternate constructor */
    :shapes(r)
/*!< Inherits rendered area from shapes class */
{
    type = static_cast<Shape>(7);
//! casts shape object
}
