#ifndef SQUARE_H
#define SQUARE_H

#include <shapes.h>

using namespace gProject;
/* A Square Class */
/*!  The vector class is a custom container class derived from shapes class.*/
class Square : public shapes
{
    public:
        Square(RenderArea *ra/**< [in] docs for input parameter ra. */); /*! Alternate constructor renders the area */
    /*!< alternate constructor */
        double get_perimeter(); /*!< Gets the perimeter */
        double get_area();	/*!< Gets the area      */
    private:
};

#endif // Square_H
