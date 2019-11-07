#include "shape.h"

namespace n{

    shape::shape()
    {
        penColor = "blank";
        penWidth = 0;
        penStyle = "blank";
        penCapStyle = "blank";
        penJointStyle = "blank";
        brushColor = "blank";
        brushStyle = "blank";
        shapeId = 0;
        shapeType = "blank";
        shapeDimensions = nullptr;
    }

    std::string shape::getPenCapStyle()
    {
        return penCapStyle;
    }
    std::string shape::getPenColor()
    {
        return penColor;
    }
    int shape::getPenWidth()
    {
        return penWidth;
    }
    std::string shape::getPenStyle()
    {
        return penStyle;
    }
    std::string shape::getPenJointStyle()
    {
       return penJointStyle;
    }
    std::string shape::getBrushColor()
    {
        return brushColor;
    }
    std::string shape::getBrushStyle()
    {
        return brushStyle;
    }
    int shape::getShapeId()
    {
        return shapeId;
    }
    vector<int>* shape::getShapeDimensions()
    {
        return shapeDimensions;
    }

  /////////////////////////////////////////////////////////////////////////////

    void shape::setPenCapStyle(std::string style)
    {
        penCapStyle = style;
    }

    void shape::setPenColor(std::string color)
    {
        penColor = color;
    }
    void shape::setPenWidth(int width)
    {
        penWidth = width;
    }
    void shape::setPenStyle(std::string style)
    {
        penStyle = style;
    }
    void shape::setPenJointStyle(std::string style)
    {
        penJointStyle = style;
    }
    void shape::setBrushColor(std::string color)
    {
        brushColor = color;
    }
    void shape::setBrushStyle(std::string style)
    {
        brushStyle = style;
    }
    void shape::setShapeId(int iD)
    {
        shapeId = iD;
    }
    void shape::setShapeDimensions(vector<int> *dim)
    {
        delete shapeDimensions;
        shapeDimensions = dim;
    }
}

