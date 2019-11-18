#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QWidget>
#include "shape.h"

using namespace n;

class ellipse : public shape
{
public:
    ellipse();
    virtual double getPerimeter();
    virtual double getArea();
    virtual ~ellipse() {}
};

#endif // ellipse_H
