#ifndef RECT_H
#define RECT_H

#include <shapes.h>

using namespace gProject;

class Rect : public shapes
{
    public:
        Rect(RenderArea *ra);
        double get_perimeter();
        double get_area();
    private:
};

#endif // RECT_H
