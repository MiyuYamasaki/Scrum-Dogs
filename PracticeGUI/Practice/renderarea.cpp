#include "renderarea.h"

#include <QPainter>

#include "shapes.h"

#include <sstream>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    shape = POLYGON;
    antialiased = false;
    transformed = false;

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    numShapes = 0;
    ShapeParser sp;
    sList = sp.InitializeVector(this);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(1000, 500);
}

QSize RenderArea::sizeHint() const
{
    return QSize(1000, 500);
}

void RenderArea::setShape(Shape shape)
{
    this->shape = shape;
    update();
}

void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}

void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}

void RenderArea::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}

void RenderArea::addShape(int shapeTypeIndex, std::string shapeDim, int penColorIndex, std::string penWidth, int penStyleIndex, int penCapStyleIndex, int penJoinStyleIndex, int brushColorIndex, int brushStyleIndex, std::string textS, int textColorIndex, int alignmentIndex, std::string pointSize, std::string fontFamily, int fontStyleIndex, int fontWeightIndex)
{
    std::string trash;
    char trashChar;
    std::string temp;
    int shapeID = 0;
    gProject::shapes* tempShape = nullptr;
    Shape type = LINE;
    Qt::GlobalColor pColor = Qt::black;
    Qt::GlobalColor tColor = Qt::black;
    int pWidth = 0;
    Qt::PenStyle pStyle = Qt::DotLine;
    Qt::PenCapStyle pcStyle = Qt::FlatCap;
    Qt::PenJoinStyle pjStyle = Qt::MiterJoin;
    Qt::GlobalColor bColor = Qt::black;
    Qt::BrushStyle bStyle = Qt::NoBrush;
    std::vector<QPoint> points;
    vector<gProject::shapes>::iterator last;
    Qt::AlignmentFlag alignment;
    std::string textString;
    int textPointSize;
    std::string textFontFamily;
    QFont::Style textFontStyle;
    QFont::Weight textFontWeight;
    int width = 0, length = 0;
    bool opened = false;
    int x = 0;
    int y = 0;
    int pos1 = 0;

    std::stringstream ss(shapeDim);
    last = this->sList->end();
    last--;
    shapeID = (*last).get_ID() + 1;
    type = static_cast<Shape>(shapeTypeIndex);
    switch(type)
    {
    case LINE:
        points.clear();
        ss >> x;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> y;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        ss >> x;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> y;
        points.push_back(QPoint(x, y));
        pColor = static_cast<Qt::GlobalColor>(penColorIndex + 2);
        pWidth = stoi(penWidth);
        pStyle = static_cast<Qt::PenStyle>(penStyleIndex);
        if(penCapStyleIndex == 0)
            pcStyle = Qt::FlatCap;
        else if(penCapStyleIndex == 1)
            pcStyle = Qt::SquareCap;
        else if(penCapStyleIndex == 2)
            pcStyle = Qt::RoundCap;
        if(penJoinStyleIndex == 0)
            pjStyle = Qt::MiterJoin;
        else if(penJoinStyleIndex == 1)
            pjStyle = Qt::BevelJoin;
        else if(penJoinStyleIndex == 2)
            pjStyle = Qt::RoundJoin;
        tempShape = new Line(this);
        sList->push_back(*tempShape);
        last = sList->end();
        last--;
        (*last).set_ID((shapeID));
        (*last).set_points(points);
        (*last).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
        break;
    case POLYLINE:
        points.clear();
        do{
            ss >> x;
            ss.get();
            ss >> y;
            trashChar = ss.peek();
            if (trashChar == ',') trashChar = ss.get();
            points.push_back(QPoint(x, y));
        }while(trashChar == ',');
        pColor = static_cast<Qt::GlobalColor>(penColorIndex + 2);
        pWidth = stoi(penWidth);
        pStyle = static_cast<Qt::PenStyle>(penStyleIndex);
        if(penCapStyleIndex == 0)
            pcStyle = Qt::FlatCap;
        else if(penCapStyleIndex == 1)
            pcStyle = Qt::SquareCap;
        else if(penCapStyleIndex == 2)
            pcStyle = Qt::RoundCap;
        if(penJoinStyleIndex == 0)
            pjStyle = Qt::MiterJoin;
        else if(penJoinStyleIndex == 1)
            pjStyle = Qt::BevelJoin;
        else if(penJoinStyleIndex == 2)
            pjStyle = Qt::RoundJoin;
        tempShape = new Polyline(this);
        sList->push_back(*tempShape);
        last = sList->end();
        last--;
        (*last).set_ID((shapeID));
        (*last).set_points(points);
        (*last).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
        break;
    case POLYGON:
        points.clear();
        do{
            ss >> x;
            ss.get();
            ss >> y;
            trashChar = ss.peek();
            if (trashChar == ',') trashChar = ss.get();
            points.push_back(QPoint(x, y));
        }while(trashChar == ',');
        pColor = static_cast<Qt::GlobalColor>(penColorIndex + 2);
        pWidth = stoi(penWidth);
        pStyle = static_cast<Qt::PenStyle>(penStyleIndex);
        if(penCapStyleIndex == 0)
            pcStyle = Qt::FlatCap;
        else if(penCapStyleIndex == 1)
            pcStyle = Qt::SquareCap;
        else if(penCapStyleIndex == 2)
            pcStyle = Qt::RoundCap;
        if(penJoinStyleIndex == 0)
            pjStyle = Qt::MiterJoin;
        else if(penJoinStyleIndex == 1)
            pjStyle = Qt::BevelJoin;
        else if(penJoinStyleIndex == 2)
            pjStyle = Qt::RoundJoin;
        bColor = static_cast<Qt::GlobalColor>(brushColorIndex + 2);
        switch (brushStyleIndex)
        {
        case 0:
            bStyle = static_cast<Qt::BrushStyle>(1);
            break;
        case 1:
            bStyle = static_cast<Qt::BrushStyle>(9);
            break;
        case 2:
            bStyle = static_cast<Qt::BrushStyle>(10);
            break;
        case 3:
            bStyle = static_cast<Qt::BrushStyle>(0);
            break;
        }
        tempShape = new Polygon(this);
        sList->push_back(*tempShape);
        last = sList->end();
        last--;
        (*last).set_ID((shapeID));
        (*last).set_points(points);
        (*last).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
        (*last).set_brush(bColor, bStyle);
        break;
    case RECTANGLE:
        points.clear();
        ss >> x;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> y;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        ss >> length;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> width;
        pColor = static_cast<Qt::GlobalColor>(penColorIndex + 2);
        pWidth = stoi(penWidth);
        pStyle = static_cast<Qt::PenStyle>(penStyleIndex);
        if(penCapStyleIndex == 0)
            pcStyle = Qt::FlatCap;
        else if(penCapStyleIndex == 1)
            pcStyle = Qt::SquareCap;
        else if(penCapStyleIndex == 2)
            pcStyle = Qt::RoundCap;
        if(penJoinStyleIndex == 0)
            pjStyle = Qt::MiterJoin;
        else if(penJoinStyleIndex == 1)
            pjStyle = Qt::BevelJoin;
        else if(penJoinStyleIndex == 2)
            pjStyle = Qt::RoundJoin;
        bColor = static_cast<Qt::GlobalColor>(brushColorIndex + 2);
        switch (brushStyleIndex)
        {
        case 0:
            bStyle = static_cast<Qt::BrushStyle>(1);
            break;
        case 1:
            bStyle = static_cast<Qt::BrushStyle>(9);
            break;
        case 2:
            bStyle = static_cast<Qt::BrushStyle>(10);
            break;
        case 3:
            bStyle = static_cast<Qt::BrushStyle>(0);
            break;
        }
        tempShape = new Rect(this);
        sList->push_back(*tempShape);
        last = sList->end();
        last--;
        (*last).set_ID((shapeID));
        (*last).set_Rect(QRect(points[0],QSize(width, length)));
        (*last).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
        (*last).set_brush(bColor, bStyle);
        break;
    case SQUARE:
        points.clear();
        ss >> x;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> y;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        ss >> length;
        width = length;
        pColor = static_cast<Qt::GlobalColor>(penColorIndex + 2);
        pWidth = stoi(penWidth);
        pStyle = static_cast<Qt::PenStyle>(penStyleIndex);
        if(penCapStyleIndex == 0)
            pcStyle = Qt::FlatCap;
        else if(penCapStyleIndex == 1)
            pcStyle = Qt::SquareCap;
        else if(penCapStyleIndex == 2)
            pcStyle = Qt::RoundCap;
        if(penJoinStyleIndex == 0)
            pjStyle = Qt::MiterJoin;
        else if(penJoinStyleIndex == 1)
            pjStyle = Qt::BevelJoin;
        else if(penJoinStyleIndex == 2)
            pjStyle = Qt::RoundJoin;
        bColor = static_cast<Qt::GlobalColor>(brushColorIndex + 2);
        switch (brushStyleIndex)
        {
        case 0:
            bStyle = static_cast<Qt::BrushStyle>(1);
            break;
        case 1:
            bStyle = static_cast<Qt::BrushStyle>(9);
            break;
        case 2:
            bStyle = static_cast<Qt::BrushStyle>(10);
            break;
        case 3:
            bStyle = static_cast<Qt::BrushStyle>(0);
            break;
        }
        tempShape = new Square(this);
        sList->push_back(*tempShape);
        last = sList->end();
        last--;
        (*last).set_ID((shapeID));
        (*last).set_Rect(QRect(points[0],QSize(width, length)));
        (*last).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
        (*last).set_brush(bColor, bStyle);
        break;
    case ELLIPSE:
        points.clear();
        ss >> x;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> y;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        ss >> length;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> width;
        pColor = static_cast<Qt::GlobalColor>(penColorIndex + 2);
        pWidth = stoi(penWidth);
        pStyle = static_cast<Qt::PenStyle>(penStyleIndex);
        if(penCapStyleIndex == 0)
            pcStyle = Qt::FlatCap;
        else if(penCapStyleIndex == 1)
            pcStyle = Qt::SquareCap;
        else if(penCapStyleIndex == 2)
            pcStyle = Qt::RoundCap;
        if(penJoinStyleIndex == 0)
            pjStyle = Qt::MiterJoin;
        else if(penJoinStyleIndex == 1)
            pjStyle = Qt::BevelJoin;
        else if(penJoinStyleIndex == 2)
            pjStyle = Qt::RoundJoin;
        bColor = static_cast<Qt::GlobalColor>(brushColorIndex + 2);
        switch (brushStyleIndex)
        {
        case 0:
            bStyle = static_cast<Qt::BrushStyle>(1);
            break;
        case 1:
            bStyle = static_cast<Qt::BrushStyle>(9);
            break;
        case 2:
            bStyle = static_cast<Qt::BrushStyle>(10);
            break;
        case 3:
            bStyle = static_cast<Qt::BrushStyle>(0);
            break;
        }
        tempShape = new Ellipse(this);
        sList->push_back(*tempShape);
        last = sList->end();
        last--;
        (*last).set_ID((shapeID));
        (*last).set_Rect(QRect(points[0],QSize(width, length)));
        (*last).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
        (*last).set_brush(bColor, bStyle);
        break;
    case CIRCLE:
        points.clear();
        ss >> x;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> y;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        ss >> length;
        width = length;
        pColor = static_cast<Qt::GlobalColor>(penColorIndex + 2);
        pWidth = stoi(penWidth);
        pStyle = static_cast<Qt::PenStyle>(penStyleIndex);
        if(penCapStyleIndex == 0)
            pcStyle = Qt::FlatCap;
        else if(penCapStyleIndex == 1)
            pcStyle = Qt::SquareCap;
        else if(penCapStyleIndex == 2)
            pcStyle = Qt::RoundCap;
        if(penJoinStyleIndex == 0)
            pjStyle = Qt::MiterJoin;
        else if(penJoinStyleIndex == 1)
            pjStyle = Qt::BevelJoin;
        else if(penJoinStyleIndex == 2)
            pjStyle = Qt::RoundJoin;
        bColor = static_cast<Qt::GlobalColor>(brushColorIndex + 2);
        switch (brushStyleIndex)
        {
        case 0:
            bStyle = static_cast<Qt::BrushStyle>(1);
            break;
        case 1:
            bStyle = static_cast<Qt::BrushStyle>(9);
            break;
        case 2:
            bStyle = static_cast<Qt::BrushStyle>(10);
            break;
        case 3:
            bStyle = static_cast<Qt::BrushStyle>(0);
            break;
        }
        tempShape = new Circle(this);
        sList->push_back(*tempShape);
        last = sList->end();
        last--;
        (*last).set_ID((shapeID));
        (*last).set_Rect(QRect(points[0],QSize(width, length)));
        (*last).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
        (*last).set_brush(bColor, bStyle);
        break;
    case TEXT:
        points.clear();
        ss >> x;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> y;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        ss >> length;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> width;
        tColor = static_cast<Qt::GlobalColor>(textColorIndex + 2);
        textString = textS;
        if(alignmentIndex == 0)
            alignment = Qt::AlignLeft;
        else if(alignmentIndex == 1)
            alignment = Qt::AlignRight;
        else if(alignmentIndex == 2)
            alignment = Qt::AlignTop;
        else if(alignmentIndex == 3)
            alignment = Qt::AlignBottom;
        else if(alignmentIndex == 4)
            alignment = Qt::AlignCenter;
        textPointSize = stoi(pointSize);
        textFontFamily = fontFamily;
        textFontStyle = static_cast<QFont::Style>(fontStyleIndex);
        textFontWeight = static_cast<QFont::Weight>(fontWeightIndex);
        tempShape = new Text(this);
        sList->push_back(*tempShape);
        last = sList->end();
        last--;
        (*last).set_ID((shapeID));
        (*last).set_Rect(QRect(points[0],QSize(width, length)));
        (*last).set_Text(textString);
        (*last).set_TextColor(tColor);
        (*last).set_FontFamily(textFontFamily);
        (*last).set_Alignment(alignment);
        (*last).set_PointSize(textPointSize);
        (*last).set_FontStyle(textFontStyle);
        (*last).set_FontWeight(textFontWeight);
        break;
    }
    gProject::shapes::numShapes++;
    update();
}

void RenderArea::editShape(int shapeID, int shapeTypeIndex, std::string shapeDim, int penColorIndex, std::string penWidth, int penStyleIndex, int penCapStyleIndex, int penJoinStyleIndex, int brushColorIndex, int brushStyleIndex, std::string textS, int textColorIndex, int alignmentIndex, std::string pointSize, std::string fontFamily, int fontStyleIndex, int fontWeightIndex)
{
    std::string trash;
    char trashChar;
    std::string temp;
    gProject::shapes* tempShape = nullptr;
    Shape type = LINE;
    Qt::GlobalColor pColor = Qt::black;
    Qt::GlobalColor tColor = Qt::black;
    int pWidth = 0;
    Qt::PenStyle pStyle = Qt::DotLine;
    Qt::PenCapStyle pcStyle = Qt::FlatCap;
    Qt::PenJoinStyle pjStyle = Qt::MiterJoin;
    Qt::GlobalColor bColor = Qt::black;
    Qt::BrushStyle bStyle = Qt::NoBrush;
    std::vector<QPoint> points;
    vector<gProject::shapes>::iterator first = sList->begin();
    vector<gProject::shapes>::iterator last = sList->end();
    Qt::AlignmentFlag alignment;
    std::string textString;
    int textPointSize;
    std::string textFontFamily;
    QFont::Style textFontStyle;
    QFont::Weight textFontWeight;
    int width = 0, length = 0;
    bool opened = false;
    int x = 0;
    int y = 0;
    int pos1 = 0;
    int index = 0;

    std::stringstream ss(shapeDim);
    do{
        if((*first).get_ID() == shapeID)
            break;
        index++;
    }while(++first != last);
    type = static_cast<Shape>(shapeTypeIndex);
    switch(type)
    {
    case LINE:
        points.clear();
        ss >> x;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> y;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        ss >> x;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> y;
        points.push_back(QPoint(x, y));
        pColor = static_cast<Qt::GlobalColor>(penColorIndex + 2);
        pWidth = stoi(penWidth);
        pStyle = static_cast<Qt::PenStyle>(penStyleIndex);
        if(penCapStyleIndex == 0)
            pcStyle = Qt::FlatCap;
        else if(penCapStyleIndex == 1)
            pcStyle = Qt::SquareCap;
        else if(penCapStyleIndex == 2)
            pcStyle = Qt::RoundCap;
        if(penJoinStyleIndex == 0)
            pjStyle = Qt::MiterJoin;
        else if(penJoinStyleIndex == 1)
            pjStyle = Qt::BevelJoin;
        else if(penJoinStyleIndex == 2)
            pjStyle = Qt::RoundJoin;
        tempShape = new Line(this);
        do{
            if((*first).get_ID() == shapeID)
            {
                sList->pop_in(index, *tempShape);
                (*first).set_ID(shapeID);
                (*first).set_points(points);
                (*first).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
                (*first).set_Perimeter(0);
                (*first).set_Area(0);
            }
        }while(++first != last);
        break;
    case POLYLINE:
        points.clear();
        do{
            ss >> x;
            ss.get();
            ss >> y;
            trashChar = ss.peek();
            if (trashChar == ',') trashChar = ss.get();
            points.push_back(QPoint(x, y));
        }while(trashChar == ',');
        pColor = static_cast<Qt::GlobalColor>(penColorIndex + 2);
        pWidth = stoi(penWidth);
        pStyle = static_cast<Qt::PenStyle>(penStyleIndex);
        if(penCapStyleIndex == 0)
            pcStyle = Qt::FlatCap;
        else if(penCapStyleIndex == 1)
            pcStyle = Qt::SquareCap;
        else if(penCapStyleIndex == 2)
            pcStyle = Qt::RoundCap;
        if(penJoinStyleIndex == 0)
            pjStyle = Qt::MiterJoin;
        else if(penJoinStyleIndex == 1)
            pjStyle = Qt::BevelJoin;
        else if(penJoinStyleIndex == 2)
            pjStyle = Qt::RoundJoin;
        tempShape = new Polyline(this);
        do{
            if((*first).get_ID() == shapeID)
            {
                sList->pop_in(index, *tempShape);
                (*first).set_ID(shapeID);
                (*first).set_points(points);
                (*first).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
                (*first).set_Perimeter(0);
                (*first).set_Area(0);
            }
        }while(++first != last);
        break;
    case POLYGON:
        points.clear();
        do{
            ss >> x;
            ss.get();
            ss >> y;
            trashChar = ss.peek();
            if (trashChar == ',') trashChar = ss.get();
            points.push_back(QPoint(x, y));
        }while(trashChar == ',');
        pColor = static_cast<Qt::GlobalColor>(penColorIndex + 2);
        pWidth = stoi(penWidth);
        pStyle = static_cast<Qt::PenStyle>(penStyleIndex);
        if(penCapStyleIndex == 0)
            pcStyle = Qt::FlatCap;
        else if(penCapStyleIndex == 1)
            pcStyle = Qt::SquareCap;
        else if(penCapStyleIndex == 2)
            pcStyle = Qt::RoundCap;
        if(penJoinStyleIndex == 0)
            pjStyle = Qt::MiterJoin;
        else if(penJoinStyleIndex == 1)
            pjStyle = Qt::BevelJoin;
        else if(penJoinStyleIndex == 2)
            pjStyle = Qt::RoundJoin;
        bColor = static_cast<Qt::GlobalColor>(brushColorIndex + 2);
        switch (brushStyleIndex)
        {
        case 0:
            bStyle = static_cast<Qt::BrushStyle>(1);
            break;
        case 1:
            bStyle = static_cast<Qt::BrushStyle>(9);
            break;
        case 2:
            bStyle = static_cast<Qt::BrushStyle>(10);
            break;
        case 3:
            bStyle = static_cast<Qt::BrushStyle>(0);
            break;
        }
        tempShape = new Polygon(this);
        do{
            if((*first).get_ID() == shapeID)
            {
                sList->pop_in(index, *tempShape);
                (*first).set_ID(shapeID);
                (*first).set_points(points);
                (*first).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
                (*first).set_brush(bColor, bStyle);
                (*first).set_Perimeter(0);
                (*first).set_Area(0);
            }
        }while(++first != last);
        break;
    case RECTANGLE:
        points.clear();
        ss >> x;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> y;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        ss >> length;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> width;
        pColor = static_cast<Qt::GlobalColor>(penColorIndex + 2);
        pWidth = stoi(penWidth);
        pStyle = static_cast<Qt::PenStyle>(penStyleIndex);
        if(penCapStyleIndex == 0)
            pcStyle = Qt::FlatCap;
        else if(penCapStyleIndex == 1)
            pcStyle = Qt::SquareCap;
        else if(penCapStyleIndex == 2)
            pcStyle = Qt::RoundCap;
        if(penJoinStyleIndex == 0)
            pjStyle = Qt::MiterJoin;
        else if(penJoinStyleIndex == 1)
            pjStyle = Qt::BevelJoin;
        else if(penJoinStyleIndex == 2)
            pjStyle = Qt::RoundJoin;
        bColor = static_cast<Qt::GlobalColor>(brushColorIndex + 2);
        switch (brushStyleIndex)
        {
        case 0:
            bStyle = static_cast<Qt::BrushStyle>(1);
            break;
        case 1:
            bStyle = static_cast<Qt::BrushStyle>(9);
            break;
        case 2:
            bStyle = static_cast<Qt::BrushStyle>(10);
            break;
        case 3:
            bStyle = static_cast<Qt::BrushStyle>(0);
            break;
        }
        tempShape = new Rect(this);
        do{
            if((*first).get_ID() == shapeID)
            {
                sList->pop_in(index, *tempShape);
                (*first).set_ID(shapeID);
                (*first).set_Rect(QRect(points[0],QSize(width, length)));
                (*first).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
                (*first).set_brush(bColor, bStyle);
                (*first).set_Perimeter((width * 2) + (length * 2));
                (*first).set_Area(width * length);
            }
        }while(++first != last);
        break;
    case SQUARE:
        points.clear();
        ss >> x;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> y;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        ss >> length;
        width = length;
        pColor = static_cast<Qt::GlobalColor>(penColorIndex + 2);
        pWidth = stoi(penWidth);
        pStyle = static_cast<Qt::PenStyle>(penStyleIndex);
        if(penCapStyleIndex == 0)
            pcStyle = Qt::FlatCap;
        else if(penCapStyleIndex == 1)
            pcStyle = Qt::SquareCap;
        else if(penCapStyleIndex == 2)
            pcStyle = Qt::RoundCap;
        if(penJoinStyleIndex == 0)
            pjStyle = Qt::MiterJoin;
        else if(penJoinStyleIndex == 1)
            pjStyle = Qt::BevelJoin;
        else if(penJoinStyleIndex == 2)
            pjStyle = Qt::RoundJoin;
        bColor = static_cast<Qt::GlobalColor>(brushColorIndex + 2);
        switch (brushStyleIndex)
        {
        case 0:
            bStyle = static_cast<Qt::BrushStyle>(1);
            break;
        case 1:
            bStyle = static_cast<Qt::BrushStyle>(9);
            break;
        case 2:
            bStyle = static_cast<Qt::BrushStyle>(10);
            break;
        case 3:
            bStyle = static_cast<Qt::BrushStyle>(0);
            break;
        }
        tempShape = new Square(this);
        do{
            if((*first).get_ID() == shapeID)
            {
                sList->pop_in(index, *tempShape);
                (*first).set_ID(shapeID);
                (*first).set_Rect(QRect(points[0],QSize(width, length)));
                (*first).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
                (*first).set_brush(bColor, bStyle);
                (*first).set_Perimeter((width * 2) + (length * 2));
                (*first).set_Area(width * length);
            }
        }while(++first != last);
        break;
    case ELLIPSE:
        points.clear();
        ss >> x;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> y;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        ss >> length;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> width;
        pColor = static_cast<Qt::GlobalColor>(penColorIndex + 2);
        pWidth = stoi(penWidth);
        pStyle = static_cast<Qt::PenStyle>(penStyleIndex);
        if(penCapStyleIndex == 0)
            pcStyle = Qt::FlatCap;
        else if(penCapStyleIndex == 1)
            pcStyle = Qt::SquareCap;
        else if(penCapStyleIndex == 2)
            pcStyle = Qt::RoundCap;
        if(penJoinStyleIndex == 0)
            pjStyle = Qt::MiterJoin;
        else if(penJoinStyleIndex == 1)
            pjStyle = Qt::BevelJoin;
        else if(penJoinStyleIndex == 2)
            pjStyle = Qt::RoundJoin;
        bColor = static_cast<Qt::GlobalColor>(brushColorIndex + 2);
        switch (brushStyleIndex)
        {
        case 0:
            bStyle = static_cast<Qt::BrushStyle>(1);
            break;
        case 1:
            bStyle = static_cast<Qt::BrushStyle>(9);
            break;
        case 2:
            bStyle = static_cast<Qt::BrushStyle>(10);
            break;
        case 3:
            bStyle = static_cast<Qt::BrushStyle>(0);
            break;
        }
        tempShape = new Ellipse(this);
        do{
            if((*first).get_ID() == shapeID)
            {
                sList->pop_in(index, *tempShape);
                (*first).set_ID(shapeID);
                (*first).set_Rect(QRect(points[0],QSize(width, length)));
                (*first).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
                (*first).set_brush(bColor, bStyle);
                (*first).set_Perimeter(2 * 3.14 * (((width/2) + (length/2))/2));
                (*first).set_Area(3.14 * (width/2) * (length/2));
            }
        }while(++first != last);
        break;
    case CIRCLE:
        points.clear();
        ss >> x;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> y;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        ss >> length;
        width = length;
        pColor = static_cast<Qt::GlobalColor>(penColorIndex + 2);
        pWidth = stoi(penWidth);
        pStyle = static_cast<Qt::PenStyle>(penStyleIndex);
        if(penCapStyleIndex == 0)
            pcStyle = Qt::FlatCap;
        else if(penCapStyleIndex == 1)
            pcStyle = Qt::SquareCap;
        else if(penCapStyleIndex == 2)
            pcStyle = Qt::RoundCap;
        if(penJoinStyleIndex == 0)
            pjStyle = Qt::MiterJoin;
        else if(penJoinStyleIndex == 1)
            pjStyle = Qt::BevelJoin;
        else if(penJoinStyleIndex == 2)
            pjStyle = Qt::RoundJoin;
        bColor = static_cast<Qt::GlobalColor>(brushColorIndex + 2);
        switch (brushStyleIndex)
        {
        case 0:
            bStyle = static_cast<Qt::BrushStyle>(1);
            break;
        case 1:
            bStyle = static_cast<Qt::BrushStyle>(9);
            break;
        case 2:
            bStyle = static_cast<Qt::BrushStyle>(10);
            break;
        case 3:
            bStyle = static_cast<Qt::BrushStyle>(0);
            break;
        }
        tempShape = new Circle(this);
        do{
            if((*first).get_ID() == shapeID)
            {
                sList->pop_in(index, *tempShape);
                (*first).set_ID(shapeID);
                (*first).set_Rect(QRect(points[0],QSize(width, length)));
                (*first).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
                (*first).set_brush(bColor, bStyle);
                (*first).set_Perimeter(2 * 3.14 * (((width/2) + (length/2))/2));
                (*first).set_Area(3.14 * (width/2) * (length/2));
            }
        }while(++first != last);
        break;
    case TEXT:
        points.clear();
        ss >> x;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> y;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        ss >> length;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> width;
        tColor = static_cast<Qt::GlobalColor>(textColorIndex + 2);
        textString = textS;
        if(alignmentIndex == 0)
            alignment = Qt::AlignLeft;
        else if(alignmentIndex == 1)
            alignment = Qt::AlignRight;
        else if(alignmentIndex == 2)
            alignment = Qt::AlignTop;
        else if(alignmentIndex == 3)
            alignment = Qt::AlignBottom;
        else if(alignmentIndex == 4)
            alignment = Qt::AlignCenter;
        textPointSize = stoi(pointSize);
        textFontFamily = fontFamily;
        textFontStyle = static_cast<QFont::Style>(fontStyleIndex);
        textFontWeight = static_cast<QFont::Weight>(fontWeightIndex);
        tempShape = new Text(this);
        do{
            if((*first).get_ID() == shapeID)
            {
                sList->pop_in(index, *tempShape);
                (*first).set_ID(shapeID);
                (*first).set_Rect(QRect(points[0],QSize(width, length)));
                (*first).set_Text(textString);
                (*first).set_TextColor(tColor);
                (*first).set_FontFamily(textFontFamily);
                (*first).set_Alignment(alignment);
                (*first).set_PointSize(textPointSize);
                (*first).set_FontStyle(textFontStyle);
                (*first).set_FontWeight(textFontWeight);
            }
        }while(++first != last);
        break;
    }
    gProject::shapes::numShapes++;
    update();
}

void RenderArea::deleteShape(int i)
{
    //find shape
    vector<gProject::shapes>::iterator first = sList->begin();
    vector<gProject::shapes>::iterator last = sList->end();
    do{
        if((*first).get_ID() == i + 1)
        {
            sList->erase(first);
            break;
        }
    }while(++first != last);
    gProject::shapes::numShapes--;
    update();
}

gProject::shapes RenderArea::findShape(int i)
{
    vector<gProject::shapes>::iterator first = sList->begin();
    vector<gProject::shapes>::iterator last = sList->end();
    do{
        if((*first).get_ID() == i + 1)
        {
            return (*first);
        }
    }while(++first != last);
}

QList<QString> RenderArea::getIDNums()
{
    QList<QString> idNums;
    vector<gProject::shapes>::iterator first = sList->begin();
    vector<gProject::shapes>::iterator last = sList->end();
    do{
        idNums.append(QString::fromStdString(std::to_string((*first).get_ID())));
    }while(++first != last);
    return idNums;
}

void RenderArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    vector<gProject::shapes>::iterator first = sList->begin();
    vector<gProject::shapes>::iterator last = sList->end();
    std::vector<QPoint> points;

    painter.save();

    do{
        shape = first->getShape();
        painter.setRenderHint(QPainter::Antialiasing, false);
        //painter.setBrush(first->get_brush());
        points = (*first).get_points();
        int size = static_cast<int>(points.size());
        QPoint* arrPoints = new QPoint[size];

        switch(shape)
        {
            case LINE:
                this->setPen(first->get_pen());
                painter.setPen(first->get_pen());
                painter.drawLine(QLine(points[0], points[1]));
                break;
            case POLYLINE:
                this->setPen(first->get_pen());
                painter.setPen(first->get_pen());
                for (int i = 0; i < size; i++)
                    arrPoints[i] = points[i];
                painter.drawPolyline(arrPoints, size);
                break;
            case POLYGON:
                this->setPen(first->get_pen());
                painter.setPen(first->get_pen());
                painter.setBrush(first->get_brush());
                for (int i = 0; i < size; i++)
                    arrPoints[i] = points[i];
                painter.drawPolygon(arrPoints, size);
                break;
            case RECTANGLE:
                this->setPen(first->get_pen());
                painter.setPen(first->get_pen());
                painter.setBrush(first->get_brush());
                painter.drawRect((*first).get_Rect());
                break;
            case SQUARE:
                this->setPen(first->get_pen());
                painter.setPen(first->get_pen());
                painter.setBrush(first->get_brush());
                painter.drawRect((*first).get_Rect());
                break;
            case ELLIPSE:
                this->setPen(first->get_pen());
                painter.setPen(first->get_pen());
                painter.setBrush(first->get_brush());
                painter.drawEllipse((*first).get_Rect());
                break;
            case CIRCLE:
                this->setPen(first->get_pen());
                painter.setPen(first->get_pen());
                painter.setBrush(first->get_brush());
                painter.drawEllipse((*first).get_Rect());
                break;
            case TEXT:
                this->setPen(first->get_pen());
                painter.setPen(QPen(first->get_TextColor()));
                QFont font = painter.font();
                font.setFamily(QString::fromStdString(first->get_FontFamily()));
                font.setPixelSize(first->get_PointSize());
                painter.setFont(font);
                painter.drawText(points[0], QString::fromStdString(first->get_Text()));
                break;
        }
        ++first;
    }while(first != last);
    painter.restore();
}


void RenderArea::closeEvent(QCloseEvent *)
{
    std::ofstream fout;
    std::string temp;
    bool opened = false;
    fout.open("shapesOutput.txt");
    if (fout)
        opened = true;
    vector<gProject::shapes>::iterator first = sList->begin();
    vector<gProject::shapes>::iterator last = sList->end();
    std::vector<QPoint> tempPoints;


    do{
        fout << (*first).get_ID() << std::endl;
        for(int i = 0; i < 8; i++)
            if((*first).getShape() == i)
                fout << shapeList[i] << std::endl;
        tempPoints = (*first).get_points();
        std::vector<QPoint>::iterator firstP = tempPoints.begin();
        std::vector<QPoint>::iterator lastP = tempPoints.end();
        switch((*first).getShape())
        {
        case LINE:
        case POLYLINE:
            do{
                fout << (*firstP).x() << ", " << (*firstP).y();
                if(++firstP != lastP)
                    fout << ", ";
            }while(firstP != lastP);
            fout << std::endl;
            if((*first).get_pen().color() == Qt::black)
                fout << "black" << std::endl;
            else if((*first).get_pen().color() == Qt::white)
                fout << "white" << std::endl;
            else if((*first).get_pen().color() == Qt::darkGray)
                fout << "darkGray" << std::endl;
            else if((*first).get_pen().color() == Qt::gray)
                fout << "gray" << std::endl;
            else if((*first).get_pen().color() == Qt::lightGray)
                fout << "lightGray" << std::endl;
            else if((*first).get_pen().color() == Qt::red)
                fout << "red" << std::endl;
            else if((*first).get_pen().color() == Qt::green)
                fout << "green" << std::endl;
            else if((*first).get_pen().color() == Qt::blue)
                fout << "blue" << std::endl;
            else if((*first).get_pen().color() == Qt::cyan)
                fout << "cyan" << std::endl;
            else if((*first).get_pen().color() == Qt::magenta)
                fout << "magenta" << std::endl;
            else if((*first).get_pen().color() == Qt::yellow)
                fout << "yellow" << std::endl;
            fout << (*first).get_pen().width() << std::endl;
            for(int i = 0; i < 6; i++)
                if((*first).get_pen().style() == i)
                    fout << penStyleList[i];
            fout << std::endl;
            if((*first).get_pen().capStyle() == Qt::FlatCap)
                fout << "FlatCap" << std::endl;
            else if((*first).get_pen().capStyle() == Qt::SquareCap)
                fout << "SquareCap" << std::endl;
            else if((*first).get_pen().capStyle() == Qt::RoundCap)
                fout << "RoundCap" << std::endl;
            if((*first).get_pen().joinStyle() == Qt::MiterJoin)
                fout << "MiterJoin";
            else if((*first).get_pen().joinStyle() == Qt::BevelJoin)
                fout << "BevelJoin";
            else if((*first).get_pen().joinStyle() == Qt::RoundJoin)
                fout << "RoundJoin";
            break;
        case POLYGON:
            do{
                fout << (*firstP).x() << ", " << (*firstP).y();
                if(++firstP != lastP)
                    fout << ", ";
            }while(firstP != lastP);
            fout << std::endl;
            if((*first).get_pen().color() == Qt::black)
                fout << "black" << std::endl;
            else if((*first).get_pen().color() == Qt::white)
                fout << "white" << std::endl;
            else if((*first).get_pen().color() == Qt::darkGray)
                fout << "darkGray" << std::endl;
            else if((*first).get_pen().color() == Qt::gray)
                fout << "gray" << std::endl;
            else if((*first).get_pen().color() == Qt::lightGray)
                fout << "lightGray" << std::endl;
            else if((*first).get_pen().color() == Qt::red)
                fout << "red" << std::endl;
            else if((*first).get_pen().color() == Qt::green)
                fout << "green" << std::endl;
            else if((*first).get_pen().color() == Qt::blue)
                fout << "blue" << std::endl;
            else if((*first).get_pen().color() == Qt::cyan)
                fout << "cyan" << std::endl;
            else if((*first).get_pen().color() == Qt::magenta)
                fout << "magenta" << std::endl;
            else if((*first).get_pen().color() == Qt::yellow)
                fout << "yellow" << std::endl;
            fout << (*first).get_pen().width() << std::endl;
            for(int i = 0; i < 6; i++)
                if((*first).get_pen().style() == i)
                    fout << penStyleList[i];
            fout << std::endl;
            if((*first).get_pen().capStyle() == Qt::FlatCap)
                fout << "FlatCap" << std::endl;
            else if((*first).get_pen().capStyle() == Qt::SquareCap)
                fout << "SquareCap" << std::endl;
            else if((*first).get_pen().capStyle() == Qt::RoundCap)
                fout << "RoundCap" << std::endl;
            if((*first).get_pen().joinStyle() == Qt::MiterJoin)
                fout << "MiterJoin" << std::endl;
            else if((*first).get_pen().joinStyle() == Qt::BevelJoin)
                fout << "BevelJoin" << std::endl;
            else if((*first).get_pen().joinStyle() == Qt::RoundJoin)
                fout << "RoundJoin" << std::endl;
            if((*first).get_brush().color() == Qt::black)
                fout << "black" << std::endl;
            else if((*first).get_brush().color() == Qt::white)
                fout << "white" << std::endl;
            else if((*first).get_brush().color() == Qt::darkGray)
                fout << "darkGray" << std::endl;
            else if((*first).get_brush().color() == Qt::gray)
                fout << "gray" << std::endl;
            else if((*first).get_brush().color() == Qt::lightGray)
                fout << "lightGray" << std::endl;
            else if((*first).get_brush().color() == Qt::red)
                fout << "red" << std::endl;
            else if((*first).get_brush().color() == Qt::green)
                fout << "green" << std::endl;
            else if((*first).get_brush().color() == Qt::blue)
                fout << "blue" << std::endl;
            else if((*first).get_brush().color() == Qt::cyan)
                fout << "cyan" << std::endl;
            else if((*first).get_brush().color() == Qt::magenta)
                fout << "magenta" << std::endl;
            else if((*first).get_brush().color() == Qt::yellow)
                fout << "yellow" << std::endl;
            if((*first).get_brush().style() == Qt::SolidPattern)
                fout << "SolidPattern";
            else if((*first).get_brush().style() == Qt::HorPattern)
                fout << "HorPattern";
            else if((*first).get_brush().style() == Qt::VerPattern)
                fout << "VerPattern";
            else if((*first).get_brush().style() == Qt::NoBrush)
                fout << "NoBrush";
            break;
        case RECTANGLE:
        case SQUARE:
        case ELLIPSE:
        case CIRCLE:
            fout << (*first).get_Rect().x() << ", " << (*first).get_Rect().y() << ", " << (*first).get_Rect().height();
            if((*first).getShape() == RECTANGLE || (*first).getShape() == ELLIPSE)
                fout << ", " << (*first).get_Rect().width() << std::endl;
            else
                fout << std::endl;
            if((*first).get_pen().color() == Qt::black)
                fout << "black" << std::endl;
            else if((*first).get_pen().color() == Qt::white)
                fout << "white" << std::endl;
            else if((*first).get_pen().color() == Qt::darkGray)
                fout << "darkGray" << std::endl;
            else if((*first).get_pen().color() == Qt::gray)
                fout << "gray" << std::endl;
            else if((*first).get_pen().color() == Qt::lightGray)
                fout << "lightGray" << std::endl;
            else if((*first).get_pen().color() == Qt::red)
                fout << "red" << std::endl;
            else if((*first).get_pen().color() == Qt::green)
                fout << "green" << std::endl;
            else if((*first).get_pen().color() == Qt::blue)
                fout << "blue" << std::endl;
            else if((*first).get_pen().color() == Qt::cyan)
                fout << "cyan" << std::endl;
            else if((*first).get_pen().color() == Qt::magenta)
                fout << "magenta" << std::endl;
            else if((*first).get_pen().color() == Qt::yellow)
                fout << "yellow" << std::endl;
            fout << (*first).get_pen().width() << std::endl;
            for(int i = 0; i < 6; i++)
                if((*first).get_pen().style() == i)
                    fout << penStyleList[i];
            fout << std::endl;
            if((*first).get_pen().capStyle() == Qt::FlatCap)
                fout << "FlatCap" << std::endl;
            else if((*first).get_pen().capStyle() == Qt::SquareCap)
                fout << "SquareCap" << std::endl;
            else if((*first).get_pen().capStyle() == Qt::RoundCap)
                fout << "RoundCap" << std::endl;
            if((*first).get_pen().joinStyle() == Qt::MiterJoin)
                fout << "MiterJoin" << std::endl;
            else if((*first).get_pen().joinStyle() == Qt::BevelJoin)
                fout << "BevelJoin" << std::endl;
            else if((*first).get_pen().joinStyle() == Qt::RoundJoin)
                fout << "RoundJoin" << std::endl;
            if((*first).get_brush().color() == Qt::black)
                fout << "black" << std::endl;
            else if((*first).get_brush().color() == Qt::white)
                fout << "white" << std::endl;
            else if((*first).get_brush().color() == Qt::darkGray)
                fout << "darkGray" << std::endl;
            else if((*first).get_brush().color() == Qt::gray)
                fout << "gray" << std::endl;
            else if((*first).get_brush().color() == Qt::lightGray)
                fout << "lightGray" << std::endl;
            else if((*first).get_brush().color() == Qt::red)
                fout << "red" << std::endl;
            else if((*first).get_brush().color() == Qt::green)
                fout << "green" << std::endl;
            else if((*first).get_brush().color() == Qt::blue)
                fout << "blue" << std::endl;
            else if((*first).get_brush().color() == Qt::cyan)
                fout << "cyan" << std::endl;
            else if((*first).get_brush().color() == Qt::magenta)
                fout << "magenta" << std::endl;
            else if((*first).get_brush().color() == Qt::yellow)
                fout << "yellow" << std::endl;
            if((*first).get_brush().style() == Qt::SolidPattern)
                fout << "SolidPattern";
            else if((*first).get_brush().style() == Qt::HorPattern)
                fout << "HorPattern";
            else if((*first).get_brush().style() == Qt::VerPattern)
                fout << "VerPattern";
            else if((*first).get_brush().style() == Qt::NoBrush)
                fout << "NoBrush";
            break;
        case TEXT:
            fout << (*first).get_Rect().x() << ", " << (*first).get_Rect().y() << ", " << (*first).get_Rect().height() << ", " << (*first).get_Rect().width() << std::endl;
            fout << ((*first).get_Text()) << std::endl;
            if((*first).get_TextColor() == Qt::black)
                fout << "black" << std::endl;
            else if((*first).get_TextColor() == Qt::white)
                fout << "white" << std::endl;
            else if((*first).get_TextColor() == Qt::darkGray)
                fout << "darkGray" << std::endl;
            else if((*first).get_TextColor() == Qt::gray)
                fout << "gray" << std::endl;
            else if((*first).get_TextColor() == Qt::lightGray)
                fout << "lightGray" << std::endl;
            else if((*first).get_TextColor() == Qt::red)
                fout << "red" << std::endl;
            else if((*first).get_TextColor() == Qt::green)
                fout << "green" << std::endl;
            else if((*first).get_TextColor() == Qt::blue)
                fout << "blue" << std::endl;
            else if((*first).get_TextColor() == Qt::cyan)
                fout << "cyan" << std::endl;
            else if((*first).get_TextColor() == Qt::magenta)
                fout << "magenta" << std::endl;
            else if((*first).get_TextColor() == Qt::yellow)
                fout << "yellow" << std::endl;
            if((*first).get_Alignment() == Qt::AlignLeft)
                fout << "AlignLeft" << std::endl;
            else if((*first).get_Alignment() == Qt::AlignRight)
                fout << "AlignRight" << std::endl;
            else if((*first).get_Alignment() == Qt::AlignTop)
                fout << "AlignTop" << std::endl;
            else if((*first).get_Alignment() == Qt::AlignBottom)
                fout << "AlignBottom" << std::endl;
            else if((*first).get_Alignment() == Qt::AlignCenter)
                fout << "AlignCenter" << std::endl;
            fout << (*first).get_PointSize() << std::endl;
            fout << (*first).get_FontFamily() << std::endl;
            if((*first).get_FontStyle() == QFont::StyleNormal)
                fout << "StyleNormal" << std::endl;
            else if((*first).get_FontStyle() == QFont::StyleItalic)
                fout << "StyleItalic" << std::endl;
            else if((*first).get_FontStyle() == QFont::StyleOblique)
                fout << "StyleOblique" << std::endl;
            if((*first).get_FontWeight() == QFont::Thin)
                fout << "Thin";
            else if((*first).get_FontWeight() == QFont::Light)
                fout << "Light";
            else if((*first).get_FontWeight() == QFont::Normal)
                fout << "Normal";
            else if((*first).get_FontWeight() == QFont::Bold)
                fout << "Bold";
            break;
        }
        if(++first != last)
            fout << std::endl;
    }while(first != last);
}

vector<gProject::shapes>* RenderArea::getSList()
{
    return sList;
}
