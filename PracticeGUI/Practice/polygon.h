#ifndef POLYGON_H
#define POLYGON_H

#include <shapes.h>

using namespace gProject;

/* A Polygon Class */
/*! This Polygon class is a child of the Shapes class.*/
class Polygon : public shapes
{
    public:
    /* An alternate constructor */
            /*! This constructor sets the type to a 2 (a polygon).*/
        Polygon(RenderArea *ra);
    private:
};

#endif // POLYGON_H
