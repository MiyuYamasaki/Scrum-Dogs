#ifndef POLYGON_H
#define POLYGON_H

#include <shapes.h>

using namespace gProject;

class Polygon : public shapes
{
    public:
        Polygon(RenderArea *ra);
        void set_points(QPoint*);
        QPoint* get_points();
        virtual double get_perimeter();
        virtual double get_area();
    private:
        QPoint* points;
};

#endif // POLYGON_H
