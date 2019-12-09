#include "testimonialbox.h"
#include "ui_testimonialbox.h"
#include <QDebug>

testimonialbox::testimonialbox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testimonialbox)
{
    ui->setupUi(this);
}

testimonialbox::~testimonialbox()
{
    delete ui;
}

void testimonialbox::on_okbutton_accepted()
{
    QString text = ui->testimonialtext->toPlainText();
    qDebug() << text <<"!!!!!!!";
}
