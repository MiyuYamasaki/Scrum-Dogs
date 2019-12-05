#include "renderarea.h"

#include <QPainter>

#include "shapes.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    shape = polygon;
    antialiased = false;
    transformed = false;

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(1000, 500);
}

QSize RenderArea::sizeHint() const
{
    return QSize(1000, 500);
}

void RenderArea::setShape(Shape shape)
{
    this->shape = shape;
    update();
}

void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}

void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}

void RenderArea::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}

void RenderArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    vector<gProject::shapes>::iterator first = sList->begin();
    vector<gProject::shapes>::iterator last = sList->end();
    do{
        for(int i = 0; i < 6; i++)
            if((*first).getShape() == i)
                shape = static_cast<Shape>(i);
        painter.setRenderHint(QPainter::Antialiasing, false);
        painter.setPen((*first).get_pen());
        painter.setBrush((*first).get_brush());
        switch(shape)
        {
            case line:
                painter.drawLine(QPoint(10, 10), QPoint(100, 100));
                break;
            case polyline:
                //painter.drawPolyline(Array of QPoints, # of points);
                break;
            case polygon:
                //painer.drawPolygon(Array of QPoints, # of points);
                break;
            case rectangle:
                painter.drawRect((*(dynamic_cast<class Rect*>(first))).get_Rect());
                break;
            case ellipse:
                painter.drawEllipse((*(dynamic_cast<class Ellipse*>(first))).get_Rect());
                break;
            case text:
                painter.drawText((*(dynamic_cast<class Text*>(first))).get_Rect(),Qt::AlignCenter, "Hello");
                break;
        }
    }while(++first != last);
    painter.restore();
}

void RenderArea::closeEvent(QCloseEvent *)
{
    std::ofstream fout;
    vector<gProject::shapes>::iterator first = sList->begin();
    vector<gProject::shapes>::iterator last = sList->end();

    while(first != last)
    {
        fout << "ShapeId: " << (*first).get_ID() << std::endl;
        fout << "ShapeType: ";
        for(int i = 0; i < 6; i++)
            if((*first).getShape() == i)
                fout << shapeList[i] << std::endl;
        fout << "ShapeDimensions: " << std::endl;
        switch((*first).getShape())
        {
            case polygon:
            case rectangle:
            case ellipse:
                fout << "BrushColor: " /*<< colorList[(*first).get_brush().color()]*/ << std::endl;
                fout << "BrushStyle: " /*<< brushStyleList[(*first).get_brush().style()]*/ << std::endl;
            case line:
            case polyline:
                fout << "PenColor: " /*<< colorList[(*first).get_pen().color()]*/ << std::endl;
                fout << "PenWidth: " << (*first).get_pen().width();
                fout << "PenStyle: " /*<< penStyleList[(*first).get_pen().style()]*/ << std::endl;
                fout << "PenCapStyle: " /*<< penCapList[(*first).get_pen().capStyle()]*/ << std::endl;
                fout << "PenJoinStyle: " /*<< penJoinList[(*first).get_pen().joinStyle()]*/ << std::endl;
                break;
            case text:
                //fout << "TextString: " << dynamic_cast<class Text*>(first)->get_Text() << std::endl;
                //fout << "TextColor: " /*<< colorList[(*first).get_pen().color()]*/ << std::endl;
                //fout << "TextAlignment: " /*<< alignmentList[dynamic_cast<class Text*>(first)->get_Alignment()]*/ << std::endl;
                //fout << "TextPointSize: "
                break;
        }
    }
}
