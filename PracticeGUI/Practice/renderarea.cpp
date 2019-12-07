#include "renderarea.h"

#include <QPainter>

#include "shapes.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    shape = POLYGON;
    antialiased = false;
    transformed = false;

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
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

void RenderArea::addShape()
{
    //get all parameters
    /*
    fin >> shapeID;
    fin.ignore(10, '\n');
    getline(fin, temp);
    for(int i = 0; i < 8; i++)
        if(temp.compare(shapeList[i]) == 0)
        {
            type = static_cast<Shape>(i);
            break;
        }
    switch(type)
    {
    case LINE:
        points.clear();
        fin >> x;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        fin >> y;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        fin >> x;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        fin >> y;
        points.push_back(QPoint(x, y));
        fin.clear();
        getline(fin, trash);
        fin.clear();
        getline(fin, temp);
        for(int i = 0; i < 11; i++)
            if(temp.compare(colorList[i]) == 0)
            {
                pColor = static_cast<Qt::GlobalColor>(i + 2);
                break;
            }
        fin >> pWidth;
        fin.clear();
        getline(fin, trash);
        getline(fin, temp);
        for(int i = 0; i < 6; i++)
            if(temp.compare(penStyleList[i]) == 0)
            {
                pStyle = static_cast<Qt::PenStyle>(i);
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 3; i++)
            if(temp.compare(penCapList[i]) == 0)
            {
                if(i == 0)
                    pcStyle = Qt::FlatCap;
                else if(i == 1)
                    pcStyle = Qt::SquareCap;
                else if(i == 2)
                    pcStyle = Qt::RoundCap;
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 3; i++)
            if(temp.compare(penJoinList[i]) == 0)
            {
                if(i == 0)
                    pjStyle = Qt::MiterJoin;
                else if(i == 1)
                    pjStyle = Qt::BevelJoin;
                else if(i == 2)
                    pjStyle = Qt::RoundJoin;
                break;
            }
        tempShape = new Line(ra);
        newVector->push_back(*tempShape);
        last = newVector->end();
        last--;
        (*last).set_ID((shapeID));
        (*last).set_points(points);
        (*last).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
        break;
    case POLYLINE:
        points.clear();
        do{
            fin >> x;
            fin.get();
            fin >> y;
            trashChar = fin.peek();
            if (trashChar == ',') trashChar = fin.get();
            points.push_back(QPoint(x, y));
        }while(trashChar == ',');

        fin.clear();
        getline(fin, trash);
        fin.clear();
        getline(fin, temp);
        for(int i = 0; i < 11; i++)
            if(temp.compare(colorList[i]) == 0)
            {
                pColor = static_cast<Qt::GlobalColor>(i + 2);
                break;
            }
        fin >> pWidth;
        fin.clear();
        getline(fin, trash);
        getline(fin, temp);
        for(int i = 0; i < 6; i++)
            if(temp.compare(penStyleList[i]) == 0)
            {
                pStyle = static_cast<Qt::PenStyle>(i);
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 3; i++)
            if(temp.compare(penCapList[i]) == 0)
            {
                if(i == 0)
                    pcStyle = Qt::FlatCap;
                else if(i == 1)
                    pcStyle = Qt::SquareCap;
                else if(i == 2)
                    pcStyle = Qt::RoundCap;
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 3; i++)
            if(temp.compare(penJoinList[i]) == 0)
            {
                if(i == 0)
                    pjStyle = Qt::MiterJoin;
                else if(i == 1)
                    pjStyle = Qt::BevelJoin;
                else if(i == 2)
                    pjStyle = Qt::RoundJoin;
                break;
            }
        tempShape = new Polyline(ra);
        newVector->push_back(*tempShape);
        last = newVector->end();
        last--;
        (*last).set_ID((shapeID));
        (*last).set_points(points);
        (*last).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
        break;
    case POLYGON:
        points.clear();
        do{
            fin >> x;
            fin.get();
            fin >> y;
            trashChar = fin.peek();
            if (trashChar == ',') trashChar = fin.get();
            points.push_back(QPoint(x, y));
        }while(trashChar == ',');

        fin.clear();
        getline(fin, trash);
        fin.clear();
        getline(fin, temp);
        for(int i = 0; i < 11; i++)
            if(temp.compare(colorList[i]) == 0)
            {
                pColor = static_cast<Qt::GlobalColor>(i + 2);
                break;
            }
        fin >> pWidth;
        fin.clear();
        getline(fin, trash);
        getline(fin, temp);
        for(int i = 0; i < 6; i++)
            if(temp.compare(penStyleList[i]) == 0)
            {
                pStyle = static_cast<Qt::PenStyle>(i);
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 3; i++)
            if(temp.compare(penCapList[i]) == 0)
            {
                if(i == 0)
                    pcStyle = Qt::FlatCap;
                else if(i == 1)
                    pcStyle = Qt::SquareCap;
                else if(i == 2)
                    pcStyle = Qt::RoundCap;
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 3; i++)
            if(temp.compare(penJoinList[i]) == 0)
            {
                if(i == 0)
                    pjStyle = Qt::MiterJoin;
                else if(i == 1)
                    pjStyle = Qt::BevelJoin;
                else if(i == 2)
                    pjStyle = Qt::RoundJoin;
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 11; i++)
            if(temp.compare(colorList[i]) == 0)
            {
                bColor = static_cast<Qt::GlobalColor>(i);
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 4; i++)
            if(temp.compare(brushStyleList[i]) == 0)
            {
                switch (i)
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
                break;
            }
        tempShape = new Polygon(ra);
        newVector->push_back(*tempShape);
        last = newVector->end();
        last--;
        (*last).set_ID((shapeID));
        (*last).set_points(points);
        (*last).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
        (*last).set_brush(bColor, bStyle);
        break;
    case RECTANGLE:
        points.clear();
        fin >> x;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        fin >> y;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        fin >> length;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        fin >> width;
        fin.clear();
        getline(fin, trash);
        fin.clear();
        getline(fin, temp);
        for(int i = 0; i < 11; i++)
            if(temp.compare(colorList[i]) == 0)
            {
                pColor = static_cast<Qt::GlobalColor>(i + 2);
                break;
            }
        fin >> pWidth;
        fin.clear();
        getline(fin, trash);
        getline(fin, temp);
        for(int i = 0; i < 6; i++)
            if(temp.compare(penStyleList[i]) == 0)
            {
                pStyle = static_cast<Qt::PenStyle>(i);
                break;
            }
                getline(fin, temp);
        for(int i = 0; i < 3; i++)
            if(temp.compare(penCapList[i]) == 0)
            {
                if(i == 0)
                    pcStyle = Qt::FlatCap;
                else if(i == 1)
                    pcStyle = Qt::SquareCap;
                else if(i == 2)
                    pcStyle = Qt::RoundCap;
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 3; i++)
            if(temp.compare(penJoinList[i]) == 0)
            {
                if(i == 0)
                    pjStyle = Qt::MiterJoin;
                else if(i == 1)
                    pjStyle = Qt::BevelJoin;
                else if(i == 2)
                    pjStyle = Qt::RoundJoin;
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 11; i++)
            if(temp.compare(colorList[i]) == 0)
            {
                bColor = static_cast<Qt::GlobalColor>(i);
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 4; i++)
            if(temp.compare(brushStyleList[i]) == 0)
            {
                switch (i)
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
            }
        tempShape = new Rect(ra);
        newVector->push_back(*tempShape);
        last = newVector->end();
        last--;
        (*last).set_ID((shapeID));
        (*last).set_Rect(QRect(points[0],QSize(width, length)));
        (*last).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
        (*last).set_brush(bColor, bStyle);
        break;
    case SQUARE:
        points.clear();
        fin >> x;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        fin >> y;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        fin >> length;
        width = length;
        fin.clear();
        getline(fin, trash);
        fin.clear();
        getline(fin, temp);
        for(int i = 0; i < 11; i++)
            if(temp.compare(colorList[i]) == 0)
            {
                pColor = static_cast<Qt::GlobalColor>(i + 2);
                break;
            }
        fin >> pWidth;
        fin.clear();
        getline(fin, trash);
        getline(fin, temp);
        for(int i = 0; i < 6; i++)
            if(temp.compare(penStyleList[i]) == 0)
            {
                pStyle = static_cast<Qt::PenStyle>(i);
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 3; i++)
            if(temp.compare(penCapList[i]) == 0)
            {
                if(i == 0)
                    pcStyle = Qt::FlatCap;
                else if(i == 1)
                    pcStyle = Qt::SquareCap;
                else if(i == 2)
                    pcStyle = Qt::RoundCap;
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 3; i++)
            if(temp.compare(penJoinList[i]) == 0)
            {
                if(i == 0)
                    pjStyle = Qt::MiterJoin;
                else if(i == 1)
                    pjStyle = Qt::BevelJoin;
                else if(i == 2)
                    pjStyle = Qt::RoundJoin;
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 11; i++)
            if(temp.compare(colorList[i]) == 0)
            {
                bColor = static_cast<Qt::GlobalColor>(i);
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 4; i++)
            if(temp.compare(brushStyleList[i]) == 0)
            {
                switch (i)
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
            }
        tempShape = new Square(ra);
        newVector->push_back(*tempShape);
        last = newVector->end();
        last--;
        (*last).set_ID((shapeID));
        (*last).set_Rect(QRect(points[0],QSize(width, length)));
        (*last).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
        (*last).set_brush(bColor, bStyle);
        break;
    case ELLIPSE:
        points.clear();
        fin >> x;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        fin >> y;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        fin >> length;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        fin >> width;
        fin.clear();
        getline(fin, trash);
        fin.clear();
        getline(fin, temp);
        for(int i = 0; i < 11; i++)
            if(temp.compare(colorList[i]) == 0)
            {
                pColor = static_cast<Qt::GlobalColor>(i + 2);
                break;
            }
        fin >> pWidth;
        fin.clear();
        getline(fin, trash);
        getline(fin, temp);
        for(int i = 0; i < 6; i++)
            if(temp.compare(penStyleList[i]) == 0)
            {
                pStyle = static_cast<Qt::PenStyle>(i);
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 3; i++)
            if(temp.compare(penCapList[i]) == 0)
            {
                if(i == 0)
                    pcStyle = Qt::FlatCap;
                else if(i == 1)
                    pcStyle = Qt::SquareCap;
                else if(i == 2)
                    pcStyle = Qt::RoundCap;
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 3; i++)
            if(temp.compare(penJoinList[i]) == 0)
            {
                if(i == 0)
                    pjStyle = Qt::MiterJoin;
                else if(i == 1)
                    pjStyle = Qt::BevelJoin;
                else if(i == 2)
                    pjStyle = Qt::RoundJoin;
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 11; i++)
            if(temp.compare(colorList[i]) == 0)
            {
                bColor = static_cast<Qt::GlobalColor>(i);
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 4; i++)
            if(temp.compare(brushStyleList[i]) == 0)
            {
                switch (i)
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
            }
        tempShape = new Ellipse(ra);
        newVector->push_back(*tempShape);
        last = newVector->end();
        last--;
        (*last).set_ID((shapeID));
        (*last).set_Rect(QRect(points[0],QSize(width, length)));
        (*last).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
        (*last).set_brush(bColor, bStyle);
        break;
    case CIRCLE:
        points.clear();
        fin >> x;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        fin >> y;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        fin >> length;
        width = length;
        fin.clear();
        getline(fin, trash);
        fin.clear();
        getline(fin, temp);
        for(int i = 0; i < 11; i++)
            if(temp.compare(colorList[i]) == 0)
            {
                pColor = static_cast<Qt::GlobalColor>(i + 2);
                break;
            }
        fin >> pWidth;
        fin.clear();
        getline(fin, trash);
        getline(fin, temp);
        for(int i = 0; i < 6; i++)
            if(temp.compare(penStyleList[i]) == 0)
            {
                pStyle = static_cast<Qt::PenStyle>(i);
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 3; i++)
            if(temp.compare(penCapList[i]) == 0)
            {
                if(i == 0)
                    pcStyle = Qt::FlatCap;
                else if(i == 1)
                    pcStyle = Qt::SquareCap;
                else if(i == 2)
                    pcStyle = Qt::RoundCap;
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 3; i++)
            if(temp.compare(penJoinList[i]) == 0)
            {
                if(i == 0)
                    pjStyle = Qt::MiterJoin;
                else if(i == 1)
                    pjStyle = Qt::BevelJoin;
                else if(i == 2)
                    pjStyle = Qt::RoundJoin;
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 11; i++)
            if(temp.compare(colorList[i]) == 0)
            {
                bColor = static_cast<Qt::GlobalColor>(i);
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 4; i++)
            if(temp.compare(brushStyleList[i]) == 0)
            {
                switch (i)
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
            }
        tempShape = new Circle(ra);
        newVector->push_back(*tempShape);
        last = newVector->end();
        last--;
        (*last).set_ID((shapeID));
        (*last).set_Rect(QRect(points[0],QSize(width, length)));
        (*last).set_pen(pColor, pWidth, pStyle, pcStyle, pjStyle);
        (*last).set_brush(bColor, bStyle);
        break;
    case TEXT:
        points.clear();
        fin >> x;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        fin >> y;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        points.push_back(QPoint(x, y));
        fin >> length;
        fin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        fin >> width;
        fin.clear();
        getline(fin, trash);
        fin.clear();
        getline(fin, temp);
        textString = temp;
        getline(fin, temp);
        for(int i = 0; i < 11; i++)
            if(temp.compare(colorList[i]) == 0)
            {
                tColor = static_cast<Qt::GlobalColor>(i + 2);
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 5; i++)
            if(temp.compare(textAlignmentList[i]) == 0)
            {
                if(i == 0)
                    alignment = Qt::AlignLeft;
                else if(i == 1)
                    alignment = Qt::AlignRight;
                else if(i == 2)
                    alignment = Qt::AlignTop;
                else if(i == 3)
                    alignment = Qt::AlignBottom;
                else if(i == 4)
                    alignment = Qt::AlignCenter;
                break;
            }
        fin >> textPointSize;
        getline(fin, trash);
        getline(fin, temp);
        textFontFamily = temp;
        getline(fin, temp);
        for(int i = 0; i < 3; i++)
            if(temp.compare(textFontStyleList[i]) == 0)
            {
                textFontStyle = static_cast<QFont::Style>(i);
                break;
            }
        getline(fin, temp);
        for(int i = 0; i < 4; i++)
            if(temp.compare(textFontWeightList[i]) == 0)
            {
                if(i == 0)
                    textFontWeight = QFont::Thin;
                else if(i == 1)
                    textFontWeight = QFont::Light;
                else if(i == 2)
                    textFontWeight = QFont::Normal;
                else if(i == 3)
                    textFontWeight = QFont::Bold;
                break;
            }
        tempShape = new Text(ra);
        newVector->push_back(*tempShape);
        last = newVector->end();
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
    */
}

void RenderArea::deleteShape(gProject::shapes s)
{
    //find shape
    vector<gProject::shapes>::iterator first = sList->begin();
    vector<gProject::shapes>::iterator last = sList->end();
    do{
        if((*first).get_ID() == s.get_ID())
            sList->erase(first);
    }while(++first != last);
}

void RenderArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    vector<gProject::shapes>::iterator first = sList->begin();
    vector<gProject::shapes>::iterator last = sList->end();
    std::vector<QPoint> points;

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
                painter.drawText(first->get_Rect(), first->get_Alignment(), QString::fromStdString(first->get_Text()));
                break;
        }
    }while(++first != last);
    //painter.restore();
}


void RenderArea::closeEvent(QCloseEvent *)
{
    /*
    std::ofstream fout;
    fout.open("shapesOutput.txt");
    vector<gProject::shapes>::iterator first = sList->begin();
    vector<gProject::shapes>::iterator last = sList->end();

    while(first != last)
    {
        fout << "ShapeId: " << (*first).get_ID() << std::endl;
        fout << "ShapeType: ";
        for(int i = 0; i < 6; i++)
            if((*first).getShape() == i)
                fout << shapeList[i] << std::endl;
        fout << "ShapeDimensions: " << std::endl;
        switch((*first).getShape())
        {
            case polygon:
            case rectangle:
            case ellipse:
                fout << "BrushColor: " << colorList[(*first).get_brush().color()] << std::endl;
                fout << "BrushStyle: " << brushStyleList[(*first).get_brush().style()] << std::endl;
            case line:
            case polyline:
                fout << "PenColor: " << colorList[(*first).get_pen().color()] << std::endl;
                fout << "PenWidth: " << (*first).get_pen().width();
                fout << "PenStyle: " << penStyleList[(*first).get_pen().style()] << std::endl;
                fout << "PenCapStyle: " << penCapList[(*first).get_pen().capStyle()] << std::endl;
                fout << "PenJoinStyle: " << penJoinList[(*first).get_pen().joinStyle()] << std::endl;
                break;
            case text:
                //fout << "TextString: " << dynamic_cast<class Text*>(first)->get_Text() << std::endl;
                //fout << "TextColor: " << colorList[(*first).get_pen().color()] << std::endl;
                //fout << "TextAlignment: " << alignmentList[dynamic_cast<class Text*>(first)->get_Alignment()] << std::endl;
                //fout << "TextPointSize: "
                break;
        }
    }

    fout.close();
    */
}
