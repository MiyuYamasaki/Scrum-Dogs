#include "formlogin.h"

int FormLogin:: attempts = 0;
const QString databaseU = "user";
const QString databaseP = "pass";

FormLogin::FormLogin(QWidget* parent)
    : QDialog(parent)
{
    setFixedSize(300, 120);
    setWindowTitle("Admin Access");
    setModal(true);
    setAttribute(Qt::WA_DeleteOnClose);

    userLabel = new QLabel("Username:");
    passLabel = new QLabel("Password:");
    userLineEdit = new QLineEdit();
    passLineEdit = new QLineEdit();
    passLineEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Login");
    quitButton = new QPushButton("Quit");

    QVBoxLayout* vbox = new QVBoxLayout(this);
    QHBoxLayout* hbox1 = new QHBoxLayout();
    QHBoxLayout* hbox2 = new QHBoxLayout();
    QHBoxLayout* hbox3 = new QHBoxLayout();

    hbox1->addWidget(userLabel, 1);
    hbox1->addWidget(userLineEdit, 2);
    hbox2->addWidget(passLabel, 1);
    hbox2->addWidget(passLineEdit, 2);
    hbox3->addWidget(loginButton, 1, Qt::AlignRight);
    hbox3->addWidget(quitButton, 0, Qt::AlignRight);

    vbox->addSpacing(1);
    vbox->addLayout(hbox1);
    vbox->addLayout(hbox2);
    vbox->addLayout(hbox3);

    connect(quitButton, SIGNAL(clicked()), this, SLOT(OnQuit()));
    connect(loginButton, SIGNAL(clicked()), this, SLOT(OnLogin()));
}

void FormLogin::reject()
{
    OnQuit();
}

void FormLogin::OnQuit()
{
    this->close();
    parentWidget()->close();
}

void FormLogin::OnLogin()
{

    bool right = false;

do
    {
    QString username = userLineEdit->text();
    QString password = passLineEdit->text();



    if(username == databaseU && password == databaseP)
    {
        right = true;
    }

        else if (!username.isEmpty() && !password.isEmpty())
    {
        QMessageBox::information(this, tr("Hol' Up!"), "Username or password are wrgon!");
    }
    else
        this->destroy();



    if(attempts > 3)
    {
        QMessageBox::information(this, tr("Hol' Up!"), "Too many incorrect attempts!");
        this-> destroy();
    }






    // Checking if username or password is empty
    if (username.isEmpty() || password.isEmpty())
        QMessageBox::information(this, tr("Hol' Up!"), "Username and password fields are empty!");
    else
        this->destroy();

}while(!right || attempts >3);
}


FormLogin::~FormLogin(){}
