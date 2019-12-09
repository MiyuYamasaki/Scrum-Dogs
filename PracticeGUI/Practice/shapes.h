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
            static int numShapes;
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
            void set_Alignment(Qt::AlignmentFlag);
            Qt::AlignmentFlag get_Alignment();
            void set_PointSize(int);
            int get_PointSize();
            void set_FontFamily(std::string);
            std::string get_FontFamily();
            void set_Text(std::string);
            std::string get_Text();
            void set_FontStyle(QFont::Style);
            QFont::Style get_FontStyle();
            void set_FontWeight(QFont::Weight);
            QFont::Weight get_FontWeight();
            void set_TextColor(Qt::GlobalColor);
            Qt::GlobalColor get_TextColor();
            void set_Perimeter(double d);
            void set_Area(double d);
            double get_perimeter() {return perimeter;}
            double get_area() {return area;}
        protected:
            int ShapeID;
            Shape type;
            RenderArea* ra;
            QRect outline;
            std::vector<QPoint> points;
            double perimeter = 0;
            double area = 0;
            Qt::AlignmentFlag alignment;
            std::string textString;
            int textPointSize;
            Qt::GlobalColor tColor;
            QFont::Style textFontStyle;
            QFont::Weight textFontWeight;
            std::string textFontFamily;
            QPainter painter;
            QPen pen;
            QBrush brush;
    };
}

#endif // SHAPES_H
