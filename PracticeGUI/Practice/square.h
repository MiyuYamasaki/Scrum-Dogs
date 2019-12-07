#ifndef SQUARE_H
#define SQUARE_H

#include <shapes.h>

using namespace gProject;

class Square : public shapes
{
    public:
        Square(RenderArea *ra);
        virtual double get_perimeter();
        virtual double get_area();
    private:
};

#endif // Square_H
