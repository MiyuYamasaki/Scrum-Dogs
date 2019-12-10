#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <shapes.h>

using namespace gProject;

/* A Ellipse Class */
/*!  The Ellipse class is inherited from shapes class*/
class Ellipse : public shapes
{
    public:
    /*!< alternate constructor */
            /*!  Initializes the type data member*/
        Ellipse(RenderArea *ra);
        /*!< Function that returns the perimeter of the ellipse*/
                /*!  Perimeter is calculated and then return*/
        double get_perimeter();
        /*!< Function that returns the area of the ellipse*/
                /*!  area is calculated and then return*/
        double get_area();
    private:
};

#endif // ELLIPSE_H
