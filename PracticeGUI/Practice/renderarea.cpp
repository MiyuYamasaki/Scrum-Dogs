#include "renderarea.h"

#include <QPainter>

#include "shapes.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    shape = POLYGON;
    antialiased = false;
    transformed = false;

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    ShapeParser sp;
    sList = sp.InitializeVector(this);
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
    std::vector<QPoint> points;

    do{
        shape = first->getShape();
        painter.setRenderHint(QPainter::Antialiasing, false);
        //painter.setBrush(first->get_brush());
        points = (*first).get_points();
        int size = static_cast<int>(points.size());
        QPoint* arrPoints = new QPoint[size];
        switch(shape)
        {
            case LINE:
                this->setPen(first->get_pen());
                painter.setPen(first->get_pen());
                painter.drawLine(QLine(points[0], points[1]));
                break;
            case POLYLINE:
                this->setPen(first->get_pen());
                painter.setPen(first->get_pen());
                for (int i = 0; i < size; i++)
                    arrPoints[i] = points[i];
                painter.drawPolyline(arrPoints, size);
                break;
            case POLYGON:
                this->setPen(first->get_pen());
                painter.setPen(first->get_pen());
                painter.setBrush(first->get_brush());
                for (int i = 0; i < size; i++)
                    arrPoints[i] = points[i];
                painter.drawPolygon(arrPoints, size);
                break;
            case RECTANGLE:
                this->setPen(first->get_pen());
                painter.setPen(first->get_pen());
                painter.setBrush(first->get_brush());
                painter.drawRect((*first).get_Rect());
                break;
            case SQUARE:
                this->setPen(first->get_pen());
                painter.setPen(first->get_pen());
                painter.setBrush(first->get_brush());
                painter.drawRect((*first).get_Rect());
                break;
            case ELLIPSE:
                this->setPen(first->get_pen());
                painter.setPen(first->get_pen());
                painter.setBrush(first->get_brush());
                painter.drawEllipse((*first).get_Rect());
                break;
            case CIRCLE:
                this->setPen(first->get_pen());
                painter.setPen(first->get_pen());
                painter.setBrush(first->get_brush());
                painter.drawEllipse((*first).get_Rect());
                break;
            case TEXT:
                this->setPen(first->get_pen());
                painter.setPen(first->get_pen());
                painter.setBrush(first->get_brush());
                painter.drawText((*(dynamic_cast<class Text*>(first))).get_Rect(),Qt::AlignCenter, "Hello");
                break;
        }
    }while(++first != last);
    //painter.restore();
}


void RenderArea::closeEvent(QCloseEvent *)
{
    /*
    std::ofstream fout;
    fout.open("shapesOutput.txt");
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
                fout << "BrushColor: " << colorList[(*first).get_brush().color()] << std::endl;
                fout << "BrushStyle: " << brushStyleList[(*first).get_brush().style()] << std::endl;
            case line:
            case polyline:
                fout << "PenColor: " << colorList[(*first).get_pen().color()] << std::endl;
                fout << "PenWidth: " << (*first).get_pen().width();
                fout << "PenStyle: " << penStyleList[(*first).get_pen().style()] << std::endl;
                fout << "PenCapStyle: " << penCapList[(*first).get_pen().capStyle()] << std::endl;
                fout << "PenJoinStyle: " << penJoinList[(*first).get_pen().joinStyle()] << std::endl;
                break;
            case text:
                //fout << "TextString: " << dynamic_cast<class Text*>(first)->get_Text() << std::endl;
                //fout << "TextColor: " << colorList[(*first).get_pen().color()] << std::endl;
                //fout << "TextAlignment: " << alignmentList[dynamic_cast<class Text*>(first)->get_Alignment()] << std::endl;
                //fout << "TextPointSize: "
                break;
        }
    }

    fout.close();
    */
}
