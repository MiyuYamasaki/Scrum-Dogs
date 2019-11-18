#include <iostream>
#include <fstream>
#include "shape.h"

using namespace n;

class shapeParser
{
private:
    vector<shape>* sList = new vector<shape>;
    shape* temp = nullptr;
    std::ifstream fin;
    std::ofstream fout;
    std::string trash;
    int shapeID;
    shapeType sType;
    vector<double>* shapeDimensions = nullptr;
    penColor pColor;
    int pWidth;
    penStyle pStyle;
    penCapStyle pCapStyle;
    penJoinStyle pJoinStyle;
    brushColor bColor;
    brushStyle bStyle;
    std::string tString;
    textColor tColor;
    textAlignment tAlignment;
    int tPointSize;
    std::string tFontFamily;
    textFontStyle tFontStyle;
    textFontWeight tFontWeight;

public:
    shapeParser(); //Constructor
    vector<shape>* initializeVector();
}
