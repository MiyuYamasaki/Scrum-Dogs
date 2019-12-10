#include "testimonialbox.h"
#include "ui_testimonialbox.h"
#include <QDebug>
#include <fstream>

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

void testimonialbox::on_pushButton_clicked()
{
    std::string s = ui->lineEdit->text().toLocal8Bit().constData();
    std::string s2 = ui->lineEdit_2->text().toLocal8Bit().constData();

    std::ofstream fout("testimony.txt");
    fout << s << " - " << s2;
    close();
}
