#include "Login.h"
#include "formlogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Login* login = new Login();
    //FormLogin* formLogin = new FormLogin(Login);
    //formLogin->show();
     login->show();



    return a.exec();
}
