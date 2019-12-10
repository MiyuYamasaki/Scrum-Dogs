#ifndef RECT_H
#define RECT_H

#include <shapes.h>

using namespace gProject;

/* A Rectangle Class */
/*!  The Rectangle class is a child of the shapes class.*/
class Rect : public shapes
{
    public:
    /* An alternate constuctor */
        /*! The alternate constructor sets the type to 3 (Rectangle).*/
        Rect(RenderArea *ra);
        /* Returns the perimeter of the Rectangle */
                /*!  Calculates and then returns a double (perimeter).*/
        double get_perimeter();
        /* Returns the area of the Rectangle */
                /*!  Calculates and then returns a double (area).*/
        double get_area();
    private:
};

#endif // RECT_H
