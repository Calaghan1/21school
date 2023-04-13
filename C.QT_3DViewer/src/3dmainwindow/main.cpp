#include <QApplication>
#include <locale>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QCoreApplication::setOrganizationName("MyProg");
  QCoreApplication::setApplicationName("3dviewer");
  setlocale(LC_ALL, "C");
  MainWindow w;
  w.show();
  return a.exec();
}
