#include <fstream>

void shapeParser
{
	vector<Shape>** shapeList = new vector<Shape>;
	Shape* temp = nullptr;
	istream fin;
	ostream fout;
	string trash;
	int shapeID;
	enum shapeType {Line, Polyline, Polygon, Rectangle, Square, Ellipse, Circle, Text};
	vector<double>* shapeDimensions = nullptr;
	enum penColor {white, black, red, green, blue, cyan, magenta, yellow, gray};
	int penWidth;
	enum penStyle {NoPen, SolidLine, DashLine, DotLine, DashDotLine, DashDotDotLine};
	enum penCapStyle {FlatCap, SquareCap, RoundCap};
	enum penJoinStyle {MiterJoin, BevelJoin, RoundJoin};
	enum brushColor {white, black, red, green, blue, cyan, magenta, yellow, gray};
	enum brushStyle {SolidPattern, HorPattern, VerPattern, NoBrush};
	string textString;
	enum textColor {white, black, red, green, blue, cyan, magenta, yellow, gray};
	enum textAlignment {AlignLeft, AlignRight, AlignTop, AlignBottom, AlignCenter};
	int textPointSize;
	string textFontFamily;
	enum textFontStyle {StyleNormal, StyleItalic, StyleOblique};
	enum textFontWeight {Thin, Light, Normal, Bold};
	
	fin.open(shapes.txt);
	while(!fin.eof) {
		fin >> trash;
		fin >> shapeID;
		fin >> trash;
		fin.clear();
		getline(fin, shapeType);
		fin >> trash;
		fin.clear();
		shapeDimensions = new vector<double>;
		while(//Not End of Line)
			fin >> shapeDimensions; //calls push_back
		switch(shapeType)
		{
			case Line:
				fin >> trash;
				fin.clear();
				getline(fin, penColor);
				fin >> trash;
				fin.clear();
				fin >> penWidth;
				fin >> trash;
				fin.clear();
				getline(fin, penStyle);
				fin >> trash;
				fin.clear();
				getline(fin, penCapStyle);
				fin >> trash;
				fin.clear();
				getline(fin, penJoinStyle);
				break;
			case Polyline:
				fin >> trash;
				fin.clear();
				getline(fin, penColor);
				fin >> trash;
				fin.clear();
				fin >> penWidth;
				fin >> trash;
				fin.clear();
				getline(fin, penStyle);
				fin >> trash;
				fin.clear();
				getline(fin, penCapStyle);
				fin >> trash;
				fin.clear();
				getline(fin, penJoinStyle);
				break;
			case Polygon:
				fin >> trash;
				fin.clear();
				getline(fin, penColor);
				fin >> trash;
				fin.clear();
				fin >> penWidth;
				fin >> trash;
				fin.clear();
				getline(fin, penStyle);
				fin >> trash;
				fin.clear();
				getline(fin, penCapStyle);
				fin >> trash;
				fin.clear();
				getline(fin, penJoinStyle);
				fin >> trash;
				fin.clear();
				getline(fin, brushColor);
				fin >> trash;
				fin.clear();
				getline(fin, brushStyle);
				break;
			case Rectangle:
				fin >> trash;
				fin.clear();
				getline(fin, penColor);
				fin >> trash;
				fin.clear();
				fin >> penWidth;
				fin >> trash;
				fin.clear();
				getline(fin, penStyle);
				fin >> trash;
				fin.clear();
				getline(fin, penCapStyle);
				fin >> trash;
				fin.clear();
				getline(fin, penJoinStyle);
				fin >> trash;
				fin.clear();
				getline(fin, brushColor);
				fin >> trash;
				fin.clear();
				getline(fin, brushStyle);
				break;
			case Square:
				fin >> trash;
				fin.clear();
				getline(fin, penColor);
				fin >> trash;
				fin.clear();
				fin >> penWidth;
				fin >> trash;
				fin.clear();
				getline(fin, penStyle);
				fin >> trash;
				fin.clear();
				getline(fin, penCapStyle);
				fin >> trash;
				fin.clear();
				getline(fin, penJoinStyle);
				fin >> trash;
				fin.clear();
				getline(fin, brushColor);
				fin >> trash;
				fin.clear();
				getline(fin, brushStyle);
				break;
			case Ellipse:
				fin >> trash;
				fin.clear();
				getline(fin, penColor);
				fin >> trash;
				fin.clear();
				fin >> penWidth;
				fin >> trash;
				fin.clear();
				getline(fin, penStyle);
				fin >> trash;
				fin.clear();
				getline(fin, penCapStyle);
				fin >> trash;
				fin.clear();
				getline(fin, penJoinStyle);
				fin >> trash;
				fin.clear();
				getline(fin, brushColor);
				fin >> trash;
				fin.clear();
				getline(fin, brushStyle);
				break;
			case Circle:
				fin >> trash;
				fin.clear();
				getline(fin, penColor);
				fin >> trash;
				fin.clear();
				fin >> penWidth;
				fin >> trash;
				fin.clear();
				getline(fin, penStyle);
				fin >> trash;
				fin.clear();
				getline(fin, penCapStyle);
				fin >> trash;
				fin.clear();
				getline(fin, penJoinStyle);
				fin >> trash;
				fin.clear();
				getline(fin, brushColor);
				fin >> trash;
				fin.clear();
				getline(fin, brushStyle);
				break;
			case Text:
				fin >> trash
				fin.clear();
				getline(fin, textString);
				fin >> trash
				fin.clear();
				getline(fin, textColor);
				fin >> trash
				fin.clear();
				getline(fin, textAlignment);
				fin >> trash
				fin.clear();
				fin >> textPointSize;
				fin >> trash
				fin.clear();
				getline(fin, textFontFamily);
				fin >> trash
				fin.clear();
				getline(fin, textFontStyle);
				fin >> trash
				fin.clear();
				getline(fin, textFontWeight);
				break;
			default:
				cout << "Invalid shape read." << endl;
				break;
		}
	}
	fin.close();
}