#ifndef SHAPEPARSER_H
#define SHAPEPARSER_H

#include <shapes.h>
#include <ellipse.h>
#include <circle.h>
#include <line.h>
#include <polyline.h>
#include <polygon.h>
#include <rect.h>
#include <square.h>
#include <text.h>
#include <fstream>

static std::string shapeList[] = {"Line", "Polyline", "Polygon", "Rectangle", "Square", "Ellipse", "Circle", "Text"};
static std::string colorList[] = {"black", "white", "darkGray", "gray", "lightGray", "red", "green", "blue", "cyan", "magenta", "yellow"};
static std::string penCapList[] = {"FlatCap", "SquareCap", "RoundCap"};
static std::string penJoinList[] = {"MiterJoin", "BevelJoin", "RoundJoin"};
static std::string penStyleList[] = {"NoPen", "SolidLine", "DashLine", "DotLine", "DashDotLine", "DashDotDotLine"};
static std::string brushStyleList[] = {"SolidPattern", "HorPattern", "VerPattern", "NoBrush"};
static std::string textAlignmentList[] = {"AlignLeft", "AlignRight", "AlignTop", "AlignBottom", "AlignCenter"};
static std::string textFontStyleList[] = {"StyleNormal", "StyleItalic", "StyleOblique"};
static std::string textFontWeightList[] = {"Thin", "Light", "Normal", "Bold"};

class ShapeParser
{
    public:
        ShapeParser();
        vector<gProject::shapes>* InitializeVector(RenderArea* ra);
    private:
        vector<gProject::shapes>* newVector = nullptr;
};

#endif // SHAPEPARSER_H
