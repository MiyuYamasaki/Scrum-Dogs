#include "Login.h"
#include "ui_Login.h"

bool Login::loggedIn = false;
bool Login::locked = false;
int Login::attempts = 0;


Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    if(locked)
    {
        QMessageBox::information(this,tr("Locked Out"), "Account it Locked");
                this->destroy();
    }
    setMinimumSize(800,600);
    ui->setupUi(this);
    userLineEdit = new QLineEdit();
    passLineEdit = new QLineEdit();

}

Login::~Login()
{
    delete userLineEdit;
    delete passLineEdit;
    delete ui;
}

bool Login::getLocked()
{
    return locked;
}
bool Login::getLoggedIn()
{
    return loggedIn;
}

void Login::on_pushButton_clicked()
{
    QString username = userLineEdit->text();
    QString password = passLineEdit->text();


    if(!locked)
    {
    if(username == "user" && password == "pass")
    {
        QMessageBox::information(this, tr("Hol' Up!"), "Got 'em in one!");
        loggedIn = true;
        this->destroy();


    }
    else if (username.isEmpty() || password.isEmpty())
        QMessageBox::information(this, tr("Hol' Up!"), "Username and password fields are empty!");
    else
    {
        QMessageBox::information(this, tr("Hol' Up!"), "The Username or password are wrong!");
        (this->attempts)++;
    }
    }
if(this->attempts >= 3)
{
    QMessageBox::information(this, tr("Hol' Up!"), "Too many incorrect attempts!");
    locked = true;
    this->destroy();

}


}

void Login::on_pushButton_2_clicked()
{
    this->destroy();
}

void Login::on_userLineEdit_textChanged(const QString & arg1)
{
    userLineEdit->setText(arg1);


}

void Login::on_passLineEdit_textChanged(const QString &arg2)
{
    passLineEdit->setText(arg2);

}

void Login::on_userLineEdit_returnPressed()
{
 on_passLineEdit_selectionChanged();
}

void Login::on_passLineEdit_returnPressed()
{
    on_pushButton_clicked();
}


void Login::on_passLineEdit_selectionChanged()
{

}
