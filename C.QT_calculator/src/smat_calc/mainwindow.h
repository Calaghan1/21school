#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
//#define min.X -1000000
//#define max.X 1000000
extern "C" {
#include "calc_core.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT
  int is_n;
  int dot;
  int dec;
  char str_for_pol[256];
  QString prew_botton;

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  QVector<double> x, y;

 private slots:
  void switch_max_min();
  void input();
  void on_push_botton_dot_clicked();
  void on_push_botton_graph_clicked();
  void on_pushButton_clicked();
  void set_font_1();
  void qstr_to_char(char *str1, QString str2);
};

#endif  // MAINWINDOW_H
