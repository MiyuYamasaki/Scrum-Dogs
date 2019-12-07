#include "shapes.h"
#include "renderarea.h"

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
