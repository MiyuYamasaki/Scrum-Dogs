#ifndef POLYGON_H
#define POLYGON_H

#include <shapes.h>

using namespace gProject;

class Polygon : public shapes
{
    public:
        Polygon(RenderArea *ra);
        virtual double get_perimeter();
        virtual double get_area();
    private:
};

#endif // POLYGON_H
