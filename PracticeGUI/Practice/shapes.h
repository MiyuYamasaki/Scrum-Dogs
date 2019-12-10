#ifndef SHAPES_H
#define SHAPES_H

#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QWidget>
#include <vector.h>

/*!< A RenderArea Class */
/*! We are just using a forward declaration so the file knows what the
 RenderArea class is.*/
class RenderArea;

/*!< The gProject namespace */
/*! Namespace created to help manage the project.*/
namespace gProject
{
   /*!< A Shape enum */
  /*! The Shape enum is meant to help us parse the data.*/
   enum Shape {LINE, POLYLINE, POLYGON, RECTANGLE, SQUARE, ELLIPSE, CIRCLE, TEXT};

   /*!< A shapes Class */
   /*!  The shapes class is the base class for all the derived shapes.*/
   class shapes
   {
            public:
            static int numShapes;
            /*!< Default constructor */
             /*! This is an empty constructor.*/
                shapes() { }

             /*!<  Alternate Constructor */
             /*! This constuctor sets the RenderArea and the Shape type.*/
                shapes(RenderArea *ra);

            /*!< Copy constructor */
            /*!This constuctor copies the data from the parameter.*/
            shapes(const shapes&);
            /*!< Destructor for the shapes class */
            /*! This is a virtual destructor.*/
            virtual ~shapes();
            /*!< Overloaded assignment operator for the shapes class */
            /*! This copies the data from the parameter and returns the
                dereferenced this pointer.*/
            shapes operator= (const shapes&);
            void set_points(std::vector<QPoint>);
            std::vector<QPoint> get_points();
            /*!< This function sets the pen properties*/
            /*! The QPen data member is set.*/
            void set_pen(Qt::GlobalColor, int, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle);

            /*!< Getter for the QPen data member*/
            /*! The QPen data member is returned.*/
            QPen get_pen();

            /*!< Setter for the QBrush data member*/
            /*! The QBrush data member is set.*/
            void set_brush(Qt::GlobalColor, Qt::BrushStyle);

            /*!< Getter for the QBrush data member*/
            /*! The QBrush data member is returned.*/
            QBrush get_brush();
            Shape getShape();
            void set_Rect(QRect);
            QRect get_Rect();
            /*!< Setter for the ShapeID data member*/
            /*! The ShapeID data member is set.*/
            void set_ID(int id);

            /*!< Getter for the ShapeID data member*/
            /*! The ShapeID data member is returned.*/
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
