#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include "vector.h"
namespace n{

class shape
{
public:
    shape();
    std::string getPenCapStyle();
    std::string getPenColor();
    int getPenWidth();
    std::string getPenStyle();
    std::string getPenJointStyle();
    std::string getBrushColor();
    std::string getBrushStyle();
    int getShapeId();
    vector<int>* getShapeDimensions();

    void setPenCapStyle(std::string style);
    void setPenColor(std::string color);
    void setPenWidth(int width);
    void setPenStyle(std::string style);
    void setPenJointStyle(std::string style);
    void setBrushColor(std::string color);
    void setBrushStyle(std::string style);
    void setShapeId(int iD);
    void setShapeDimensions(vector<int> *dim);

    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;

    ~shape()
    {
        delete shapeDimensions;
    }

private:
    std::string penColor;
    int penWidth;
    std::string penStyle;
    std::string penCapStyle;
    std::string penJointStyle;
    std::string brushColor;
    std::string brushStyle;
    int shapeId;
    std::string shapeType;
    vector<int> *shapeDimensions;

};
}

#endif // SHAPE_H
