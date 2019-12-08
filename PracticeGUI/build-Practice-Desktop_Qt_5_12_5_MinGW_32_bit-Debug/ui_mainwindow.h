/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Shape_Type_Label;
    QLabel *Shape_Dim_Shape_Label;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QLabel *Brush_Color_Label;
    QComboBox *Brush_Color_ComboBox;
    QLabel *Pen_Cap_Style_Label;
    QComboBox *Pen_Cap_Style_ComboBox;
    QLabel *Brush_Style_Label;
    QComboBox *Brush_Style_ComboBox;
    QLabel *Pen_Join_Style_Label;
    QComboBox *Pen_Join_Style_ComboBox;
    QLabel *Pen_Style_Label;
    QComboBox *Pen_Style_ComboBox;
    QLabel *Pen_Width_Label;
    QLineEdit *Pen_Width_LineEdit;
    QLabel *Pen_Color_Label;
    QComboBox *Pen_Color_ComboBox;
    QLabel *perimeter_label;
    QLabel *area_label;
    QWidget *tab_2;
    QLabel *Allignment_Label;
    QComboBox *Allignment_ComboBox;
    QLabel *Allignment_Label_2;
    QLineEdit *Text_LineEdit;
    QLabel *Text_Point_Size_Label;
    QLineEdit *Text_Point_Size_LineEdit;
    QLabel *Font_Family_Label;
    QLineEdit *Font_Family_LineEdit;
    QLabel *Font_Style_Label;
    QComboBox *Font_Style_ComboBox;
    QLabel *Font_Weight_Label;
    QComboBox *Font_Weight_ComboBox;
    QLabel *Text_Color_Label_2;
    QComboBox *Text_Color_ComboBox;
    QLineEdit *Shape_Dim_LineEdit;
    QComboBox *Shape_Type_Combo_Box;
    QPushButton *pushButton;
    QComboBox *Delete_Shape_ComboBox;
    QLabel *Delete_Shape_Label;
    QPushButton *pushButton_delete_shape;
    QPushButton *pushButton_refresh;
    QPushButton *pushButton_edit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuFormat;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(510, 437);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Shape_Type_Label = new QLabel(centralwidget);
        Shape_Type_Label->setObjectName(QString::fromUtf8("Shape_Type_Label"));
        Shape_Type_Label->setGeometry(QRect(380, 20, 101, 20));
        Shape_Dim_Shape_Label = new QLabel(centralwidget);
        Shape_Dim_Shape_Label->setObjectName(QString::fromUtf8("Shape_Dim_Shape_Label"));
        Shape_Dim_Shape_Label->setGeometry(QRect(380, 80, 111, 20));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 50, 331, 331));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        Brush_Color_Label = new QLabel(tab_1);
        Brush_Color_Label->setObjectName(QString::fromUtf8("Brush_Color_Label"));
        Brush_Color_Label->setGeometry(QRect(0, 20, 111, 20));
        Brush_Color_ComboBox = new QComboBox(tab_1);
        Brush_Color_ComboBox->addItem(QString());
        Brush_Color_ComboBox->addItem(QString());
        Brush_Color_ComboBox->addItem(QString());
        Brush_Color_ComboBox->addItem(QString());
        Brush_Color_ComboBox->addItem(QString());
        Brush_Color_ComboBox->addItem(QString());
        Brush_Color_ComboBox->addItem(QString());
        Brush_Color_ComboBox->addItem(QString());
        Brush_Color_ComboBox->addItem(QString());
        Brush_Color_ComboBox->addItem(QString());
        Brush_Color_ComboBox->addItem(QString());
        Brush_Color_ComboBox->setObjectName(QString::fromUtf8("Brush_Color_ComboBox"));
        Brush_Color_ComboBox->setGeometry(QRect(0, 40, 131, 32));
        Pen_Cap_Style_Label = new QLabel(tab_1);
        Pen_Cap_Style_Label->setObjectName(QString::fromUtf8("Pen_Cap_Style_Label"));
        Pen_Cap_Style_Label->setGeometry(QRect(150, 20, 101, 20));
        Pen_Cap_Style_ComboBox = new QComboBox(tab_1);
        Pen_Cap_Style_ComboBox->addItem(QString());
        Pen_Cap_Style_ComboBox->addItem(QString());
        Pen_Cap_Style_ComboBox->addItem(QString());
        Pen_Cap_Style_ComboBox->setObjectName(QString::fromUtf8("Pen_Cap_Style_ComboBox"));
        Pen_Cap_Style_ComboBox->setGeometry(QRect(150, 40, 131, 32));
        Brush_Style_Label = new QLabel(tab_1);
        Brush_Style_Label->setObjectName(QString::fromUtf8("Brush_Style_Label"));
        Brush_Style_Label->setGeometry(QRect(0, 140, 111, 20));
        Brush_Style_ComboBox = new QComboBox(tab_1);
        Brush_Style_ComboBox->addItem(QString());
        Brush_Style_ComboBox->addItem(QString());
        Brush_Style_ComboBox->addItem(QString());
        Brush_Style_ComboBox->addItem(QString());
        Brush_Style_ComboBox->setObjectName(QString::fromUtf8("Brush_Style_ComboBox"));
        Brush_Style_ComboBox->setGeometry(QRect(0, 160, 131, 32));
        Pen_Join_Style_Label = new QLabel(tab_1);
        Pen_Join_Style_Label->setObjectName(QString::fromUtf8("Pen_Join_Style_Label"));
        Pen_Join_Style_Label->setGeometry(QRect(0, 80, 101, 20));
        Pen_Join_Style_ComboBox = new QComboBox(tab_1);
        Pen_Join_Style_ComboBox->addItem(QString());
        Pen_Join_Style_ComboBox->addItem(QString());
        Pen_Join_Style_ComboBox->addItem(QString());
        Pen_Join_Style_ComboBox->setObjectName(QString::fromUtf8("Pen_Join_Style_ComboBox"));
        Pen_Join_Style_ComboBox->setGeometry(QRect(0, 100, 131, 32));
        Pen_Style_Label = new QLabel(tab_1);
        Pen_Style_Label->setObjectName(QString::fromUtf8("Pen_Style_Label"));
        Pen_Style_Label->setGeometry(QRect(150, 80, 101, 20));
        Pen_Style_ComboBox = new QComboBox(tab_1);
        Pen_Style_ComboBox->addItem(QString());
        Pen_Style_ComboBox->addItem(QString());
        Pen_Style_ComboBox->addItem(QString());
        Pen_Style_ComboBox->addItem(QString());
        Pen_Style_ComboBox->addItem(QString());
        Pen_Style_ComboBox->addItem(QString());
        Pen_Style_ComboBox->setObjectName(QString::fromUtf8("Pen_Style_ComboBox"));
        Pen_Style_ComboBox->setGeometry(QRect(150, 100, 131, 32));
        Pen_Width_Label = new QLabel(tab_1);
        Pen_Width_Label->setObjectName(QString::fromUtf8("Pen_Width_Label"));
        Pen_Width_Label->setGeometry(QRect(150, 140, 101, 20));
        Pen_Width_LineEdit = new QLineEdit(tab_1);
        Pen_Width_LineEdit->setObjectName(QString::fromUtf8("Pen_Width_LineEdit"));
        Pen_Width_LineEdit->setGeometry(QRect(150, 160, 113, 21));
        Pen_Color_Label = new QLabel(tab_1);
        Pen_Color_Label->setObjectName(QString::fromUtf8("Pen_Color_Label"));
        Pen_Color_Label->setGeometry(QRect(0, 200, 101, 20));
        Pen_Color_ComboBox = new QComboBox(tab_1);
        Pen_Color_ComboBox->addItem(QString());
        Pen_Color_ComboBox->addItem(QString());
        Pen_Color_ComboBox->addItem(QString());
        Pen_Color_ComboBox->addItem(QString());
        Pen_Color_ComboBox->addItem(QString());
        Pen_Color_ComboBox->addItem(QString());
        Pen_Color_ComboBox->addItem(QString());
        Pen_Color_ComboBox->addItem(QString());
        Pen_Color_ComboBox->addItem(QString());
        Pen_Color_ComboBox->addItem(QString());
        Pen_Color_ComboBox->addItem(QString());
        Pen_Color_ComboBox->setObjectName(QString::fromUtf8("Pen_Color_ComboBox"));
        Pen_Color_ComboBox->setGeometry(QRect(0, 220, 131, 32));
        perimeter_label = new QLabel(tab_1);
        perimeter_label->setObjectName(QString::fromUtf8("perimeter_label"));
        perimeter_label->setGeometry(QRect(0, 260, 141, 16));
        area_label = new QLabel(tab_1);
        area_label->setObjectName(QString::fromUtf8("area_label"));
        area_label->setGeometry(QRect(150, 260, 141, 20));
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        Allignment_Label = new QLabel(tab_2);
        Allignment_Label->setObjectName(QString::fromUtf8("Allignment_Label"));
        Allignment_Label->setGeometry(QRect(0, 20, 101, 20));
        Allignment_ComboBox = new QComboBox(tab_2);
        Allignment_ComboBox->addItem(QString());
        Allignment_ComboBox->addItem(QString());
        Allignment_ComboBox->addItem(QString());
        Allignment_ComboBox->addItem(QString());
        Allignment_ComboBox->addItem(QString());
        Allignment_ComboBox->setObjectName(QString::fromUtf8("Allignment_ComboBox"));
        Allignment_ComboBox->setGeometry(QRect(0, 40, 131, 32));
        Allignment_Label_2 = new QLabel(tab_2);
        Allignment_Label_2->setObjectName(QString::fromUtf8("Allignment_Label_2"));
        Allignment_Label_2->setGeometry(QRect(0, 80, 101, 20));
        Text_LineEdit = new QLineEdit(tab_2);
        Text_LineEdit->setObjectName(QString::fromUtf8("Text_LineEdit"));
        Text_LineEdit->setGeometry(QRect(0, 100, 113, 21));
        Text_Point_Size_Label = new QLabel(tab_2);
        Text_Point_Size_Label->setObjectName(QString::fromUtf8("Text_Point_Size_Label"));
        Text_Point_Size_Label->setGeometry(QRect(150, 20, 101, 20));
        Text_Point_Size_LineEdit = new QLineEdit(tab_2);
        Text_Point_Size_LineEdit->setObjectName(QString::fromUtf8("Text_Point_Size_LineEdit"));
        Text_Point_Size_LineEdit->setGeometry(QRect(150, 40, 113, 21));
        Font_Family_Label = new QLabel(tab_2);
        Font_Family_Label->setObjectName(QString::fromUtf8("Font_Family_Label"));
        Font_Family_Label->setGeometry(QRect(150, 80, 101, 20));
        Font_Family_LineEdit = new QLineEdit(tab_2);
        Font_Family_LineEdit->setObjectName(QString::fromUtf8("Font_Family_LineEdit"));
        Font_Family_LineEdit->setGeometry(QRect(150, 100, 113, 21));
        Font_Style_Label = new QLabel(tab_2);
        Font_Style_Label->setObjectName(QString::fromUtf8("Font_Style_Label"));
        Font_Style_Label->setGeometry(QRect(0, 130, 101, 20));
        Font_Style_ComboBox = new QComboBox(tab_2);
        Font_Style_ComboBox->addItem(QString());
        Font_Style_ComboBox->addItem(QString());
        Font_Style_ComboBox->addItem(QString());
        Font_Style_ComboBox->setObjectName(QString::fromUtf8("Font_Style_ComboBox"));
        Font_Style_ComboBox->setGeometry(QRect(0, 150, 131, 32));
        Font_Weight_Label = new QLabel(tab_2);
        Font_Weight_Label->setObjectName(QString::fromUtf8("Font_Weight_Label"));
        Font_Weight_Label->setGeometry(QRect(150, 130, 101, 20));
        Font_Weight_ComboBox = new QComboBox(tab_2);
        Font_Weight_ComboBox->addItem(QString());
        Font_Weight_ComboBox->addItem(QString());
        Font_Weight_ComboBox->addItem(QString());
        Font_Weight_ComboBox->addItem(QString());
        Font_Weight_ComboBox->setObjectName(QString::fromUtf8("Font_Weight_ComboBox"));
        Font_Weight_ComboBox->setGeometry(QRect(150, 150, 131, 32));
        Text_Color_Label_2 = new QLabel(tab_2);
        Text_Color_Label_2->setObjectName(QString::fromUtf8("Text_Color_Label_2"));
        Text_Color_Label_2->setGeometry(QRect(0, 190, 61, 16));
        Text_Color_ComboBox = new QComboBox(tab_2);
        Text_Color_ComboBox->addItem(QString());
        Text_Color_ComboBox->addItem(QString());
        Text_Color_ComboBox->addItem(QString());
        Text_Color_ComboBox->addItem(QString());
        Text_Color_ComboBox->addItem(QString());
        Text_Color_ComboBox->addItem(QString());
        Text_Color_ComboBox->addItem(QString());
        Text_Color_ComboBox->addItem(QString());
        Text_Color_ComboBox->addItem(QString());
        Text_Color_ComboBox->addItem(QString());
        Text_Color_ComboBox->addItem(QString());
        Text_Color_ComboBox->setObjectName(QString::fromUtf8("Text_Color_ComboBox"));
        Text_Color_ComboBox->setGeometry(QRect(0, 210, 131, 32));
        tabWidget->addTab(tab_2, QString());
        Shape_Dim_LineEdit = new QLineEdit(centralwidget);
        Shape_Dim_LineEdit->setObjectName(QString::fromUtf8("Shape_Dim_LineEdit"));
        Shape_Dim_LineEdit->setGeometry(QRect(380, 100, 113, 21));
        Shape_Type_Combo_Box = new QComboBox(centralwidget);
        Shape_Type_Combo_Box->addItem(QString());
        Shape_Type_Combo_Box->addItem(QString());
        Shape_Type_Combo_Box->addItem(QString());
        Shape_Type_Combo_Box->addItem(QString());
        Shape_Type_Combo_Box->addItem(QString());
        Shape_Type_Combo_Box->addItem(QString());
        Shape_Type_Combo_Box->addItem(QString());
        Shape_Type_Combo_Box->addItem(QString());
        Shape_Type_Combo_Box->setObjectName(QString::fromUtf8("Shape_Type_Combo_Box"));
        Shape_Type_Combo_Box->setGeometry(QRect(380, 40, 91, 32));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 130, 93, 28));
        Delete_Shape_ComboBox = new QComboBox(centralwidget);
        Delete_Shape_ComboBox->setObjectName(QString::fromUtf8("Delete_Shape_ComboBox"));
        Delete_Shape_ComboBox->setGeometry(QRect(380, 220, 73, 22));
        Delete_Shape_Label = new QLabel(centralwidget);
        Delete_Shape_Label->setObjectName(QString::fromUtf8("Delete_Shape_Label"));
        Delete_Shape_Label->setGeometry(QRect(380, 200, 111, 16));
        pushButton_delete_shape = new QPushButton(centralwidget);
        pushButton_delete_shape->setObjectName(QString::fromUtf8("pushButton_delete_shape"));
        pushButton_delete_shape->setGeometry(QRect(380, 250, 93, 28));
        pushButton_refresh = new QPushButton(centralwidget);
        pushButton_refresh->setObjectName(QString::fromUtf8("pushButton_refresh"));
        pushButton_refresh->setGeometry(QRect(380, 310, 93, 28));
        pushButton_edit = new QPushButton(centralwidget);
        pushButton_edit->setObjectName(QString::fromUtf8("pushButton_edit"));
        pushButton_edit->setGeometry(QRect(380, 280, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 510, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuFormat = new QMenu(menubar);
        menuFormat->setObjectName(QString::fromUtf8("menuFormat"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuFormat->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        Shape_Type_Label->setText(QApplication::translate("MainWindow", "Shape Type", nullptr));
        Shape_Dim_Shape_Label->setText(QApplication::translate("MainWindow", "Shape Dimensions", nullptr));
        Brush_Color_Label->setText(QApplication::translate("MainWindow", "Brush Color", nullptr));
        Brush_Color_ComboBox->setItemText(0, QApplication::translate("MainWindow", "black", nullptr));
        Brush_Color_ComboBox->setItemText(1, QApplication::translate("MainWindow", "white", nullptr));
        Brush_Color_ComboBox->setItemText(2, QApplication::translate("MainWindow", "darkGray", nullptr));
        Brush_Color_ComboBox->setItemText(3, QApplication::translate("MainWindow", "gray", nullptr));
        Brush_Color_ComboBox->setItemText(4, QApplication::translate("MainWindow", "lightGray", nullptr));
        Brush_Color_ComboBox->setItemText(5, QApplication::translate("MainWindow", "red", nullptr));
        Brush_Color_ComboBox->setItemText(6, QApplication::translate("MainWindow", "green", nullptr));
        Brush_Color_ComboBox->setItemText(7, QApplication::translate("MainWindow", "blue", nullptr));
        Brush_Color_ComboBox->setItemText(8, QApplication::translate("MainWindow", "cyan", nullptr));
        Brush_Color_ComboBox->setItemText(9, QApplication::translate("MainWindow", "magenta", nullptr));
        Brush_Color_ComboBox->setItemText(10, QApplication::translate("MainWindow", "yellow", nullptr));

        Pen_Cap_Style_Label->setText(QApplication::translate("MainWindow", "Pen Cap Style", nullptr));
        Pen_Cap_Style_ComboBox->setItemText(0, QApplication::translate("MainWindow", "FlatCap", nullptr));
        Pen_Cap_Style_ComboBox->setItemText(1, QApplication::translate("MainWindow", "SquareCap", nullptr));
        Pen_Cap_Style_ComboBox->setItemText(2, QApplication::translate("MainWindow", "RoundCap", nullptr));

        Brush_Style_Label->setText(QApplication::translate("MainWindow", "Brush Style", nullptr));
        Brush_Style_ComboBox->setItemText(0, QApplication::translate("MainWindow", "SolidPattern", nullptr));
        Brush_Style_ComboBox->setItemText(1, QApplication::translate("MainWindow", "HorPattern", nullptr));
        Brush_Style_ComboBox->setItemText(2, QApplication::translate("MainWindow", "VerPattern", nullptr));
        Brush_Style_ComboBox->setItemText(3, QApplication::translate("MainWindow", "NoBrush", nullptr));

        Pen_Join_Style_Label->setText(QApplication::translate("MainWindow", "Pen Join Style", nullptr));
        Pen_Join_Style_ComboBox->setItemText(0, QApplication::translate("MainWindow", "MiterJoin", nullptr));
        Pen_Join_Style_ComboBox->setItemText(1, QApplication::translate("MainWindow", "BevelJoin", nullptr));
        Pen_Join_Style_ComboBox->setItemText(2, QApplication::translate("MainWindow", "RoundJoin", nullptr));

        Pen_Style_Label->setText(QApplication::translate("MainWindow", "Pen Style", nullptr));
        Pen_Style_ComboBox->setItemText(0, QApplication::translate("MainWindow", "NoPen", nullptr));
        Pen_Style_ComboBox->setItemText(1, QApplication::translate("MainWindow", "SolidLine", nullptr));
        Pen_Style_ComboBox->setItemText(2, QApplication::translate("MainWindow", "DashLine", nullptr));
        Pen_Style_ComboBox->setItemText(3, QApplication::translate("MainWindow", "DotLine", nullptr));
        Pen_Style_ComboBox->setItemText(4, QApplication::translate("MainWindow", "DashDotLine", nullptr));
        Pen_Style_ComboBox->setItemText(5, QApplication::translate("MainWindow", "DashDotDotLine", nullptr));

        Pen_Width_Label->setText(QApplication::translate("MainWindow", "Pen Width", nullptr));
        Pen_Color_Label->setText(QApplication::translate("MainWindow", "Pen Color", nullptr));
        Pen_Color_ComboBox->setItemText(0, QApplication::translate("MainWindow", "black", nullptr));
        Pen_Color_ComboBox->setItemText(1, QApplication::translate("MainWindow", "white", nullptr));
        Pen_Color_ComboBox->setItemText(2, QApplication::translate("MainWindow", "darkGray", nullptr));
        Pen_Color_ComboBox->setItemText(3, QApplication::translate("MainWindow", "gray", nullptr));
        Pen_Color_ComboBox->setItemText(4, QApplication::translate("MainWindow", "lightGray", nullptr));
        Pen_Color_ComboBox->setItemText(5, QApplication::translate("MainWindow", "red", nullptr));
        Pen_Color_ComboBox->setItemText(6, QApplication::translate("MainWindow", "green", nullptr));
        Pen_Color_ComboBox->setItemText(7, QApplication::translate("MainWindow", "blue", nullptr));
        Pen_Color_ComboBox->setItemText(8, QApplication::translate("MainWindow", "cyan", nullptr));
        Pen_Color_ComboBox->setItemText(9, QApplication::translate("MainWindow", "magenta", nullptr));
        Pen_Color_ComboBox->setItemText(10, QApplication::translate("MainWindow", "yellow", nullptr));

        perimeter_label->setText(QApplication::translate("MainWindow", "Perimeter:", nullptr));
        area_label->setText(QApplication::translate("MainWindow", "Area:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MainWindow", "Tab 1", nullptr));
        Allignment_Label->setText(QApplication::translate("MainWindow", "Allignment", nullptr));
        Allignment_ComboBox->setItemText(0, QApplication::translate("MainWindow", "AllignLeft", nullptr));
        Allignment_ComboBox->setItemText(1, QApplication::translate("MainWindow", "AllignRight", nullptr));
        Allignment_ComboBox->setItemText(2, QApplication::translate("MainWindow", "AllignTop", nullptr));
        Allignment_ComboBox->setItemText(3, QApplication::translate("MainWindow", "AllignBottom", nullptr));
        Allignment_ComboBox->setItemText(4, QApplication::translate("MainWindow", "AllignCenter", nullptr));

        Allignment_Label_2->setText(QApplication::translate("MainWindow", "Text", nullptr));
        Text_Point_Size_Label->setText(QApplication::translate("MainWindow", "Text Point Size", nullptr));
        Font_Family_Label->setText(QApplication::translate("MainWindow", "Font Family", nullptr));
        Font_Style_Label->setText(QApplication::translate("MainWindow", "Font Style", nullptr));
        Font_Style_ComboBox->setItemText(0, QApplication::translate("MainWindow", "StyleNormal", nullptr));
        Font_Style_ComboBox->setItemText(1, QApplication::translate("MainWindow", "StyleItalic", nullptr));
        Font_Style_ComboBox->setItemText(2, QApplication::translate("MainWindow", "StyleOblique", nullptr));

        Font_Weight_Label->setText(QApplication::translate("MainWindow", "Font Weight", nullptr));
        Font_Weight_ComboBox->setItemText(0, QApplication::translate("MainWindow", "Thin", nullptr));
        Font_Weight_ComboBox->setItemText(1, QApplication::translate("MainWindow", "Light", nullptr));
        Font_Weight_ComboBox->setItemText(2, QApplication::translate("MainWindow", "Normal", nullptr));
        Font_Weight_ComboBox->setItemText(3, QApplication::translate("MainWindow", "Bold", nullptr));

        Text_Color_Label_2->setText(QApplication::translate("MainWindow", "Text Color", nullptr));
        Text_Color_ComboBox->setItemText(0, QApplication::translate("MainWindow", "black", nullptr));
        Text_Color_ComboBox->setItemText(1, QApplication::translate("MainWindow", "white", nullptr));
        Text_Color_ComboBox->setItemText(2, QApplication::translate("MainWindow", "darkGray", nullptr));
        Text_Color_ComboBox->setItemText(3, QApplication::translate("MainWindow", "gray", nullptr));
        Text_Color_ComboBox->setItemText(4, QApplication::translate("MainWindow", "lightGray", nullptr));
        Text_Color_ComboBox->setItemText(5, QApplication::translate("MainWindow", "red", nullptr));
        Text_Color_ComboBox->setItemText(6, QApplication::translate("MainWindow", "green", nullptr));
        Text_Color_ComboBox->setItemText(7, QApplication::translate("MainWindow", "blue", nullptr));
        Text_Color_ComboBox->setItemText(8, QApplication::translate("MainWindow", "cyan", nullptr));
        Text_Color_ComboBox->setItemText(9, QApplication::translate("MainWindow", "magenta", nullptr));
        Text_Color_ComboBox->setItemText(10, QApplication::translate("MainWindow", "yellow", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", nullptr));
        Shape_Type_Combo_Box->setItemText(0, QApplication::translate("MainWindow", "Line", nullptr));
        Shape_Type_Combo_Box->setItemText(1, QApplication::translate("MainWindow", "Polyline", nullptr));
        Shape_Type_Combo_Box->setItemText(2, QApplication::translate("MainWindow", "Polygon", nullptr));
        Shape_Type_Combo_Box->setItemText(3, QApplication::translate("MainWindow", "Rectangle", nullptr));
        Shape_Type_Combo_Box->setItemText(4, QApplication::translate("MainWindow", "Square", nullptr));
        Shape_Type_Combo_Box->setItemText(5, QApplication::translate("MainWindow", "Ellipse", nullptr));
        Shape_Type_Combo_Box->setItemText(6, QApplication::translate("MainWindow", "Circle", nullptr));
        Shape_Type_Combo_Box->setItemText(7, QApplication::translate("MainWindow", "Text", nullptr));

        pushButton->setText(QApplication::translate("MainWindow", "Create Shape", nullptr));
        Delete_Shape_Label->setText(QApplication::translate("MainWindow", "Edit/Delete Shape", nullptr));
        pushButton_delete_shape->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        pushButton_refresh->setText(QApplication::translate("MainWindow", "Refresh", nullptr));
        pushButton_edit->setText(QApplication::translate("MainWindow", "Edit", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuFormat->setTitle(QApplication::translate("MainWindow", "Format", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
