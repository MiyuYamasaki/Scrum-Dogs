#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <shapes.h>

using namespace gProject;

class Ellipse : public shapes
{
    public:
        Ellipse(RenderArea *ra);
        void set_Rect(QRect);
        QRect get_Rect();
        virtual double get_perimeter();
        virtual double get_area();
    private:
        QRect outline;
};

#endif // ELLIPSE_H
