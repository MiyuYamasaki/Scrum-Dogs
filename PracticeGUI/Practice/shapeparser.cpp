#include "shapeparser.h"

//! Constructor */
ShapeParser::ShapeParser()
//!< default constructor for ShapeParser */
{
}
//! Mutator function */
vector<gProject::shapes>* ShapeParser::InitializeVector(RenderArea* ra)
//! Initialiazes vector */
{
    newVector = new vector<gProject::shapes>;

//    QStringList filenames = QFileDialog::getOpenFileNames(nullptr, ("shape.txt"), "C://", "All files (*.*)");

//    std::string current_locale_text = filenames[0].toLocal8Bit().constData();

//    std::ifstream fin(current_locale_text.c_str());

    std::ifstream fin("shape.txt");
    std::ofstream fout;
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
//    QPoint* oldPoints = nullptr;
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

    fout.open("shapesOutput.txt");
    if(fin)
        opened = true;
    while(fin)
    {
        if(fin.eof()) break;
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
            (*last).set_Perimeter(0);
            (*last).set_Area(0);
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
            (*last).set_Perimeter(0);
            (*last).set_Area(0);
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
                    bColor = static_cast<Qt::GlobalColor>(i + 2);
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
            (*last).set_Perimeter(0);
            (*last).set_Area(0);
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
                    bColor = static_cast<Qt::GlobalColor>(i + 2);
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
            (*last).set_Perimeter((width * 2) + (length * 2));
            (*last).set_Area(width * length);
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
                    bColor = static_cast<Qt::GlobalColor>(i + 2);
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
            (*last).set_Perimeter((width * 2) + (length * 2));
            (*last).set_Area(width * length);
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
                    bColor = static_cast<Qt::GlobalColor>(i + 2);
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
            (*last).set_Perimeter(2 * 3.14 * (((width/2) + (length/2))/2));
            (*last).set_Area(3.14 * (width/2) * (length/2));
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
                    bColor = static_cast<Qt::GlobalColor>(i + 2);
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
            (*last).set_Perimeter(2 * 3.14 * (width/2));
            (*last).set_Area(3.14 * (width/2) * (length/2));
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
            (*last).set_points(points);
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
    }

    fin.close();
    fout.close();

    return newVector;
}
