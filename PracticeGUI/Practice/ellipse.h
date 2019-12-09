#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <shapes.h>

using namespace gProject;

class Ellipse : public shapes
{
    public:
        Ellipse(RenderArea *ra);
        double get_perimeter();
        double get_area();
    private:
};

#endif // ELLIPSE_H
