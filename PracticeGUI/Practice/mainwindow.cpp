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
    if(!(newLogin->getClosed())) newLogin->exec();
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
void MainWindow::displayIdReport(vector<gProject::shapes>* temp, int sort)
 {
     int row = 0;

     QWidget* tableDialog = new QWidget();
     QTableWidget* table = new QTableWidget(13,19,tableDialog);
     vector<gProject::shapes>::iterator first = temp->begin();
     vector<gProject::shapes>::iterator last = temp->end();

 do{
   /////////////////////////////////////////////////////////////////////////////////
     QTableWidgetItem *iD = new QTableWidgetItem(first->get_ID());
     QTableWidgetItem *shapeType = new QTableWidgetItem(first->getShape());

     std::string tempCoor = "";
     if(first->getShape() == LINE || first->getShape() == POLYLINE || first->getShape() == POLYGON || first->getShape() == TEXT)
     {
         std::vector<QPoint> tempPointsVec = first->get_points();
         std::vector<QPoint>::iterator firstCoor = tempPointsVec.begin();
         std::vector<QPoint>::iterator lastCoor = tempPointsVec.end();
         do
         {
             tempCoor += "(";
             tempCoor += std::to_string(firstCoor->x());
             tempCoor += ",";
             tempCoor += std::to_string(firstCoor->y());
             tempCoor += ") ";
             ++firstCoor;
         }while(firstCoor != lastCoor);
     }
     else
     {
         tempCoor += "(";
         tempCoor += std::to_string(first->get_Rect().x());
         tempCoor += ",";
         tempCoor += std::to_string(first->get_Rect().y());
         tempCoor += ") ";
     }

     QTableWidgetItem *coordinates = new QTableWidgetItem(QString::fromStdString(tempCoor));

     std::string tempAlign;
     if(first->get_Alignment() == Qt::AlignLeft)
     {
         tempAlign = "Align Left";
     }
     else if(first->get_Alignment() == Qt::AlignRight)
     {
         tempAlign = "Align Right";
     }
     else if(first->get_Alignment() == Qt::AlignTop)
     {
         tempAlign = "Align Top";
     }
     else if(first->get_Alignment() == Qt::AlignBottom)
     {
         tempAlign = "Align Bottom";
     }
     else if(first->get_Alignment() == Qt::AlignCenter)
     {
         tempAlign = "Align Center";
     }
     QTableWidgetItem *allignment = new QTableWidgetItem(QString::fromStdString(tempAlign));

     QTableWidgetItem *text = new QTableWidgetItem(QString::fromStdString(first->get_Text()));
     QTableWidgetItem *ptSize = new QTableWidgetItem(QString::number(first->get_PointSize()));

     std::string tempTextColor;
     if(first->get_TextColor() == Qt::GlobalColor::red)
     {
         tempTextColor = "red";
     }
     else if(first->get_TextColor() == Qt::GlobalColor::black)
     {
         tempTextColor = "black";
     }
     else if(first->get_TextColor() == Qt::GlobalColor::white)
     {
         tempTextColor = "white";
     }
     else if(first->get_TextColor() == Qt::GlobalColor::darkGray)
     {
         tempTextColor = "dark gray";
     }
     else if(first->get_TextColor() == Qt::GlobalColor::gray)
     {
         tempTextColor = "gray";
     }
     else if(first->get_TextColor() == Qt::GlobalColor::lightGray)
     {
         tempTextColor = "light gray";
     }
     else if(first->get_TextColor() == Qt::GlobalColor::green)
     {
         tempTextColor = "greeen";
     }
     else if(first->get_TextColor() == Qt::GlobalColor::blue)
     {
         tempTextColor = "blue";
     }
     else if(first->get_TextColor() == Qt::GlobalColor::cyan)
     {
         tempTextColor = "cyan";
     }
     else if(first->get_TextColor() == Qt::GlobalColor::magenta)
     {
         tempTextColor = "magenta";
     }
     else if(first->get_TextColor() == Qt::GlobalColor::yellow)
     {
         tempTextColor = "yellow";
     }

     QTableWidgetItem *textColor = new QTableWidgetItem(QString::fromStdString(tempTextColor));

     std::string tempFontStyle;
     if(first->get_FontStyle() == QFont::Style::StyleNormal)
     {
         tempFontStyle = "Style Normal";
     }
     else if(first->get_FontStyle() == QFont::Style::StyleItalic)
     {
         tempFontStyle = "Style Italic";
     }
     else if(first->get_FontStyle() == QFont::Style::StyleOblique)
     {
         tempFontStyle = "Style Oblique";
     }
      QTableWidgetItem *fontStyle = new QTableWidgetItem(QString::fromStdString(tempFontStyle));

      std::string fontWeight;
      if(first->get_FontWeight() == QFont::Weight::Bold)
      {
          fontWeight = "Bold";
      }
      else if(first->get_FontWeight() == QFont::Weight::Thin)
      {
          fontWeight = "Thin";
      }
      else if(first->get_FontWeight() == QFont::Weight::Light)
      {
          fontWeight = "Light";
      }
      else if(first->get_FontWeight() == QFont::Weight::Normal)
      {
          fontWeight = "Normal";
      }

      QTableWidgetItem *fontWeightItem = new QTableWidgetItem(QString::fromStdString(fontWeight));

      QTableWidgetItem *fontFamily = new QTableWidgetItem(QString::fromStdString(first->get_FontFamily()));

      std::string penCap;
      if(first->get_pen().capStyle() ==  Qt::PenCapStyle::FlatCap)
      {
         penCap = "Flat Cap";
      }
      else if(first->get_pen().capStyle() ==  Qt::PenCapStyle::SquareCap)
      {
          penCap = "Square Cap";
      }
      else if(first->get_pen().capStyle() ==  Qt::PenCapStyle::RoundCap)
      {
          penCap = "Round Cap";
      }
      QTableWidgetItem *penCapStyle = new QTableWidgetItem(QString::fromStdString(penCap));

      std::string penJoin;
      if(first->get_pen().joinStyle() == Qt::PenJoinStyle::MiterJoin)
      {
          penJoin = "Milter Join";
      }
      else if(first->get_pen().joinStyle() == Qt::PenJoinStyle::BevelJoin)
      {
          penJoin = "Bevel Join";
      }
      else if(first->get_pen().joinStyle() == Qt::PenJoinStyle::RoundJoin)
      {
          penJoin = "Round Join";
      }

      QTableWidgetItem *penJoinStyle = new QTableWidgetItem(QString::fromStdString(penJoin));

      std::string penStyle;
      if(first->get_pen().style() == Qt::PenStyle::SolidLine)
      {
          penStyle = "Solid Line";
      }
      else if(first->get_pen().style() == Qt::PenStyle::NoPen)
      {
          penStyle = "No Pen";
      }
      else if(first->get_pen().style() == Qt::PenStyle::DashLine)
      {
          penStyle = "Dash Line";
      }
      else if(first->get_pen().style() == Qt::PenStyle::DotLine)
      {
          penStyle = "Dot Line";
      }
      else if(first->get_pen().style() == Qt::PenStyle::DashDotLine)
      {
          penStyle = "Dash Dot Line";
      }
      else if(first->get_pen().style() == Qt::PenStyle::DashDotDotLine)
      {
          penStyle = "Dash Dot Dot Line";
      }
      QTableWidgetItem *penStyleItem = new QTableWidgetItem(QString::fromStdString(penStyle));

      std::string penColor;
      if(first->get_pen().color() == Qt::GlobalColor::gray)
      {
          penColor = "Gray";
      }
      else if(first->get_pen().color() == Qt::GlobalColor::black)
      {
          penColor = "Black";
      }
      else if(first->get_pen().color() == Qt::GlobalColor::white)
      {
          penColor = "White";
      }
      else if(first->get_pen().color() == Qt::GlobalColor::darkGray)
      {
          penColor = "Dark Gray";
      }
      else if(first->get_pen().color() == Qt::GlobalColor::lightGray)
      {
          penColor = "Light Gray";
      }
      else if(first->get_pen().color() == Qt::GlobalColor::red)
      {
          penColor = "Red";
      }
      else if(first->get_pen().color() == Qt::GlobalColor::green)
      {
          penColor = "Green";
      }
      else if(first->get_pen().color() == Qt::GlobalColor::blue)
      {
          penColor = "Blue";
      }
      else if(first->get_pen().color() == Qt::GlobalColor::cyan)
      {
          penColor = "Cyan";
      }
      else if(first->get_pen().color() == Qt::GlobalColor::magenta)
      {
          penColor = "Magenta";
      }
      else if(first->get_pen().color() == Qt::GlobalColor::yellow)
      {
          penColor = "Yellow";
      }
      QTableWidgetItem *penColorItem = new QTableWidgetItem(QString::fromStdString(penColor));

      QTableWidgetItem *penWidth = new QTableWidgetItem(QString::number(first->get_pen().width()));

      std::string brushColor;

      if(first->get_brush().color() == Qt::GlobalColor::yellow)
      {
          brushColor = "Yellow";
      }
      else if(first->get_brush().color() == Qt::GlobalColor::black)
      {
          brushColor = "Black";
      }
      else if(first->get_brush().color() == Qt::GlobalColor::white)
      {
          brushColor = "White";
      }
      else if(first->get_brush().color() == Qt::GlobalColor::darkGray)
      {
          brushColor = "Dark Gray";
      }
      else if(first->get_brush().color() == Qt::GlobalColor::gray)
      {
          brushColor = "Gray";
      }
      else if(first->get_brush().color() == Qt::GlobalColor::lightGray)
      {
          brushColor = "Light Gray";
      }
      else if(first->get_brush().color() == Qt::GlobalColor::red)
      {
          brushColor = "Red";
      }
      else if(first->get_brush().color() == Qt::GlobalColor::green)
      {
          brushColor = "Green";
      }
      else if(first->get_brush().color() == Qt::GlobalColor::blue)
      {
          brushColor = "Blue";
      }
      else if(first->get_brush().color() == Qt::GlobalColor::cyan)
      {
          brushColor = "Cyan";
      }
      else if(first->get_brush().color() == Qt::GlobalColor::magenta)
      {
          brushColor = "Magenta";
      }
      QTableWidgetItem *brushColorItem = new QTableWidgetItem(QString::fromStdString(brushColor));

      std::string brushStyle;
      if(first->get_brush().style() == Qt::BrushStyle::SolidPattern)
      {
         brushStyle = "Solid Pattern";
      }
      else if(first->get_brush().style() == Qt::BrushStyle::HorPattern)
      {
          brushStyle = "Hor Pattern";
      }
      else if(first->get_brush().style() == Qt::BrushStyle::VerPattern)
      {
          brushStyle = "Ver Pattern";
      }
      else if(first->get_brush().style() == Qt::BrushStyle::NoBrush)
      {
          brushStyle = "No Brush";
      }
      QTableWidgetItem *brushStyleItem = new QTableWidgetItem(QString::fromStdString(brushStyle));

      QTableWidgetItem *area = new QTableWidgetItem(QString::number(first->get_area()));

      QTableWidgetItem *perimeter = new QTableWidgetItem(QString::number(first->get_perimeter()));


    //////////////////////////////////////////////////////////////////////////////////

    table->setItem(row,0, iD);
    iD->setText(QString::number(first->get_ID()));

    table->setItem(row, 1, shapeType);
    if(first->getShape() == 0)
    {
       shapeType->setText("Line");
    }
    else if(first->getShape() == 1)
    {
        shapeType->setText("Polyline");
    }
    else if(first->getShape() == 2)
    {
        shapeType->setText("Polygon");
    }
    else if(first->getShape() == 3)
    {
        shapeType->setText("Rectangle");
    }
    else if(first->getShape() == 4)
    {
        shapeType->setText("Square");
    }
    else if(first->getShape() == 5)
    {
        shapeType->setText("Ellipse");
    }
    else if(first->getShape() == 6)
    {
        shapeType->setText("Circle");
    }
    else if(first->getShape() == 7)
    {
        shapeType->setText("Text");
    }


    table->setItem(row,2, coordinates);
    coordinates->setText(QString::fromStdString(tempCoor));

    table->setItem(row,3,allignment);
    allignment->setText(QString::fromStdString(tempAlign));

    table->setItem(row,4, text);
    text->setText(QString::fromStdString(first->get_Text()));

    table->setItem(row,5,ptSize);
    ptSize->setText(QString::number(first->get_PointSize()));

    table->setItem(row, 6, textColor);
    textColor->setText(QString::fromStdString(tempTextColor));

    table->setItem(row, 7, fontStyle);
    fontStyle->setText(QString::fromStdString(tempFontStyle));

    table->setItem(row, 8, fontWeightItem);
    fontWeightItem->setText(QString::fromStdString(fontWeight));

    table->setItem(row,9,fontFamily);
    fontFamily->setText(QString::fromStdString(first->get_FontFamily()));

    table->setItem(row,10, penCapStyle);
    penCapStyle->setText(QString::fromStdString(penCap));

    table->setItem(row, 11, penJoinStyle);
    penJoinStyle->setText(QString::fromStdString(penJoin));

    table->setItem(row,12, penStyleItem);
    penStyleItem->setText(QString::fromStdString(penStyle));

    table->setItem(row,13, penColorItem);
    penColorItem->setText(QString::fromStdString(penColor));

    table->setItem(row,14, penWidth);
    penWidth->setText(QString::number(first->get_pen().width()));

    table->setItem(row,15, brushColorItem);
    brushColorItem->setText(QString::fromStdString(brushColor));

    table->setItem(row,16, brushStyleItem);
    brushStyleItem->setText(QString::fromStdString(brushStyle));

    table->setItem(row, 17, area);
    area->setText(QString::number(first->get_area()));

    table->setItem(row, 18, perimeter);
    perimeter->setText(QString::number(first->get_perimeter()));
/////////////////////////////////////////////////////////////////////
    row += 1;
    ++first;

 }while(first != last);




     table->resize(1500, 800);

     if(sort == 0)
     {
     table->sortByColumn(0, Qt::AscendingOrder);
    }
     else if(sort == 1)
     {
       table->sortByColumn(17, Qt::AscendingOrder);
     }
     else if(sort == 2)
     {
       table->sortByColumn(18, Qt::AscendingOrder);
     }

     //table->resizeColumnsToContents();
     tableDialog->show();
     //table->show();



 }

void MainWindow::on_Reports_Id_clicked()
{
   displayIdReport(renderArea->getSList(), 0);
}

void MainWindow::on_Reports_Area_clicked()
{
     displayIdReport(renderArea->getSList(), 1);
}

void MainWindow::on_Reports_Peri_clicked()
{
 displayIdReport(renderArea->getSList(), 2);
}
