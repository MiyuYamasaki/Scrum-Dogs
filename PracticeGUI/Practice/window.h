#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QComboBox;
class QLabel;
class QSpinBox;
QT_END_NAMESPACE
class RenderArea;
class shapes;

//! [0]
/*! Window class  */
class Window : public QWidget
/*! Window class derived from QWidget  */
{
    Q_OBJECT

public:
    Window(); /*!< default constructor  */
/*! creates and initializes the window to default values   */

private slots:
    void shapeChanged();   /*!< to change shape  */
    void penChanged();	   /*!< changing pens  */
    void brushChanged();   /*!< changing brushes  */

private:
    RenderArea *renderArea; /*!< member to render area  */
    QLabel *shapeLabel;     /*!< label for shape  */
    QLabel *penWidthLabel;  /*!< pen width label  */
    QLabel *penStyleLabel;  /*!< pen style label  */
    QLabel *penCapLabel;    /*!< pen cap label    */
    QLabel *penJoinLabel;   /*!< label for shape  */
    QLabel *brushStyleLabel;/*!< label for brush style  */
    QLabel *otherOptionsLabel; /*!< label for other options  */
    QComboBox *shapeComboBox;  /*!< shape combo box  */
    QSpinBox *penWidthSpinBox; /*!< spin box for pen width  */
    QComboBox *penStyleComboBox;/*!< combo box for pen style  */
    QComboBox *penCapComboBox;  /*!< combo box for pen cap  */
    QComboBox *penJoinComboBox; /*!< combo box for pen join  */
    QComboBox *brushStyleComboBox;/*!< combo box for brush style  */
    QCheckBox *antialiasingCheckBox;/*!< check box for antialisiasing  */
    QCheckBox *transformationsCheckBox;/*!< combo box for transformations  */
};
//! [0]

#endif // WINDOW_H
