#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include "vector.h"

namespace n{

enum class penCapStyle {FlatCap, SquareCap, RoundCap};
static std::string penCapList[] = {"FlatCap", "SquareCap", "RoundCap"};
enum class shapeType {Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text};
static std::string shapeList[] = {"Line", "Polyline", "Rectangle", "Square", "Ellipse", "Circle", "Text"};
enum class penColor {white, black, red, green, blue, cyan, magenta, yellow, gray};
static std::string penColorList[] = {"white", "black", "red", "green", "blue", "cyan", "magenta", "yellow", "gray"};
enum class penStyle {NoPen, SolidLine, DashLine, DotLine, DashDotLine, DashDotDotLine};
static std::string penStyleList[] = {"NoPen", "SolidLine", "DashLine", "DotLine", "DashDotLine", "DashDotDotLine"};
enum class penJoinStyle {MiterJoin, BevelJoin, RoundJoin};
static std::string penJoinList[] = {"MiterJoin", "BevelJoin", "RoundJoin"};
enum class brushColor {white, black, red, green, blue, cyan, magenta, yellow, gray};
static std::string brushColorList[] = {"white", "black", "red", "green", "blue", "cyan", "magenta", "yellow", "gray"};
enum class brushStyle {SolidPattern, HorPattern, VerPattern, NoBrush};
static std::string brushStyleList[] = {"SolidPattern", "HorPattern", "VerPattern", "NoBrush"};
enum class textColor {white, black, red, green, blue, cyan, magenta, yellow, gray};
static std::string textColorList[] = {"white", "black", "red", "green", "blue", "cyan", "magenta", "yellow", "gray"};
enum class textAlignment {AlignLeft, AlignRight, AlignTop, AlignBottom, AlignCenter};
static std::string textAlignmentList[] = {"AlignLeft", "AlignRight", "AlignTop", "AlignBottom", "AlignCenter"};
enum class textFontStyle {StyleNormal, StyleItalic, StyleOblique};
static std::string textFontStyleList[] = {"StyleNormal", "StyleItalic", "StyleOblique"};
enum class textFontWeight {Thin, Light, Normal, Bold};
static std::string textFontWeightList[] = {"Thin", "Light", "Normal", "Bold"};


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
    shape();
    shape(int, shapeType, vector<double>*, penColor, int, penStyle, penCapStyle, penJoinStyle, brushColor, brushStyle, std::string, textColor, textAlignment, int, std::string, textFontStyle, textFontWeight);
    penCapStyle getPenCapStyle();
    penColor getPenColor();
    int getPenWidth();
    penStyle getPenStyle();
    penJoinStyle getPenJoinStyle();
    brushColor getBrushColor();
    brushStyle getBrushStyle();
    int getShapeId();
    vector<double>* getShapeDimensions();

    void setPenCapStyle(penCapStyle style);
    void setPenColor(penColor color);
    void setPenWidth(int width);
    void setPenStyle(penStyle style);
    void setPenJoinStyle(penJoinStyle style);
    void setBrushColor(brushColor color);
    void setBrushStyle(brushStyle style);
    void setShapeId(int iD);
    void setShapeDimensions(vector<double> *dim);

    virtual double getArea()
    {
        return 0;
    }
    virtual double getPerimeter()
    {
        return 0;
    }

    virtual ~shape()
    {
        delete shapeDimensions;
    }
};
}

#endif // SHAPE_H
