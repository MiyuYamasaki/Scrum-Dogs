#ifndef SHAPES_H
#define SHAPES_H

#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QWidget>
#include <vector.h>

class RenderArea;

namespace gProject
{
    enum Shape {line, polyline, polygon, rectangle, ellipse, text};

    class shapes
    {
        public:
            shapes(RenderArea *ra);
            virtual ~shapes();
            void set_pen(Qt::GlobalColor, int, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);
            QPen get_pen();
            void set_brush(Qt::GlobalColor, Qt::BrushStyle);
            QBrush get_brush();
            Shape getShape();
            void set_ID(int id);
            int get_ID();
            virtual double get_perimeter() {return 0;}
            virtual double get_area() {return 0;}
            void draw();
        protected:
            int ShapeID;
            Shape type;
            RenderArea* ra;
            QPainter painter;
            QPen pen;
            QBrush brush;
    };
}

#endif // SHAPES_H
