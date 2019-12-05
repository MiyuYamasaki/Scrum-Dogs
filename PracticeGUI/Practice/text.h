#ifndef TEXT_H
#define TEXT_H

#include <shapes.h>

using namespace gProject;

class Text : public shapes
{
    public:
        Text(RenderArea *ra);
        void set_Rect(QRect);
        QRect get_Rect();
        void set_Alignment(Qt::AlignmentFlag);
        Qt::AlignmentFlag get_Alignment();
        void set_Text(std::string);
        std::string get_Text();
    private:
        QRect outline;
        Qt::AlignmentFlag alignment;
        std::string textString;
        int textPointSize;
        std::string textFontFamily;
};

#endif // TEXT_H
