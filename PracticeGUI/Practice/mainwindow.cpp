#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent) /*!< MainWindow constructor  */
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
/*!<  constructing ui from QWidget parent */
{
    ui->setupUi(this);
    renderArea = new RenderArea;
    renderArea->setGeometry(0,0,1000,500);
    renderArea->show();
}

MainWindow::~MainWindow() /*!< destructor  */
{
    delete ui;
/*! ui has been deleted  */
}


void MainWindow::on_Brush_Color_ComboBox_activated(int index)
{

}

void MainWindow::on_Pen_Join_Style_ComboBox_activated(int index)
{

}

void MainWindow::on_Brush_Style_ComboBox_activated(int index)
{

}

void MainWindow::on_Text_Color_ComboBox_activated(int index)
{

}

void MainWindow::on_Pen_Cap_Style_ComboBox_activated(int index)
{

}

void MainWindow::on_Pen_Style_ComboBox_activated(int index)
{

}

void MainWindow::on_Pen_Width_LineEdit_textEdited(const QString &arg1)
{

}

void MainWindow::on_Pen_Color_ComboBox_activated(int index)
{

}

void MainWindow::on_Shape_Type_Combo_Box_activated(int index)
{

}

void MainWindow::on_Shape_Dim_LineEdit_textEdited(const QString &arg1)
{

}

void MainWindow::on_Allignment_ComboBox_activated(int index)
{

}

void MainWindow::on_Text_Point_Size_LineEdit_textEdited(const QString &arg1)
{

}

void MainWindow::on_Text_LineEdit_textEdited(const QString &arg1)
{

}

void MainWindow::on_Font_Family_LineEdit_textEdited(const QString &arg1)
{

}

void MainWindow::on_Font_Style_ComboBox_activated(int index)
{

}

void MainWindow::on_Font_Weight_ComboBox_activated(int index)
{

}

void MainWindow::on_pushButton_clicked()
{
    renderArea->addShape(ui->Shape_Type_Combo_Box->currentIndex(),
                        ui->Shape_Dim_LineEdit->text().toLocal8Bit().constData(),
                        ui->Pen_Color_ComboBox->currentIndex(),
                        ui->Pen_Width_LineEdit->text().toLocal8Bit().constData(),
                        ui->Pen_Style_ComboBox->currentIndex(),
                        ui->Pen_Cap_Style_ComboBox->currentIndex(),
                        ui->Pen_Join_Style_ComboBox->currentIndex(),
                        ui->Brush_Color_ComboBox->currentIndex(),
                        ui->Brush_Style_ComboBox->currentIndex(),
                        ui->Text_LineEdit->text().toLocal8Bit().constData(),
                        ui->Text_Color_ComboBox->currentIndex(),
                        ui->Allignment_ComboBox->currentIndex(),
                        ui->Text_Point_Size_LineEdit->text().toLocal8Bit().constData(),
                        ui->Font_Family_LineEdit->text().toLocal8Bit().constData(),
                        ui->Font_Style_ComboBox->currentIndex(),
                        ui->Font_Weight_ComboBox->currentIndex());
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{

}

void MainWindow::closeEvent (QCloseEvent *event)
{
    renderArea->close();
}

void MainWindow::on_Delete_Shape_ComboBox_activated(int index)
{

}

void MainWindow::on_pushButton_delete_shape_clicked()
{
    renderArea->deleteShape(ui->Delete_Shape_ComboBox->currentIndex());
}

void MainWindow::on_pushButton_refresh_clicked()
{
    ui->Delete_Shape_ComboBox->clear();
    ui->Delete_Shape_ComboBox->addItems(renderArea->getIDNums());
}

void MainWindow::on_Delete_Shape_ComboBox_currentIndexChanged(int index)
{

  gProject::shapes tempShape = this->renderArea->findShape(index);
  for(int i = 0; i < 8; i++)
  {
      if(tempShape.getShape() == i)
          ui->Shape_Type_Combo_Box->setCurrentIndex(i);
  }
  for(int i = 0; i < 11; i++)
  {
      if(tempShape.getShape() == i)
          ui->Brush_Color_ComboBox->setCurrentIndex(i);
  }

  for(int i = 0; i < 3; i++)
  {
      if(tempShape.getShape() == i)
          ui->Pen_Join_Style_ComboBox->setCurrentIndex(i);
  }
  for(int i = 0; i < 4; i++)
  {
      if(tempShape.getShape() == i)
          ui->Brush_Style_ComboBox->setCurrentIndex(i);
  }

  for(int i = 0; i < 11; i++)
  {
      if(tempShape.getShape() == i)
          ui->Text_Color_ComboBox->setCurrentIndex(i);
  }

  for(int i = 0; i < 3; i++)
  {
      if(tempShape.getShape() == i)
          ui->Pen_Cap_Style_ComboBox->setCurrentIndex(i);
  }

  for(int i = 0; i < 6; i++)
  {
      if(tempShape.getShape() == i)
          ui->Pen_Style_ComboBox->setCurrentIndex(i);
  }

  for(int i = 0; i < 11; i++)
  {
      if(tempShape.getShape() == i)
          ui->Pen_Color_ComboBox->setCurrentIndex(i);
  }

  for(int i = 0; i < 5; i++)
  {
      if(tempShape.getShape() == i)
          ui->Allignment_ComboBox->setCurrentIndex(i);
  }
  for(int i = 0; i < 3; i++)
  {
      if(tempShape.getShape() == i)
          ui->Font_Style_ComboBox->setCurrentIndex(i);
  }

  for(int i = 0; i < 4; i++)
  {
      if(tempShape.getShape() == i)
          ui->Font_Weight_ComboBox->setCurrentIndex(i);
  }

   ui->Pen_Width_LineEdit->setText(QString::fromStdString(std::to_string(tempShape.get_pen().width())));
   ui->Text_LineEdit->setText(QString::fromStdString(tempShape.get_Text()));
   ui->Text_Point_Size_LineEdit->setText(QString::fromStdString(std::to_string(tempShape.get_Text().size())));
   ui->Font_Family_LineEdit->setText(QString::fromStdString(tempShape.get_FontFamily()));
   ui->perimeter_label->setText(QString::fromStdString(std::to_string(tempShape.get_perimeter())));
   ui->area_label->setText(QString::fromStdString(std::to_string(tempShape.get_perimeter())));
}

