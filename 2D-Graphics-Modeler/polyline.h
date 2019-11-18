#ifndef POLYLINE_H
#define POLYLINE_H

#include <QWidget>
#include "shape.h"

using namespace n;

class polyline : public shape
{
public:
    polyline();
    virtual double getPerimeter();
    virtual double getArea();
    virtual ~polyline() {}
};

#endif // polyline_H
