#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <shapes.h>

using namespace gProject;

class Ellipse : public shapes
{
    public:
        Ellipse(RenderArea *ra);
        virtual double get_perimeter();
        virtual double get_area();
    private:
};

#endif // ELLIPSE_H
