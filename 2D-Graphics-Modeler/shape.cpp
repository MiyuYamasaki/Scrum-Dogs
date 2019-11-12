#include "shape.h"

namespace n{

    shape::shape()
    {
        shapeID = 0;
        shapeDimensions = nullptr;
        penWidth = 0;
        textString = "None";
        textPointSize = 0;
        textFontFamily = "None";
    }

   penCapStyle shape::getPenCapStyle()
    {
        return qPenCapStyle;
    }

   penColor shape::getPenColor()
   {
       return qPenColor;
   }

   int shape::getPenWidth()
   {
       return penWidth;
   }

   penStyle shape::getPenStyle()
   {
       return qPenStyle;
   }

   penJoinStyle shape::getPenJointStyle()
   {
       return qPenJoinStyle;
   }

   brushColor shape::getBrushColor()
   {
        return qBrushColor;
   }

   brushStyle shape::getBrushStyle()
   {
       return qBrushStyle;
   }

   int shape::getShapeId()
   {
       return shapeID;
   }

   vector<double>* shape::getShapeDimensions()
   {
       return shapeDimensions;
   }

///////////////////////////////////////////////////////////////////////////////

   void shape::setPenCapStyle(penCapStyle style)
   {
       qPenCapStyle = style;
   }

   void shape::setPenColor(penColor color)
   {
       qPenColor = color;
   }

   void shape::setPenWidth(int width)
   {
       penWidth = width;
   }

   void shape::setPenStyle(penStyle style)
   {
       qPenStyle = style;
   }

   void shape::setPenJoinStyle(penJoinStyle style)
   {
       qPenJoinStyle = style;
   }

   void shape::setBrushColor(brushColor color)
   {
      qBrushColor = color;
   }

   void shape::setBrushStyle(brushStyle style)
   {
       qBrushStyle = style;
   }

    void shape::setShapeId(int iD)
    {
       shapeID = iD;
    }

    void shape::setShapeDimensions(vector<double> *dim)
    {
        delete shapeDimensions;
        shapeDimensions = dim;
    }
}

