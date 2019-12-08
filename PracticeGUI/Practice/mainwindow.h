#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <renderarea.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
/*! mainWindow class  */
class MainWindow : public QMainWindow
/*! derived from QMainindow  */
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); /*!< default constructor  */
/*! parent for QWidget set to nullptr  */
    ~MainWindow(); /*!< destructor  */
private slots:
    void on_Brush_Color_ComboBox_activated(int index);

    void on_Pen_Join_Style_ComboBox_activated(int index);

    void on_Brush_Style_ComboBox_activated(int index);

    void on_Text_Color_ComboBox_activated(int index);

    void on_Pen_Cap_Style_ComboBox_activated(int index);

    void on_Pen_Style_ComboBox_activated(int index);

    void on_Pen_Width_LineEdit_textEdited(const QString &arg1);

    void on_Pen_Color_ComboBox_activated(int index);

    void on_Shape_Type_Combo_Box_activated(int index);

    void on_Shape_Dim_LineEdit_textEdited(const QString &arg1);

    void on_Allignment_ComboBox_activated(int index);

    void on_Text_Point_Size_LineEdit_textEdited(const QString &arg1);

    void on_Text_LineEdit_textEdited(const QString &arg1);

    void on_Font_Family_LineEdit_textEdited(const QString &arg1);

    void on_Font_Style_ComboBox_activated(int index);

    void on_Font_Weight_ComboBox_activated(int index);

    void on_pushButton_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void closeEvent (QCloseEvent *event);

    void on_Delete_Shape_ComboBox_activated(int index);

    void on_pushButton_delete_shape_clicked();

    void on_pushButton_refresh_clicked();

    void on_Delete_Shape_ComboBox_currentIndexChanged(int index);

private:
    RenderArea *renderArea;
    Ui::MainWindow *ui; /*!< private member  */
/*! ui for the main window  */
};
#endif // MAINWINDOW_H
