#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QWidget>
#include "shape.h"

using namespace n;

class rectangle : public shape
{
public:
    rectangle();
    virtual double getPerimeter();
    virtual double getArea();
    virtual ~rectangle() {}
};

#endif // RECTANGLE_H
