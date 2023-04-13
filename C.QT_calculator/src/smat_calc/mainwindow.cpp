#include "mainwindow.h"

#include <QtDebug>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->push_botton_0, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_1, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_2, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_3, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_4, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_5, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_6, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_7, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_8, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_9, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_AC, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_sin, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_cos, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_asin, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_acos, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_tan, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_plus, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_sub, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_mult, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_div, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_mod, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_sqrt, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_eq, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_log, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_ln, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_pow, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_atan, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_end_bracket, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_first_bracet, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_x, SIGNAL(clicked()), this, SLOT(input()));
  connect(ui->push_botton_unary, SIGNAL(clicked()), this, SLOT(input()));
  QDoubleValidator *double_val = new QDoubleValidator(0, 1000000000.0, 2, this);
  QDoubleValidator *double_val_1 =
      new QDoubleValidator(-1000000.0, 1000000000.0, 2, this);
  ui->lineEdit_full_credit->setValidator(double_val);
  ui->lineEdit_full_interest_rate->setValidator(double_val);
  ui->lineEdit_Credit_term->setValidator(double_val);
  ui->lineEdit->setValidator(double_val_1);
  ui->lineEdit_2->setValidator(double_val_1);
  ui->lineEdit_3->setValidator(double_val_1);
  ui->lineEdit_4->setValidator(double_val_1);
}

MainWindow::~MainWindow() { delete ui; }
int flag_for_x = 0;
void MainWindow::input() {
  double s = 0;
  dot = 0;
  ui->lineEdit->setEnabled(false);
  ui->lineEdit_2->setEnabled(false);
  ui->lineEdit_3->setEnabled(false);
  ui->lineEdit_4->setEnabled(false);
  set_font_1();
  QPushButton *button = (QPushButton *)sender();
  if (ui->label->text() == "Enert X value here") {
    ui->label->setText("");
  }
  if (button->text() == "=") {
    if (!flag_for_x) {
      ui->after_eq->setText(ui->label->text());
    }
    if (ui->label->text().contains('x')) {
      flag_for_x = 1;
      ui->label->setText("Enert X value here");
    } else {
      char str1[256] = {'\0'};
      qstr_to_char(str1, ui->label->text());
      char token[256] = {'\0'};
      if (find_token(str1, token)) {
        clean_str(str1);
        To_Polish(token, str1);
        double res = calc_resutl(str1, s);
        if (isnan(res) || !isfinite(res)) {
          ui->label->setText("Error");
        } else {
          if (flag_for_x) {
            flag_for_x = 0;
            double buf = res;
            clean_str(str1);
            clean_str(token);
            qstr_to_char(str1, ui->after_eq->text());
            if (find_token(str1, token)) {
              clean_str(str1);
              To_Polish(token, str1);
              res = calc_resutl(str1, buf);
              clean_str(str1);
              double_to_str(res, str1);
              ui->label->setText(str1);
            }
          } else {
            clean_str(str1);
            double_to_str(res, str1);
            ui->label->setText(str1);
          }
        }
      } else {
        ui->label->setText("Error");
      }
    }
  } else {
    QString str;
    QString str1;
    if (button->text() == "+/-") {
      is_n++;
      if (is_n % 2 == 0) {
        str = prew_botton;
      } else {
        str = ("-(" + ui->label->text() + ")");
        prew_botton = ui->label->text();
      }
    } else {
      is_n = 0;
      str = (ui->label->text() + button->text());
      if (button->text() == "AC") {
        x.clear();
        y.clear();
        ui->widget->clearGraphs();
        str = "";
        ui->after_eq->setText(str);
      }
    }
    ui->label->setText(str);
  }
}

void MainWindow::qstr_to_char(char *str1, QString str2) {
  const char *str;
  str = str2.toStdString().c_str();
  for (int i = 0; i < str2.length(); i++) {
    str1[i] = str[i];
  }
}

void MainWindow::on_push_botton_dot_clicked() {
  dot++;
  if (dot < 2 && ui->label->text().length() > 0) {
    ui->label->setText(ui->label->text() + '.');
  }
}

void MainWindow::on_push_botton_graph_clicked() {
  x.clear();
  y.clear();
  ui->widget->clearGraphs();
  switch_max_min();
  ui->widget->xAxis->setRange(ui->lineEdit->text().toDouble(),
                              ui->lineEdit_2->text().toDouble());
  ui->widget->yAxis->setRange(ui->lineEdit_3->text().toDouble(),
                              ui->lineEdit_4->text().toDouble());
  double X = ui->lineEdit->text().toDouble();
  double max_X = ui->lineEdit_2->text().toDouble();
  double Y = ui->lineEdit_4->text().toDouble();
  double max_Y = ui->lineEdit_3->text().toDouble();
  if (max_X >= X && max_Y >= Y) {
    double h = 0.0001;
    double N = (max_X - X) / h;
    while (N > 5000000) {
      h *= 1.2;
      N = (max_X - X) / h;
    }
    int graph_n = 0;
    printf("H = %lf\n", h);
    QString myString = ui->label->text();
    const char *str;
    char str1[256] = {'\0'};
    str = ui->label->text().toStdString().c_str();
    for (int i = 0; i < myString.length(); i++) {
      str1[i] = str[i];
    }
    double res = 0;
    char token[256] = {'\0'};
    find_token(str1, token);
    clean_str(str1);
    To_Polish(token, str1);
    while (X <= max_X) {
      for (; X <= max_X; X += h) {
        /*                if (fabs(fabs(X) - (M_PI_2 + M_PI * k)) < 1e-4) {

                            k++;
                               if ( X > 0 ) {
                                  res = calc_resutl(str1, M_PI_2);
                               } else {
                                   res = calc_resutl(str1, -M_PI_2);
                               }
                           } else */
        if (fabs(X) < 1e-6) {
          res = calc_resutl(str1, 0);
        } else {
          res = calc_resutl(str1, X);
        }
        if (isnan(res) || !isfinite(res)) {
          while ((isnan(res) || !isfinite(res)) && X < max_X) {
            X += h;
            res = calc_resutl(str1, X);
          }
          break;
        } else {
          x.push_back(X);
          y.push_back(res);
        }
      }

      //               if (mul_h > 0) {
      //                   X += mul_h;
      //               } else {
      //                  X += h;
      //               }
      ui->widget->addGraph();
      ui->widget->graph(graph_n)->addData(x, y);
      graph_n++;
      //               printf("GRAPH_N %d\n", graph_n);

      x.clear();
      y.clear();
    }

  } else {
    ui->label->setText("Error");
  }
  ui->widget->replot();
}

void MainWindow::switch_max_min() {
  ui->lineEdit->setEnabled(true);
  ui->lineEdit_2->setEnabled(true);
  ui->lineEdit_3->setEnabled(true);
  ui->lineEdit_4->setEnabled(true);
}

void MainWindow::on_pushButton_clicked() {
  double K, P, PS, M, RES;
  RES = 0;
  char str[256];
  clean_str(str);
  K = ui->lineEdit_full_credit->text().toDouble();
  M = ui->lineEdit_Credit_term->text().toDouble();
  P = ui->lineEdit_full_interest_rate->text().toDouble();
  if (ui->Annu->isChecked()) {
    PS = P / 12 / 100;
    RES = K * PS * pow((1 + PS), M) / (pow((1 + PS), M) - 1);
    RES *= 100;
    RES = round(RES);
    RES /= 100;
    sprintf(str, "%.2lf", RES);
    ui->Monthly_payment->setText(str);
    RES *= M;
    sprintf(str, "%.2lf", RES);
    ui->Debt_interest->setText(str);
    RES -= K;
    sprintf(str, "%.2lf", RES);
    ui->Interest_charges->setText(str);
  } else {
    double MP = K / M;
    PS = P / 1200;
    double First_month = MP + (K)*PS;
    double last_month = MP + (K - MP * (M - 1)) * PS;
    int k = M;
    for (int i = 0; i < k; i++) {
      RES += MP + (K - MP * i) * PS;
    }
    sprintf(str, "%.2lf", RES);
    ui->Debt_interest->setText(str);
    sprintf(str, "%.2lf...%.2lf", First_month, last_month);
    ui->Monthly_payment->setText(str);
    RES -= K;
    sprintf(str, "%.2lf", RES);
    ui->Interest_charges->setText(str);
  }
}

void MainWindow::set_font_1() {
  QFont font = ui->label->font();
  int len = ui->label->text().length();
  if (len >= 0 && len <= 15) {
    font.setPointSize(30);
  } else if ((len >= 15 && len <= 20)) {
    font.setPointSize(25);
  } else if (len >= 20 && len <= 30) {
    font.setPointSize(20);
  } else if (len >= 30 && len <= 40) {
    font.setPointSize(15);
  } else if (len >= 40 && len <= 50) {
    font.setPointSize(10);
  }
  ui->label->setFont(font);
}
