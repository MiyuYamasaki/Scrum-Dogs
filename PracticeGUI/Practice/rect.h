#ifndef RECT_H
#define RECT_H

#include <shapes.h>

using namespace gProject;

class Rect : public shapes
{
    public:
        Rect(RenderArea *ra);
        virtual double get_perimeter();
        virtual double get_area();
    private:
};

#endif // RECT_H
