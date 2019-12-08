#ifndef CIRCLE_H
#define CIRCLE_H

#include <shapes.h>

using namespace gProject;
/*! Circle class */
class Circle : public shapes
/*! circle class is inherited from shapes */
{
    public:
        Circle(RenderArea *ra); /*!< alternate constructor */
    /*! alternate constructor renders area */
        virtual double get_perimeter(); /*!< getter function */
    /*! Function gets perimeter */
        virtual double get_area();	/*!< getter function */
    /*! Function gets area */
    private:
};

#endif // CIRCLE_H
