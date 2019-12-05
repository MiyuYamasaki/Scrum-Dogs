#ifndef POLYLINE_H
#define POLYLINE_H

#include <shapes.h>

using namespace gProject;

class Polyline : public shapes
{
    public:
        Polyline(RenderArea *ra);
        void set_points(QPoint*);
    private:
        QPoint* points;
};

#endif // POLYLINE_H
