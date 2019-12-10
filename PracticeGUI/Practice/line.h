#ifndef LINE_H
#define LINE_H

#include <shapes.h>

using namespace gProject;

/* A Line Class */
/*!  The Line class is inherited from shapes class*/
class Line : public shapes
{
    public:
        /*!< alternate constructor */
        /*!  Initializes the type data member*/
        Line(RenderArea *ra);
    private:
};

#endif // LINE_H
