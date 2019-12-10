#ifndef POLYLINE_H
#define POLYLINE_H

#include <shapes.h>

using namespace gProject;

/* A Polyline Class */
/*! This Polyline class is a child of shapes.*/
class Polyline : public shapes
{
    public:
    /* An Alternate Constructor */
            /*! This sets the type to 1 a polyline.*/
        Polyline(RenderArea *ra);
    private:
};

#endif // POLYLINE_H
