#include "shapes.h"
#include "renderarea.h"

int gProject::shapes::numShapes = 0;

gProject::shapes::shapes(RenderArea *ra)
{
    this->ra = ra;
    ra->setShape(type);
}

gProject::shapes::shapes(const shapes& s)
{
    this->ShapeID = s.ShapeID;
    this->type = s.type;
    this->ra = s.ra;
    this->outline = s.outline;
    this->perimeter = s.perimeter;
    this->area = s.area;
    this->set_points(s.points);
    this->alignment = s.alignment;
    this->textString = s.textString;
    this->textPointSize = s.textPointSize;
    this->tColor = s.tColor;
    this->textFontStyle = s.textFontStyle;
    this->textFontWeight = s.textFontWeight;
    this->textFontFamily = s.textFontFamily;
    this->pen = s.pen;
    this->brush = s.brush;
}

gProject::shapes::~shapes()
{

}

gProject::shapes gProject::shapes::operator= (const shapes& s)
{
    this->ShapeID = s.ShapeID;
    this->type = s.type;
    this->ra = s.ra;
    this->outline = s.outline;
    this->perimeter = s.perimeter;
    this->area = s.area;
    this->set_points(s.points);
    this->alignment = s.alignment;
    this->textString = s.textString;
    this->textPointSize = s.textPointSize;
    this->tColor = s.tColor;
    this->textFontStyle = s.textFontStyle;
    this->textFontWeight = s.textFontWeight;
    this->textFontFamily = s.textFontFamily;
    this->pen = s.pen;
    this->brush = s.brush;
    return *this;
}

void gProject::shapes::set_points(std::vector<QPoint> p)
{
    points = p;
}

std::vector<QPoint> gProject::shapes::get_points()
{
    return points;
}

void gProject::shapes::set_pen(Qt::GlobalColor c, int i, Qt::PenStyle p, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs)
{
    pen = QPen(c, i, p, pcs, pjs);
}

QPen gProject::shapes::get_pen()
{
    return pen;
}

void gProject::shapes::set_brush(Qt::GlobalColor c, Qt::BrushStyle b)
{
    brush = QBrush(c, b);
}

QBrush gProject::shapes::get_brush()
{
    return brush;
}

Shape gProject::shapes::getShape()
{
    return type;
}

void gProject::shapes::set_ID(int id)
{
    ShapeID = id;
}

int gProject::shapes::get_ID()
{
    return ShapeID;
}

void gProject::shapes::set_Rect(QRect r)
{
    outline = r;
}

QRect gProject::shapes::get_Rect()
{
    return outline;
}

void gProject::shapes::set_Alignment(Qt::AlignmentFlag a)
{
    alignment = a;
}

Qt::AlignmentFlag gProject::shapes::get_Alignment()
{
    return alignment;
}

void gProject::shapes::set_PointSize(int i)
{
    textPointSize = i;
}

int gProject::shapes::get_PointSize()
{
    return textPointSize;
}

void gProject::shapes::set_FontFamily(std::string s)
{
    textFontFamily = s;
}

std::string gProject::shapes::get_FontFamily()
{
    return textFontFamily;
}

void gProject::shapes::set_Text(std::string s)
{
    textString = s;
}

std::string gProject::shapes::get_Text()
{
    return textString;
}

void gProject::shapes::set_FontStyle(QFont::Style s)
{
    textFontStyle = s;
}

QFont::Style gProject::shapes::get_FontStyle()
{
    return textFontStyle;
}

void gProject::shapes::set_FontWeight(QFont::Weight s)
{
    textFontWeight = s;
}

QFont::Weight gProject::shapes::get_FontWeight()
{
    return textFontWeight;
}

void gProject::shapes::set_TextColor(Qt::GlobalColor c)
{
    tColor = c;
}

Qt::GlobalColor gProject::shapes::get_TextColor()
{
    return tColor;
}

void gProject::shapes::set_Perimeter(double d)
{
    perimeter = d;
}

void gProject::shapes::set_Area(double d)
{
    area = d;
}
