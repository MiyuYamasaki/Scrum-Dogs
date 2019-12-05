#ifndef LINE_H
#define LINE_H

#include <shapes.h>

using namespace gProject;

class Line : public shapes
{
    public:
        Line(RenderArea *ra);
        void set_points(QPoint*);
    private:
        QPoint* points;
};

#endif // LINE_H
