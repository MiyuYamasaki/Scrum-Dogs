#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include "vector.h"

namespace n{

enum class penCapStyle {FlatCap, SquareCap, RoundCap};
enum class shapeType {Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text};
enum class penColor {white, black, red, green, blue, cyan, magenta, yellow, gray};
enum class penStyle {NoPen, SolidLine, DashLine, DotLine, DashDotLine, DashDotDotLine};
enum class penJoinStyle {MiterJoin, BevelJoin, RoundJoin};
enum class brushColor {white, black, red, green, blue, cyan, magenta, yellow, gray};
enum class brushStyle {SolidPattern, HorPattern, VerPattern, NoBrush};
enum class textColor {white, black, red, green, blue, cyan, magenta, yellow, gray};
enum class textAlignment {AlignLeft, AlignRight, AlignTop, AlignBottom, AlignCenter};
enum class textFontStyle {StyleNormal, StyleItalic, StyleOblique};
enum class textFontWeight {Thin, Light, Normal, Bold};


class shape
{

private:
    int shapeID;
    shapeType qShapeType;
    vector<double>* shapeDimensions = nullptr;
    penColor qPenColor;
    int penWidth;
    penStyle qPenStyle;
    penCapStyle qPenCapStyle;
    penJoinStyle qPenJoinStyle;
    brushColor qBrushColor;
    brushStyle qBrushStyle;
    std::string textString;
    textColor qTextColor;
    textAlignment qTextAlignment;
    int textPointSize;
    std::string textFontFamily;
    textFontStyle qTextFontStyle;
    textFontWeight qTextFontWeight;

public:
    shape(); //
    penCapStyle getPenCapStyle(); //
    penColor getPenColor();//
    int getPenWidth();//
    penStyle getPenStyle();//
    penJoinStyle getPenJointStyle();//
    brushColor getBrushColor();//
    brushStyle getBrushStyle();//
    int getShapeId();//
    vector<double>* getShapeDimensions();//

    void setPenCapStyle(penCapStyle style);//
    void setPenColor(penColor color);//
    void setPenWidth(int width);//
    void setPenStyle(penStyle style);//
    void setPenJoinStyle(penJoinStyle style);//
    void setBrushColor(brushColor color);//
    void setBrushStyle(brushStyle style);//
    void setShapeId(int iD);//
    void setShapeDimensions(vector<double> *dim);//

    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;

   virtual ~shape()
    {
        delete shapeDimensions;
    }
};
}

#endif // SHAPE_H
