#include "text.h"

Text::Text(RenderArea* r)
    :shapes(r)
{
    type = static_cast<Shape>(5);
}

void Text::set_Rect(QRect r)
{
    outline = r;
}

QRect Text::get_Rect()
{
    return outline;
}

void Text::set_Alignment(Qt::AlignmentFlag af)
{
    alignment = af;
}

Qt::AlignmentFlag Text::get_Alignment()
{
    return alignment;
}

void Text::set_Text(std::string s)
{
    textString = s;
}

std::string Text::get_Text()
{
    return textString;
}
