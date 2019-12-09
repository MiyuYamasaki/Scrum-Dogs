#include "contactus.h"
#include "ui_contactus.h"

contactUs::contactUs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::contactUs)
{
    ui->setupUi(this);
    QPixmap pm("image0.jpg"); // <- path to image file
    ui->Picture->setPixmap(pm);
    ui->Picture->setScaledContents(true);
}

contactUs::~contactUs()
{
    delete ui;
}
