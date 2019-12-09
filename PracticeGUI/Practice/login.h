#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    bool getAccess();
    bool getClosed();
    ~login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::login *ui;
    bool access = false;
    bool closed = false;
};

#endif // LOGIN_H
