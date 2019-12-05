#include "shapeParser.h"
#include "circle.h"
#include "ellipse.h"
#include "line.h"
#include "polygon.h"
#include "polyline.h"
#include "rectangle.h"
#include "square.h"
#include "text.h"
#include <map>

using namespace n;

shapeParser::shapeParser()
{
}

vector<shape>* shapeParser::initializeVector()
{
    std::string readIn;
    double point;
    int temp = 0;
    vector<shape>* tempVector = new vector<shape>;
    circle* newCircle;
    ellipse* newEllipse;
    line* newLine;
    polygon* newPolygon;
    polyline* newPolyline;
    rectangle* newRectangle;
    square* newSquare;
    text* newText;

    fin.open("shapes.txt");
    while(!fin.eof()) {
        fin >> trash;
        fin >> shapeID;
        fin >> trash;
        fin.clear();
        getline(fin, readIn);
        for(int i = 0; i < 8; i++)
        {
            if(readIn == shapeList[i])
                sType = static_cast<shapeType>(i);
        }
        //getline(fin, sType);
        fin >> trash;
        fin.clear();
        shapeDimensions = new vector<double>;
        while(true)
        {
            fin >> point;
            if(fin.fail())
                break;
            shapeDimensions->push_back(point);
        }
        for(int i = 0; i < 9; i++)
            if(static_cast<int>(sType) == i)
                temp = i;
        switch(temp)
        {
            case 0:
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 9; i++)
                    if(readIn == penColorList[i])
                        pColor = static_cast<penColor>(i);
                fin >> trash;
                fin.clear();
                fin >> pWidth;
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 6; i++)
                    if(readIn == penStyleList[i])
                        pStyle = static_cast<penStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 3; i++)
                    if(readIn == penCapList[i])
                        pCapStyle = static_cast<penCapStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 3; i++)
                    if(readIn == penJoinList[i])
                        pJoinStyle = static_cast<penJoinStyle>(i);
                newLine = new line(shapeID, shapeDimensions, pColor, pWidth, pStyle, pCapStyle, pJoinStyle, )
                break;
            case 1:
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 9; i++)
                    if(readIn == penColorList[i])
                        pColor = static_cast<penColor>(i);
                fin >> trash;
                fin.clear();
                fin >> pWidth;
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 6; i++)
                    if(readIn == penStyleList[i])
                        pStyle = static_cast<penStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 3; i++)
                    if(readIn == penCapList[i])
                        pCapStyle = static_cast<penCapStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 3; i++)
                    if(readIn == penJoinList[i])
                        pJoinStyle = static_cast<penJoinStyle>(i);
                break;
            case 2:
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 9; i++)
                    if(readIn == penColorList[i])
                        pColor = static_cast<penColor>(i);
                fin >> trash;
                fin.clear();
                fin >> pWidth;
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 6; i++)
                    if(readIn == penStyleList[i])
                        pStyle = static_cast<penStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 3; i++)
                    if(readIn == penCapList[i])
                        pCapStyle = static_cast<penCapStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 3; i++)
                    if(readIn == penJoinList[i])
                        pJoinStyle = static_cast<penJoinStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 9; i++)
                    if(readIn == brushColorList[i])
                        bColor = static_cast<brushColor>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 4; i++)
                    if(readIn == brushStyleList[i])
                        bStyle = static_cast<brushStyle>(i);
                break;
            case 3:
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 9; i++)
                    if(readIn == penColorList[i])
                        pColor = static_cast<penColor>(i);
                fin >> trash;
                fin.clear();
                fin >> pWidth;
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 6; i++)
                    if(readIn == penStyleList[i])
                        pStyle = static_cast<penStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 3; i++)
                    if(readIn == penCapList[i])
                        pCapStyle = static_cast<penCapStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 3; i++)
                    if(readIn == penJoinList[i])
                        pJoinStyle = static_cast<penJoinStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 9; i++)
                    if(readIn == brushColorList[i])
                        bColor = static_cast<brushColor>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 4; i++)
                    if(readIn == brushStyleList[i])
                        bStyle = static_cast<brushStyle>(i);
                break;
            case 4:
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 9; i++)
                    if(readIn == penColorList[i])
                        pColor = static_cast<penColor>(i);
                fin >> trash;
                fin.clear();
                fin >> pWidth;
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 6; i++)
                    if(readIn == penStyleList[i])
                        pStyle = static_cast<penStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 3; i++)
                    if(readIn == penCapList[i])
                        pCapStyle = static_cast<penCapStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 3; i++)
                    if(readIn == penJoinList[i])
                        pJoinStyle = static_cast<penJoinStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 9; i++)
                    if(readIn == brushColorList[i])
                        bColor = static_cast<brushColor>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 4; i++)
                    if(readIn == brushStyleList[i])
                        bStyle = static_cast<brushStyle>(i);
                break;
            case 5:
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 9; i++)
                    if(readIn == penColorList[i])
                        pColor = static_cast<penColor>(i);
                fin >> trash;
                fin.clear();
                fin >> pWidth;
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 6; i++)
                    if(readIn == penStyleList[i])
                        pStyle = static_cast<penStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 3; i++)
                    if(readIn == penCapList[i])
                        pCapStyle = static_cast<penCapStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 3; i++)
                    if(readIn == penJoinList[i])
                        pJoinStyle = static_cast<penJoinStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 9; i++)
                    if(readIn == brushColorList[i])
                        bColor = static_cast<brushColor>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 4; i++)
                    if(readIn == brushStyleList[i])
                        bStyle = static_cast<brushStyle>(i);
                break;
            case 6:
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 9; i++)
                    if(readIn == penColorList[i])
                        pColor = static_cast<penColor>(i);
                fin >> trash;
                fin.clear();
                fin >> pWidth;
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 6; i++)
                    if(readIn == penStyleList[i])
                        pStyle = static_cast<penStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 3; i++)
                    if(readIn == penCapList[i])
                        pCapStyle = static_cast<penCapStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 3; i++)
                    if(readIn == penJoinList[i])
                        pJoinStyle = static_cast<penJoinStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 9; i++)
                    if(readIn == brushColorList[i])
                        bColor = static_cast<brushColor>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 4; i++)
                    if(readIn == brushStyleList[i])
                        bStyle = static_cast<brushStyle>(i);
                break;
            case 7:
                fin >> trash;
                fin.clear();
                getline(fin, tString);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 9; i++)
                    if(readIn == textColorList[i])
                        tColor = static_cast<textColor>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 5; i++)
                    if(readIn == textAlignmentList[i])
                        tAlignment = static_cast<textAlignment>(i);
                fin >> trash;
                fin.clear();
                fin >> tPointSize;
                fin >> trash;
                fin.clear();
                getline(fin, tFontFamily);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 3; i++)
                    if(readIn == textFontStyleList[i])
                        tFontStyle = static_cast<textFontStyle>(i);
                fin >> trash;
                fin.clear();
                getline(fin, readIn);
                for(int i = 0; i < 4; i++)
                    if(readIn == textFontWeightList[i])
                        tFontWeight = static_cast<textFontWeight>(i);
                break;
            default:
                std::cout << "Invalid shape read.\n";
                break;
        }
    }
    fin.close();
}
