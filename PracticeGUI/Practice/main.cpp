#include "mainwindow.h"
#include "renderarea.h"
#include "window.h"

#include <QApplication>
//! main */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //!< a object */
    MainWindow w;
    w.show();
    return a.exec();		//!< returning drawing*/
}
