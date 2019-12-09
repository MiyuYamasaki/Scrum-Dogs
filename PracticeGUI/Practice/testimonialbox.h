#ifndef TESTIMONIALBOX_H
#define TESTIMONIALBOX_H

#include <QDialog>

namespace Ui {
class testimonialbox;
}

class testimonialbox : public QDialog
{
    Q_OBJECT

public:
    explicit testimonialbox(QWidget *parent = nullptr);
    ~testimonialbox();

//    testimonialbox* uiPtr() {return ui;}

private slots:
    void on_okbutton_accepted();

private:
    Ui::testimonialbox *ui;
};

#endif // TESTIMONIALBOX_H
