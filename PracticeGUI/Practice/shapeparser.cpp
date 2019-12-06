#include "shapeparser.h"

ShapeParser::ShapeParser()
{
}

vector<gProject::shapes>* ShapeParser::InitializeVector(RenderArea* ra)
{
    newVector = new vector<gProject::shapes>;
    std::ifstream fin;
    std::ofstream fout;
    std::string trash;
    std::string temp;
    int shapeID;
    gProject::shapes* tempShape = nullptr;
    Shape type;
    Qt::GlobalColor pColor = Qt::black;
    int pWidth = 0;
    Qt::PenStyle pStyle = Qt::DotLine;
    Qt::PenCapStyle pcStyle = Qt::FlatCap;
    Qt::PenJoinStyle pjStyle = Qt::MiterJoin;
    //Qt::GlobalColor bColor;
    //Qt::BrushStyle bStyle;
    QPoint* oldPoints = nullptr;
    QPoint* newPoints = nullptr;
    int pointCount;
    int x;
    int y;

    fin.open("shapes.txt");
    fout.open("shapesOutput.txt");
    fin >> trash;
    fin >> trash;
    fin >> shapeID;
    fin >> trash;
    fin >> temp;
    for(int i = 0; i < 6; i++)
        if(temp == shapeList[i])
            type = static_cast<Shape>(i);
    fin >> trash;
    fin >> temp;
    pointCount = 0;
    do{
        x = std::stoi(temp.substr(0,2));
        fin >> temp;
        y = std::stoi(temp.substr(0,2));
        pointCount++;

        newPoints = new QPoint[pointCount];
        newPoints[pointCount - 1] = QPoint(x,y);
        if(pointCount > 1)
            for(int i = 0; i < pointCount - 1; i++)
                newPoints[i] = oldPoints[i];
        delete [] oldPoints;
        oldPoints = newPoints;
        fin >> temp;
    }while(pointCount != 2);

    fin >> trash;
    fin >> temp;
    for(int i = 0; i < 9; i++)
        if(temp == colorList[i])
            pColor = static_cast<Qt::GlobalColor>(i);
    fin >> trash;
    fin >> pWidth;
    fin >> trash;
    fin >> temp;
    for(int i = 0; i < 6; i++)
        if(temp == penStyleList[i])
            pStyle = static_cast<Qt::PenStyle>(i);
    fin >> trash;
    fin >> temp;
    for(int i = 0; i < 3; i++)
        if(temp == penCapList[i])
            pcStyle = static_cast<Qt::PenCapStyle>(i);
    fin >> trash;
    fin >> temp;
    for(int i = 0; i < 3; i++)
        if(temp == penJoinList[i])
            pjStyle = static_cast<Qt::PenJoinStyle>(i);
    tempShape = new class Line(ra);
    dynamic_cast<class Line*>(tempShape)->set_points(newPoints);
    tempShape->set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
    newVector->push_back(tempShape);

    return newVector;
}
