#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) /*!< MainWindow constructor  */
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
/*!<  constructing ui from QWidget parent */
{
    newLogin = new login;
    newLogin->exec();
    if(newLogin->getClosed())
    {
        ui->setupUi(this);
        renderArea = new RenderArea;
        renderArea->setGeometry(0,0,1000,500);
        renderArea->show();
    }
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
    if(newLogin->getAccess())
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
    else QMessageBox::warning(this, "Warning", "Not an Admin");
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
    if(newLogin->getAccess())renderArea->deleteShape(ui->Delete_Shape_ComboBox->currentIndex());
    else QMessageBox::warning(this, "Warning", "Not an Admin");
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
  if(tempShape.get_pen().color() == Qt::black)
      ui->Pen_Color_ComboBox->setCurrentIndex(0);
  else if(tempShape.get_pen().color() == Qt::white)
      ui->Pen_Color_ComboBox->setCurrentIndex(1);
  else if(tempShape.get_pen().color() == Qt::darkGray)
      ui->Pen_Color_ComboBox->setCurrentIndex(2);
  else if(tempShape.get_pen().color() == Qt::gray)
      ui->Pen_Color_ComboBox->setCurrentIndex(3);
  else if(tempShape.get_pen().color() == Qt::lightGray)
      ui->Pen_Color_ComboBox->setCurrentIndex(4);
  else if(tempShape.get_pen().color() == Qt::red)
      ui->Pen_Color_ComboBox->setCurrentIndex(5);
  else if(tempShape.get_pen().color() == Qt::green)
      ui->Pen_Color_ComboBox->setCurrentIndex(6);
  else if(tempShape.get_pen().color() == Qt::blue)
      ui->Pen_Color_ComboBox->setCurrentIndex(7);
  else if(tempShape.get_pen().color() == Qt::cyan)
      ui->Pen_Color_ComboBox->setCurrentIndex(8);
  else if(tempShape.get_pen().color() == Qt::magenta)
      ui->Pen_Color_ComboBox->setCurrentIndex(9);
  else if(tempShape.get_pen().color() == Qt::yellow)
      ui->Pen_Color_ComboBox->setCurrentIndex(10);
  for(int i = 0; i < 6; i++)
  {
      if(tempShape.get_pen().style() == i)
          ui->Pen_Style_ComboBox->setCurrentIndex(i);
  }
  if(tempShape.get_pen().capStyle() == Qt::FlatCap)
      ui->Pen_Cap_Style_ComboBox->setCurrentIndex(0);
  else if(tempShape.get_pen().capStyle() == Qt::SquareCap)
      ui->Pen_Cap_Style_ComboBox->setCurrentIndex(1);
  else if(tempShape.get_pen().capStyle() == Qt::RoundCap)
      ui->Pen_Cap_Style_ComboBox->setCurrentIndex(2);
  if(tempShape.get_pen().joinStyle() == Qt::MiterJoin)
      ui->Pen_Join_Style_ComboBox->setCurrentIndex(0);
  else if(tempShape.get_pen().joinStyle() == Qt::BevelJoin)
      ui->Pen_Join_Style_ComboBox->setCurrentIndex(1);
  else if(tempShape.get_pen().joinStyle() == Qt::RoundJoin)
      ui->Pen_Join_Style_ComboBox->setCurrentIndex(2);
  if(tempShape.get_brush().color() == Qt::black)
      ui->Brush_Color_ComboBox->setCurrentIndex(0);
  else if(tempShape.get_brush().color() == Qt::white)
      ui->Brush_Color_ComboBox->setCurrentIndex(1);
  else if(tempShape.get_brush().color() == Qt::darkGray)
      ui->Brush_Color_ComboBox->setCurrentIndex(2);
  else if(tempShape.get_brush().color() == Qt::gray)
      ui->Brush_Color_ComboBox->setCurrentIndex(3);
  else if(tempShape.get_brush().color() == Qt::lightGray)
      ui->Brush_Color_ComboBox->setCurrentIndex(4);
  else if(tempShape.get_brush().color() == Qt::red)
      ui->Brush_Color_ComboBox->setCurrentIndex(5);
  else if(tempShape.get_brush().color() == Qt::green)
      ui->Brush_Color_ComboBox->setCurrentIndex(6);
  else if(tempShape.get_brush().color() == Qt::blue)
      ui->Brush_Color_ComboBox->setCurrentIndex(7);
  else if(tempShape.get_brush().color() == Qt::cyan)
      ui->Brush_Color_ComboBox->setCurrentIndex(8);
  else if(tempShape.get_brush().color() == Qt::magenta)
      ui->Brush_Color_ComboBox->setCurrentIndex(9);
  else if(tempShape.get_brush().color() == Qt::yellow)
      ui->Brush_Color_ComboBox->setCurrentIndex(10);
  for(int i = 0; i < 11; i++)
  {
      if(tempShape.get_brush().color() == i + 2)
          ui->Brush_Color_ComboBox->setCurrentIndex(i);
  }
  if(tempShape.get_brush().style() == Qt::SolidPattern)
      ui->Brush_Style_ComboBox->setCurrentIndex(0);
  else if(tempShape.get_brush().style() == Qt::HorPattern)
      ui->Brush_Style_ComboBox->setCurrentIndex(1);
  else if(tempShape.get_brush().style() == Qt::VerPattern)
      ui->Brush_Style_ComboBox->setCurrentIndex(2);
  else if(tempShape.get_brush().style() == Qt::NoBrush)
      ui->Brush_Style_ComboBox->setCurrentIndex(3);
  if(tempShape.get_TextColor() == Qt::black)
      ui->Text_Color_ComboBox->setCurrentIndex(0);
  else if(tempShape.get_TextColor() == Qt::white)
      ui->Text_Color_ComboBox->setCurrentIndex(1);
  else if(tempShape.get_TextColor() == Qt::darkGray)
      ui->Text_Color_ComboBox->setCurrentIndex(2);
  else if(tempShape.get_TextColor() == Qt::gray)
      ui->Text_Color_ComboBox->setCurrentIndex(3);
  else if(tempShape.get_TextColor() == Qt::lightGray)
      ui->Text_Color_ComboBox->setCurrentIndex(4);
  else if(tempShape.get_TextColor() == Qt::red)
      ui->Text_Color_ComboBox->setCurrentIndex(5);
  else if(tempShape.get_TextColor() == Qt::green)
      ui->Text_Color_ComboBox->setCurrentIndex(6);
  else if(tempShape.get_TextColor() == Qt::blue)
      ui->Text_Color_ComboBox->setCurrentIndex(7);
  else if(tempShape.get_TextColor() == Qt::cyan)
      ui->Text_Color_ComboBox->setCurrentIndex(8);
  else if(tempShape.get_TextColor() == Qt::magenta)
      ui->Text_Color_ComboBox->setCurrentIndex(9);
  else if(tempShape.get_TextColor() == Qt::yellow)
      ui->Text_Color_ComboBox->setCurrentIndex(10);
  if(tempShape.get_Alignment() == Qt::AlignLeft)
      ui->Allignment_ComboBox->setCurrentIndex(0);
  else if(tempShape.get_Alignment() == Qt::AlignRight)
      ui->Allignment_ComboBox->setCurrentIndex(1);
  else if(tempShape.get_Alignment() == Qt::AlignTop)
      ui->Allignment_ComboBox->setCurrentIndex(2);
  else if(tempShape.get_Alignment() == Qt::AlignBottom)
      ui->Allignment_ComboBox->setCurrentIndex(3);
  else if(tempShape.get_Alignment() == Qt::AlignCenter)
      ui->Allignment_ComboBox->setCurrentIndex(4);
  if(tempShape.get_FontStyle() == QFont::StyleNormal)
      ui->Font_Style_ComboBox->setCurrentIndex(0);
  else if(tempShape.get_FontStyle() == QFont::StyleItalic)
      ui->Font_Style_ComboBox->setCurrentIndex(1);
  else if(tempShape.get_FontStyle() == QFont::StyleOblique)
      ui->Font_Style_ComboBox->setCurrentIndex(2);
  if(tempShape.get_FontWeight() == QFont::Thin)
      ui->Font_Weight_ComboBox->setCurrentIndex(0);
  if(tempShape.get_FontWeight() == QFont::Light)
      ui->Font_Weight_ComboBox->setCurrentIndex(1);
  if(tempShape.get_FontWeight() == QFont::Normal)
      ui->Font_Weight_ComboBox->setCurrentIndex(2);
  if(tempShape.get_FontWeight() == QFont::Bold)
      ui->Font_Weight_ComboBox->setCurrentIndex(3);
   ui->Pen_Width_LineEdit->setText(QString::fromStdString(std::to_string(tempShape.get_pen().width())));
   ui->Text_LineEdit->setText(QString::fromStdString(tempShape.get_Text()));
   ui->Text_Point_Size_LineEdit->setText(QString::fromStdString(std::to_string(tempShape.get_Text().size())));
   ui->Font_Family_LineEdit->setText(QString::fromStdString(tempShape.get_FontFamily()));
   if(tempShape.getShape() == RECTANGLE || tempShape.getShape() == SQUARE || tempShape.getShape() == ELLIPSE || tempShape.getShape() == CIRCLE)
   {
        ui->textEdit->setText(QString::fromStdString(std::to_string(tempShape.get_perimeter())));
        ui->textEdit_2->setText(QString::fromStdString(std::to_string(tempShape.get_area())));
   }
   if(tempShape.getShape() == LINE || tempShape.getShape() == POLYLINE || tempShape.getShape() == POLYGON)
   {
       std::vector<QPoint> tempVec = tempShape.get_points();
       std::vector<QPoint>::iterator first = tempVec.begin();
       std::vector<QPoint>::iterator last = tempVec.end();
       std::string temp = "";
       do{
         temp += std::to_string((*first).x());
         temp += ", ";
         temp += std::to_string((*first).y());
         if(++first != last) temp += ", ";
       }while(first != last);
       ui->Shape_Dim_LineEdit->setText(QString::fromStdString(temp));
   }
   else
   {
       QRect tempRect = tempShape.get_Rect();
       std::string temp = "";
       temp += std::to_string(tempRect.x());
       temp += ", ";
       temp += std::to_string(tempRect.y());
       temp += ", ";
       temp += std::to_string(tempRect.height());
       if(tempShape.getShape() != SQUARE && tempShape.getShape() != CIRCLE)
       {
         temp += ", ";
         temp += std::to_string(tempRect.width());
       }
       ui->Shape_Dim_LineEdit->setText(QString::fromStdString(temp));
   }
}


void MainWindow::on_pushButton_edit_clicked()
{
    if(newLogin->getAccess())
    renderArea->editShape(ui->Delete_Shape_ComboBox->currentIndex() + 1,
                        ui->Shape_Type_Combo_Box->currentIndex(),
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
    else QMessageBox::warning(this, "Warning", "Not an Admin");
}

void MainWindow::on_pushButton_contact_clicked()
{
    contactUs* temp = new contactUs;
    temp->show();
}

void MainWindow::on_pushButton_testim_clicked()
{
    testimonialbox temp;
    temp.exec();
}
