#ifndef SHAPES_H
#define SHAPES_H

#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QWidget>
#include <vector.h>

class RenderArea;

enum Shape {LINE, POLYLINE, POLYGON, RECTANGLE, SQUARE, ELLIPSE, CIRCLE, TEXT};

namespace gProject
{
    class shapes
    {
        public:
            shapes() { }
            shapes(RenderArea *ra);
            shapes(const shapes&);
            virtual ~shapes();
            shapes operator= (const shapes&);
            void set_points(std::vector<QPoint>);
            std::vector<QPoint> get_points();
            void set_pen(Qt::GlobalColor, int, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
            QPen get_pen();
            void set_brush(Qt::GlobalColor, Qt::BrushStyle);
            QBrush get_brush();
            Shape getShape();
            void set_Rect(QRect);
            QRect get_Rect();
            void set_ID(int id);
            int get_ID();
            virtual double get_perimeter() {return 0;}
            virtual double get_area() {return 0;}
        protected:
            int ShapeID;
            Shape type;
            RenderArea* ra;
            QRect outline;
            std::vector<QPoint> points;
            QPainter painter;
            QPen pen;
            QBrush brush;
    };
}

#endif // SHAPES_H
