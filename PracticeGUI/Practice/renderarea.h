#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include <shapeparser.h>
#include <QLabel>

class shapes;
static int numShapes = 0;

/* Render Area Class */
/*! This class is derived from QWidget.*/
class RenderArea : public QWidget
{
    Q_OBJECT


public:
    /* Alternate Constructor */
        /*! This is setting up the canvas.*/
    RenderArea(QWidget *parent = 0);

    /* Sets the size of the canvas area */
        /*! The minumum size is (1000, 500).*/
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    /* This function also sets the size of the canvas area */
        /*! The minumum size is (1000, 500).*/
    QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
    /* Sets the shape and updates the canvas area */
        /*! The canvas will be updated with the new shape*/
    void setShape(Shape shape);
    /* Sets the Pen and updates the canvas area */
        /*! The canvas will be updated with the new Pen value*/
    void setPen(const QPen &pen);
    /* Sets the Brush and updates the canvas area */
        /*! The canvas will be updated with the new Brush value*/
    void setBrush(const QBrush &brush);
    /* Sets the antialiased (boolean) and updates the canvas area */
        /*! The canvas will be updated with the new antialiased value*/
    void setAntialiased(bool antialiased);
    /* Sets the transformed (boolean) and updates the canvas area */
        /*! The canvas will be updated with the new transformed value*/
    void setTransformed(bool transformed);
    void addShape(int, std::string, int, std::string, int, int, int, int, int, std::string, int, int, std::string, std::string, int, int);
    void editShape(int, int, std::string, int, std::string, int, int, int, int, int, std::string, int, int, std::string, std::string, int, int);
    void deleteShape(int);
    vector<gProject::shapes>* getSList();
    gProject::shapes findShape(int);
    QList<QString> getIDNums();

protected:
    /* This paints the shape onto the canvas */
        /*! The shape will be painted to the canvas with the specified values*/
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    /* This function writes the data (shape data) to the output file */
        /*! The output file will be updated with the new values (shapes)*/
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    /* The Shape enum data member*/
        /*! Keeps track of the shapes*/
    Shape shape;
    /* The QPen data member*/
        /*! Able to work with the properties in the QPen class*/
    QPen pen;
    /* The QBrash data member*/
        /*! Able to work with the properties in the QBrush class*/
    QBrush brush;
    /* The boolean data member transformed*/
      /*! This data member indicates as to whether the render area has been moved*/
    bool transformed;
    /* The boolean data member transformed*/
    /*! This data member indicates as to whether the render area has been smoothed*/
    bool antialiased;
    /* The templated vector of type shapes*/
        /*! Keeps track of the shapes*/
    vector<gProject::shapes>* sList = nullptr;
};
//! [0]

#endif // RENDERAREA_H
