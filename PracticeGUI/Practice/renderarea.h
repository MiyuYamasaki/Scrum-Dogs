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

class RenderArea : public QWidget
{
    Q_OBJECT


public:

    RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

public slots:
    void setShape(Shape shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setAntialiased(bool antialiased);
    void setTransformed(bool transformed);
    void addShape(int, std::string, int, std::string, int, int, int, int, int, std::string, int, int, std::string, std::string, int, int);
    void editShape(int, int, std::string, int, std::string, int, int, int, int, int, std::string, int, int, std::string, std::string, int, int);
    void deleteShape(int);
    vector<gProject::shapes>* getSList();
    gProject::shapes findShape(int);
    QList<QString> getIDNums();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    bool transformed;
    bool antialiased;
    vector<gProject::shapes>* sList = nullptr;
};
//! [0]

#endif // RENDERAREA_H
