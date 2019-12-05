#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QLineEdit>
#include <QMessageBox>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr );
    ~Login();

    bool getLocked();
    bool getLoggedIn();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_userLineEdit_textChanged(const QString &arg1);

    void on_passLineEdit_textChanged(const QString &arg2);

    void on_passLineEdit_returnPressed();

    void on_userLineEdit_returnPressed();



    void on_passLineEdit_selectionChanged();

private:
    Ui::Login *ui;
    QLineEdit* userLineEdit;
    QLineEdit* passLineEdit;
    QString arg1;
    QString arg2;
    static bool locked;
    static bool loggedIn;
    static int attempts;

};

#endif // LOGIN_H
