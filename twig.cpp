#include "ui/mainwindow.h"

#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtWidgets/QApplication>

void setStylesheet()
{
    QFile f(":qdarkstyle/style.qss");
    f.open(QFile::ReadOnly | QFile::Text);
    QTextStream ts(&f);
    qApp->setStyleSheet(ts.readAll());
    f.close();
}

void setIcon()
{
    QIcon appIcon;
    // bazel build
    appIcon.addFile(":res/images/twig.ico");
    // cmake build
    appIcon.addFile(":images/axe.ico");
    QApplication::setWindowIcon(appIcon);
}

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    setIcon();
    setStylesheet();

    Twig::MainWindow m;
    if (argc == 2)
    {
        m.LoadFile(QString(argv[1]));
    }
    m.show();

    return QApplication::exec();
}
