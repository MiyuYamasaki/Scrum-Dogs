#ifndef RECT_H
#define RECT_H

#include <shapes.h>

using namespace gProject;

class Rect : public shapes
{
    public:
        Rect(RenderArea *ra);
        void set_Rect(QRect);
        QRect get_Rect();
        virtual double get_perimeter();
        virtual double get_area();
    private:
        QRect outline;
};

#endif // RECT_H
