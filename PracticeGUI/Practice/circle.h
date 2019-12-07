#ifndef CIRCLE_H
#define CIRCLE_H

#include <shapes.h>

using namespace gProject;

class Circle : public shapes
{
    public:
        Circle(RenderArea *ra);
        virtual double get_perimeter();
        virtual double get_area();
    private:
};

#endif // CIRCLE_H
