#ifndef FORMLOGIN_H
#define FORMLOGIN_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class FormLogin : public QDialog
{
    Q_OBJECT

public:
    FormLogin(QWidget* parent = nullptr);
    ~FormLogin();

private slots:
    void OnQuit();
    void OnLogin();


private:
    void reject();
static int attempts;

    QLabel* userLabel;
    QLabel* passLabel;
    QLineEdit* userLineEdit;
    QLineEdit* passLineEdit;
    QPushButton* loginButton;
    QPushButton* quitButton;
};


#endif // FORMLOGIN_H
