#ifndef CONTACTUS_H
#define CONTACTUS_H

#include <QWidget>
#include <QPixmap>

namespace Ui {
class contactUs;
}

class contactUs : public QWidget
{
    Q_OBJECT

public:
    explicit contactUs(QWidget *parent = nullptr);
    ~contactUs();

private:
    Ui::contactUs *ui;
};

#endif // CONTACTUS_H
