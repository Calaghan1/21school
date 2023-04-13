/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

#include "oglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget *centralwidget;
  OGLWidget *widget;
  QPushButton *gif_button;
  QPushButton *pushButton;
  QLabel *label;
  QLabel *label_2;
  QPushButton *scale_plus;
  QPushButton *scale_sub;
  QPushButton *muving_left;
  QPushButton *muving_up;
  QPushButton *muving_right;
  QPushButton *muving_down;
  QPushButton *rotation_y_left;
  QPushButton *rotation_y_right;
  QPushButton *rotation_x_down;
  QPushButton *rotation_x_push;
  QPushButton *rotation_z_left;
  QPushButton *rotation_z_right;
  QSpinBox *z_right;
  QLabel *label_15;
  QLabel *label_16;
  QLabel *label_17;
  QSpinBox *x_right;
  QSpinBox *y_right;
  QLabel *label_18;
  QSpinBox *sdvig;
  QLabel *label_19;
  QSpinBox *masht;
  QLabel *label_20;
  QLabel *vershina;
  QLabel *poligon;
  QLabel *label_21;
  QLabel *label_vershina;
  QLabel *label_poligon;
  QGroupBox *groupBox;
  QRadioButton *radio_stipple;
  QRadioButton *radio_whole;
  QSpinBox *size_ribs;
  QLabel *label_vershina_3;
  QGroupBox *groupBox_2;
  QRadioButton *radio_no_show;
  QRadioButton *radio_krug;
  QRadioButton *radio_kvadrat;
  QSpinBox *size_peaks;
  QLabel *label_vershina_2;
  QGroupBox *groupBox_3;
  QSpinBox *peaks_color_r;
  QSpinBox *peaks_color_g;
  QSpinBox *peaks_color_b;
  QLabel *label_23;
  QLabel *label_24;
  QLabel *label_22;
  QGroupBox *groupBox_4;
  QSpinBox *ribs_color_r;
  QSpinBox *ribs_color_g;
  QSpinBox *ribs_color_b;
  QLabel *label_25;
  QLabel *label_26;
  QLabel *label_27;
  QGroupBox *groupBox_5;
  QSpinBox *fon_color_r;
  QSpinBox *fon_color_g;
  QSpinBox *fon_color_b;
  QLabel *label_28;
  QLabel *label_29;
  QLabel *label_30;
  QPushButton *change_perspective;
  QPushButton *pushButton_2;
  QPushButton *pushButton_3;
  QPushButton *pushButton_4;
  QMenuBar *menubar;
  QStatusBar *statusbar;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->setWindowModality(Qt::ApplicationModal);
    MainWindow->setEnabled(true);
    MainWindow->resize(1650, 820);
    MainWindow->setMinimumSize(QSize(1650, 820));
    MainWindow->setMaximumSize(QSize(1650, 820));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    widget = new OGLWidget(centralwidget);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(10, -20, 1200, 700));
    gif_button = new QPushButton(widget);
    gif_button->setObjectName(QString::fromUtf8("gif_button"));
    gif_button->setGeometry(QRect(1090, 650, 100, 32));
    pushButton = new QPushButton(centralwidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(542, 740, 116, 32));
    QFont font;
    font.setPointSize(18);
    pushButton->setFont(font);
    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(250, 700, 700, 20));
    label->setAlignment(Qt::AlignCenter);
    label_2 = new QLabel(centralwidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(1340, 40, 180, 20));
    label_2->setFont(font);
    label_2->setAlignment(Qt::AlignCenter);
    scale_plus = new QPushButton(centralwidget);
    scale_plus->setObjectName(QString::fromUtf8("scale_plus"));
    scale_plus->setGeometry(QRect(1460, 160, 60, 32));
    scale_sub = new QPushButton(centralwidget);
    scale_sub->setObjectName(QString::fromUtf8("scale_sub"));
    scale_sub->setGeometry(QRect(1340, 160, 60, 32));
    muving_left = new QPushButton(centralwidget);
    muving_left->setObjectName(QString::fromUtf8("muving_left"));
    muving_left->setGeometry(QRect(1300, 370, 100, 32));
    muving_up = new QPushButton(centralwidget);
    muving_up->setObjectName(QString::fromUtf8("muving_up"));
    muving_up->setGeometry(QRect(1380, 340, 100, 32));
    muving_right = new QPushButton(centralwidget);
    muving_right->setObjectName(QString::fromUtf8("muving_right"));
    muving_right->setGeometry(QRect(1460, 370, 100, 32));
    muving_down = new QPushButton(centralwidget);
    muving_down->setObjectName(QString::fromUtf8("muving_down"));
    muving_down->setGeometry(QRect(1380, 400, 100, 32));
    rotation_y_left = new QPushButton(centralwidget);
    rotation_y_left->setObjectName(QString::fromUtf8("rotation_y_left"));
    rotation_y_left->setGeometry(QRect(1340, 250, 60, 32));
    rotation_y_right = new QPushButton(centralwidget);
    rotation_y_right->setObjectName(QString::fromUtf8("rotation_y_right"));
    rotation_y_right->setGeometry(QRect(1460, 250, 60, 32));
    rotation_x_down = new QPushButton(centralwidget);
    rotation_x_down->setObjectName(QString::fromUtf8("rotation_x_down"));
    rotation_x_down->setGeometry(QRect(1340, 220, 60, 32));
    QFont font1;
    font1.setPointSize(13);
    rotation_x_down->setFont(font1);
    rotation_x_push = new QPushButton(centralwidget);
    rotation_x_push->setObjectName(QString::fromUtf8("rotation_x_push"));
    rotation_x_push->setGeometry(QRect(1460, 220, 60, 32));
    rotation_z_left = new QPushButton(centralwidget);
    rotation_z_left->setObjectName(QString::fromUtf8("rotation_z_left"));
    rotation_z_left->setGeometry(QRect(1340, 280, 60, 32));
    rotation_z_right = new QPushButton(centralwidget);
    rotation_z_right->setObjectName(QString::fromUtf8("rotation_z_right"));
    rotation_z_right->setGeometry(QRect(1460, 280, 60, 32));
    z_right = new QSpinBox(centralwidget);
    z_right->setObjectName(QString::fromUtf8("z_right"));
    z_right->setGeometry(QRect(1400, 283, 60, 22));
    z_right->setMinimum(1);
    z_right->setMaximum(360);
    label_15 = new QLabel(centralwidget);
    label_15->setObjectName(QString::fromUtf8("label_15"));
    label_15->setGeometry(QRect(1318, 280, 22, 32));
    label_15->setMinimumSize(QSize(22, 32));
    label_15->setMaximumSize(QSize(22, 32));
    QFont font2;
    font2.setPointSize(20);
    font2.setBold(true);
    label_15->setFont(font2);
    label_15->setStyleSheet(QString::fromUtf8(""));
    label_15->setAlignment(Qt::AlignCenter);
    label_16 = new QLabel(centralwidget);
    label_16->setObjectName(QString::fromUtf8("label_16"));
    label_16->setGeometry(QRect(1318, 220, 22, 32));
    label_16->setMinimumSize(QSize(22, 32));
    label_16->setMaximumSize(QSize(22, 32));
    label_16->setFont(font2);
    label_16->setStyleSheet(QString::fromUtf8(""));
    label_16->setAlignment(Qt::AlignCenter);
    label_17 = new QLabel(centralwidget);
    label_17->setObjectName(QString::fromUtf8("label_17"));
    label_17->setGeometry(QRect(1318, 250, 22, 32));
    label_17->setMinimumSize(QSize(22, 32));
    label_17->setMaximumSize(QSize(22, 32));
    label_17->setFont(font2);
    label_17->setStyleSheet(QString::fromUtf8(""));
    label_17->setAlignment(Qt::AlignCenter);
    x_right = new QSpinBox(centralwidget);
    x_right->setObjectName(QString::fromUtf8("x_right"));
    x_right->setGeometry(QRect(1400, 223, 60, 22));
    x_right->setMinimum(1);
    x_right->setMaximum(360);
    y_right = new QSpinBox(centralwidget);
    y_right->setObjectName(QString::fromUtf8("y_right"));
    y_right->setGeometry(QRect(1400, 253, 60, 22));
    y_right->setMinimum(1);
    y_right->setMaximum(360);
    label_18 = new QLabel(centralwidget);
    label_18->setObjectName(QString::fromUtf8("label_18"));
    label_18->setGeometry(QRect(1340, 307, 180, 32));
    label_18->setMinimumSize(QSize(180, 32));
    label_18->setMaximumSize(QSize(180, 32));
    label_18->setFont(font2);
    label_18->setStyleSheet(QString::fromUtf8(""));
    label_18->setAlignment(Qt::AlignCenter);
    sdvig = new QSpinBox(centralwidget);
    sdvig->setObjectName(QString::fromUtf8("sdvig"));
    sdvig->setGeometry(QRect(1400, 373, 60, 22));
    sdvig->setMinimum(1);
    sdvig->setMaximum(10);
    label_19 = new QLabel(centralwidget);
    label_19->setObjectName(QString::fromUtf8("label_19"));
    label_19->setGeometry(QRect(1340, 127, 180, 32));
    label_19->setMinimumSize(QSize(180, 32));
    label_19->setMaximumSize(QSize(180, 32));
    label_19->setFont(font2);
    label_19->setStyleSheet(QString::fromUtf8(""));
    label_19->setAlignment(Qt::AlignCenter);
    masht = new QSpinBox(centralwidget);
    masht->setObjectName(QString::fromUtf8("masht"));
    masht->setGeometry(QRect(1400, 163, 60, 22));
    masht->setMinimum(1);
    masht->setMaximum(10);
    label_20 = new QLabel(centralwidget);
    label_20->setObjectName(QString::fromUtf8("label_20"));
    label_20->setGeometry(QRect(1340, 187, 180, 32));
    label_20->setMinimumSize(QSize(180, 32));
    label_20->setMaximumSize(QSize(180, 32));
    label_20->setFont(font2);
    label_20->setStyleSheet(QString::fromUtf8(""));
    label_20->setAlignment(Qt::AlignCenter);
    vershina = new QLabel(centralwidget);
    vershina->setObjectName(QString::fromUtf8("vershina"));
    vershina->setGeometry(QRect(1340, 100, 90, 20));
    vershina->setAlignment(Qt::AlignCenter);
    poligon = new QLabel(centralwidget);
    poligon->setObjectName(QString::fromUtf8("poligon"));
    poligon->setGeometry(QRect(1430, 100, 90, 20));
    poligon->setAlignment(Qt::AlignCenter);
    label_21 = new QLabel(centralwidget);
    label_21->setObjectName(QString::fromUtf8("label_21"));
    label_21->setGeometry(QRect(1340, 7, 180, 32));
    label_21->setMinimumSize(QSize(180, 32));
    label_21->setMaximumSize(QSize(180, 32));
    label_21->setFont(font2);
    label_21->setStyleSheet(QString::fromUtf8(""));
    label_21->setAlignment(Qt::AlignCenter);
    label_vershina = new QLabel(centralwidget);
    label_vershina->setObjectName(QString::fromUtf8("label_vershina"));
    label_vershina->setGeometry(QRect(1340, 67, 90, 32));
    label_vershina->setMinimumSize(QSize(90, 32));
    label_vershina->setMaximumSize(QSize(90, 32));
    QFont font3;
    font3.setPointSize(16);
    font3.setBold(true);
    label_vershina->setFont(font3);
    label_vershina->setStyleSheet(QString::fromUtf8(""));
    label_vershina->setAlignment(Qt::AlignCenter);
    label_poligon = new QLabel(centralwidget);
    label_poligon->setObjectName(QString::fromUtf8("label_poligon"));
    label_poligon->setGeometry(QRect(1430, 67, 90, 32));
    label_poligon->setMinimumSize(QSize(90, 32));
    label_poligon->setMaximumSize(QSize(90, 32));
    label_poligon->setFont(font3);
    label_poligon->setStyleSheet(QString::fromUtf8(""));
    label_poligon->setAlignment(Qt::AlignCenter);
    groupBox = new QGroupBox(centralwidget);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(1530, 30, 100, 140));
    QFont font4;
    font4.setPointSize(15);
    font4.setBold(true);
    groupBox->setFont(font4);
    groupBox->setAlignment(Qt::AlignCenter);
    radio_stipple = new QRadioButton(groupBox);
    radio_stipple->setObjectName(QString::fromUtf8("radio_stipple"));
    radio_stipple->setGeometry(QRect(10, 50, 99, 20));
    radio_whole = new QRadioButton(groupBox);
    radio_whole->setObjectName(QString::fromUtf8("radio_whole"));
    radio_whole->setGeometry(QRect(10, 80, 99, 20));
    size_ribs = new QSpinBox(groupBox);
    size_ribs->setObjectName(QString::fromUtf8("size_ribs"));
    size_ribs->setGeometry(QRect(10, 110, 42, 22));
    size_ribs->setMinimum(1);
    size_ribs->setMaximum(20);
    label_vershina_3 = new QLabel(groupBox);
    label_vershina_3->setObjectName(QString::fromUtf8("label_vershina_3"));
    label_vershina_3->setGeometry(QRect(60, 110, 40, 22));
    label_vershina_3->setMinimumSize(QSize(30, 22));
    label_vershina_3->setMaximumSize(QSize(90, 32));
    label_vershina_3->setFont(font3);
    label_vershina_3->setStyleSheet(QString::fromUtf8(""));
    label_vershina_3->setAlignment(Qt::AlignCenter);
    groupBox_2 = new QGroupBox(centralwidget);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setGeometry(QRect(1210, 30, 100, 140));
    groupBox_2->setFont(font4);
    groupBox_2->setAlignment(Qt::AlignCenter);
    radio_no_show = new QRadioButton(groupBox_2);
    radio_no_show->setObjectName(QString::fromUtf8("radio_no_show"));
    radio_no_show->setGeometry(QRect(10, 20, 90, 20));
    radio_krug = new QRadioButton(groupBox_2);
    radio_krug->setObjectName(QString::fromUtf8("radio_krug"));
    radio_krug->setGeometry(QRect(10, 50, 90, 20));
    radio_kvadrat = new QRadioButton(groupBox_2);
    radio_kvadrat->setObjectName(QString::fromUtf8("radio_kvadrat"));
    radio_kvadrat->setGeometry(QRect(10, 80, 90, 20));
    size_peaks = new QSpinBox(groupBox_2);
    size_peaks->setObjectName(QString::fromUtf8("size_peaks"));
    size_peaks->setGeometry(QRect(10, 110, 42, 22));
    size_peaks->setMinimum(1);
    size_peaks->setMaximum(20);
    label_vershina_2 = new QLabel(groupBox_2);
    label_vershina_2->setObjectName(QString::fromUtf8("label_vershina_2"));
    label_vershina_2->setGeometry(QRect(60, 110, 40, 22));
    label_vershina_2->setMinimumSize(QSize(30, 22));
    label_vershina_2->setMaximumSize(QSize(90, 32));
    label_vershina_2->setFont(font3);
    label_vershina_2->setStyleSheet(QString::fromUtf8(""));
    label_vershina_2->setAlignment(Qt::AlignCenter);
    groupBox_3 = new QGroupBox(centralwidget);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    groupBox_3->setGeometry(QRect(1210, 170, 100, 110));
    groupBox_3->setFont(font4);
    groupBox_3->setAlignment(Qt::AlignCenter);
    peaks_color_r = new QSpinBox(groupBox_3);
    peaks_color_r->setObjectName(QString::fromUtf8("peaks_color_r"));
    peaks_color_r->setGeometry(QRect(10, 25, 42, 22));
    peaks_color_r->setMaximum(127);
    peaks_color_g = new QSpinBox(groupBox_3);
    peaks_color_g->setObjectName(QString::fromUtf8("peaks_color_g"));
    peaks_color_g->setGeometry(QRect(10, 55, 42, 22));
    peaks_color_g->setMaximum(127);
    peaks_color_b = new QSpinBox(groupBox_3);
    peaks_color_b->setObjectName(QString::fromUtf8("peaks_color_b"));
    peaks_color_b->setGeometry(QRect(10, 85, 42, 22));
    peaks_color_b->setMaximum(127);
    label_23 = new QLabel(groupBox_3);
    label_23->setObjectName(QString::fromUtf8("label_23"));
    label_23->setGeometry(QRect(60, 55, 30, 22));
    label_23->setMinimumSize(QSize(30, 22));
    label_23->setMaximumSize(QSize(30, 32));
    label_23->setFont(font2);
    label_23->setStyleSheet(QString::fromUtf8(""));
    label_23->setAlignment(Qt::AlignCenter);
    label_24 = new QLabel(groupBox_3);
    label_24->setObjectName(QString::fromUtf8("label_24"));
    label_24->setGeometry(QRect(60, 85, 30, 22));
    label_24->setMinimumSize(QSize(30, 22));
    label_24->setMaximumSize(QSize(30, 32));
    label_24->setFont(font2);
    label_24->setStyleSheet(QString::fromUtf8(""));
    label_24->setAlignment(Qt::AlignCenter);
    label_22 = new QLabel(groupBox_3);
    label_22->setObjectName(QString::fromUtf8("label_22"));
    label_22->setGeometry(QRect(60, 25, 30, 22));
    label_22->setMinimumSize(QSize(30, 22));
    label_22->setMaximumSize(QSize(30, 32));
    label_22->setFont(font2);
    label_22->setStyleSheet(QString::fromUtf8(""));
    label_22->setAlignment(Qt::AlignCenter);
    groupBox_4 = new QGroupBox(centralwidget);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    groupBox_4->setGeometry(QRect(1530, 170, 100, 110));
    groupBox_4->setFont(font4);
    groupBox_4->setAlignment(Qt::AlignCenter);
    ribs_color_r = new QSpinBox(groupBox_4);
    ribs_color_r->setObjectName(QString::fromUtf8("ribs_color_r"));
    ribs_color_r->setGeometry(QRect(10, 25, 42, 22));
    ribs_color_r->setMaximum(127);
    ribs_color_g = new QSpinBox(groupBox_4);
    ribs_color_g->setObjectName(QString::fromUtf8("ribs_color_g"));
    ribs_color_g->setGeometry(QRect(10, 55, 42, 22));
    ribs_color_g->setMaximum(127);
    ribs_color_b = new QSpinBox(groupBox_4);
    ribs_color_b->setObjectName(QString::fromUtf8("ribs_color_b"));
    ribs_color_b->setGeometry(QRect(10, 85, 42, 22));
    ribs_color_b->setMaximum(127);
    label_25 = new QLabel(groupBox_4);
    label_25->setObjectName(QString::fromUtf8("label_25"));
    label_25->setGeometry(QRect(60, 25, 30, 22));
    label_25->setMinimumSize(QSize(30, 22));
    label_25->setMaximumSize(QSize(30, 32));
    label_25->setFont(font2);
    label_25->setStyleSheet(QString::fromUtf8(""));
    label_25->setAlignment(Qt::AlignCenter);
    label_26 = new QLabel(groupBox_4);
    label_26->setObjectName(QString::fromUtf8("label_26"));
    label_26->setGeometry(QRect(60, 55, 30, 22));
    label_26->setMinimumSize(QSize(30, 22));
    label_26->setMaximumSize(QSize(30, 32));
    label_26->setFont(font2);
    label_26->setStyleSheet(QString::fromUtf8(""));
    label_26->setAlignment(Qt::AlignCenter);
    label_27 = new QLabel(groupBox_4);
    label_27->setObjectName(QString::fromUtf8("label_27"));
    label_27->setGeometry(QRect(60, 85, 30, 22));
    label_27->setMinimumSize(QSize(30, 22));
    label_27->setMaximumSize(QSize(30, 32));
    label_27->setFont(font2);
    label_27->setStyleSheet(QString::fromUtf8(""));
    label_27->setAlignment(Qt::AlignCenter);
    groupBox_5 = new QGroupBox(centralwidget);
    groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
    groupBox_5->setGeometry(QRect(1200, 310, 100, 110));
    groupBox_5->setFont(font4);
    groupBox_5->setAlignment(Qt::AlignCenter);
    fon_color_r = new QSpinBox(groupBox_5);
    fon_color_r->setObjectName(QString::fromUtf8("fon_color_r"));
    fon_color_r->setGeometry(QRect(10, 25, 42, 22));
    fon_color_r->setMaximum(1);
    fon_color_g = new QSpinBox(groupBox_5);
    fon_color_g->setObjectName(QString::fromUtf8("fon_color_g"));
    fon_color_g->setGeometry(QRect(10, 55, 42, 22));
    fon_color_g->setMaximum(1);
    fon_color_b = new QSpinBox(groupBox_5);
    fon_color_b->setObjectName(QString::fromUtf8("fon_color_b"));
    fon_color_b->setGeometry(QRect(10, 85, 42, 22));
    fon_color_b->setMaximum(1);
    label_28 = new QLabel(groupBox_5);
    label_28->setObjectName(QString::fromUtf8("label_28"));
    label_28->setGeometry(QRect(60, 55, 30, 22));
    label_28->setMinimumSize(QSize(30, 22));
    label_28->setMaximumSize(QSize(30, 32));
    label_28->setFont(font2);
    label_28->setStyleSheet(QString::fromUtf8(""));
    label_28->setAlignment(Qt::AlignCenter);
    label_29 = new QLabel(groupBox_5);
    label_29->setObjectName(QString::fromUtf8("label_29"));
    label_29->setGeometry(QRect(60, 85, 30, 22));
    label_29->setMinimumSize(QSize(30, 22));
    label_29->setMaximumSize(QSize(30, 32));
    label_29->setFont(font2);
    label_29->setStyleSheet(QString::fromUtf8(""));
    label_29->setAlignment(Qt::AlignCenter);
    label_30 = new QLabel(groupBox_5);
    label_30->setObjectName(QString::fromUtf8("label_30"));
    label_30->setGeometry(QRect(60, 25, 30, 22));
    label_30->setMinimumSize(QSize(30, 22));
    label_30->setMaximumSize(QSize(30, 32));
    label_30->setFont(font2);
    label_30->setStyleSheet(QString::fromUtf8(""));
    label_30->setAlignment(Qt::AlignCenter);
    change_perspective = new QPushButton(centralwidget);
    change_perspective->setObjectName(QString::fromUtf8("change_perspective"));
    change_perspective->setGeometry(QRect(1350, 550, 161, 32));
    pushButton_2 = new QPushButton(centralwidget);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(1380, 470, 100, 32));
    pushButton_3 = new QPushButton(centralwidget);
    pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
    pushButton_3->setGeometry(QRect(1240, 630, 131, 32));
    pushButton_4 = new QPushButton(centralwidget);
    pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
    pushButton_4->setGeometry(QRect(1410, 630, 100, 32));
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 1650, 24));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);
    QWidget::setTabOrder(size_peaks, peaks_color_r);
    QWidget::setTabOrder(peaks_color_r, peaks_color_g);
    QWidget::setTabOrder(peaks_color_g, peaks_color_b);
    QWidget::setTabOrder(peaks_color_b, fon_color_r);
    QWidget::setTabOrder(fon_color_r, fon_color_g);
    QWidget::setTabOrder(fon_color_g, fon_color_b);
    QWidget::setTabOrder(fon_color_b, masht);
    QWidget::setTabOrder(masht, x_right);
    QWidget::setTabOrder(x_right, y_right);
    QWidget::setTabOrder(y_right, z_right);
    QWidget::setTabOrder(z_right, sdvig);
    QWidget::setTabOrder(sdvig, size_ribs);
    QWidget::setTabOrder(size_ribs, ribs_color_r);
    QWidget::setTabOrder(ribs_color_r, ribs_color_g);
    QWidget::setTabOrder(ribs_color_g, ribs_color_b);
    QWidget::setTabOrder(ribs_color_b, scale_plus);
    QWidget::setTabOrder(scale_plus, scale_sub);
    QWidget::setTabOrder(scale_sub, radio_stipple);
    QWidget::setTabOrder(radio_stipple, radio_whole);
    QWidget::setTabOrder(radio_whole, radio_no_show);
    QWidget::setTabOrder(radio_no_show, radio_krug);
    QWidget::setTabOrder(radio_krug, radio_kvadrat);
    QWidget::setTabOrder(radio_kvadrat, rotation_y_left);
    QWidget::setTabOrder(rotation_y_left, muving_right);
    QWidget::setTabOrder(muving_right, rotation_x_down);
    QWidget::setTabOrder(rotation_x_down, rotation_y_right);
    QWidget::setTabOrder(rotation_y_right, rotation_z_left);
    QWidget::setTabOrder(rotation_z_left, rotation_z_right);
    QWidget::setTabOrder(rotation_z_right, muving_up);
    QWidget::setTabOrder(muving_up, rotation_x_push);
    QWidget::setTabOrder(rotation_x_push, pushButton);
    QWidget::setTabOrder(pushButton, muving_down);
    QWidget::setTabOrder(muving_down, muving_left);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    gif_button->setText(
        QCoreApplication::translate("MainWindow", "gif", nullptr));
    pushButton->setText(
        QCoreApplication::translate("MainWindow", "open file", nullptr));
    label->setText(QString());
    label_2->setText(QString());
    scale_plus->setText(
        QCoreApplication::translate("MainWindow", "+", nullptr));
    scale_sub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
    muving_left->setText(
        QCoreApplication::translate("MainWindow", "left", nullptr));
    muving_up->setText(
        QCoreApplication::translate("MainWindow", "up", nullptr));
    muving_right->setText(
        QCoreApplication::translate("MainWindow", "right", nullptr));
    muving_down->setText(
        QCoreApplication::translate("MainWindow", "down", nullptr));
    rotation_y_left->setText(
        QCoreApplication::translate("MainWindow", "left", nullptr));
    rotation_y_right->setText(
        QCoreApplication::translate("MainWindow", "right", nullptr));
    rotation_x_down->setText(
        QCoreApplication::translate("MainWindow", "down", nullptr));
    rotation_x_push->setText(
        QCoreApplication::translate("MainWindow", "push", nullptr));
    rotation_z_left->setText(
        QCoreApplication::translate("MainWindow", "left", nullptr));
    rotation_z_right->setText(
        QCoreApplication::translate("MainWindow", "right", nullptr));
    label_15->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
    label_16->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
    label_17->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
    label_18->setText(
        QCoreApplication::translate("MainWindow", "MOVING:", nullptr));
    label_19->setText(
        QCoreApplication::translate("MainWindow", "SCALE:", nullptr));
    label_20->setText(
        QCoreApplication::translate("MainWindow", "ROTATION:", nullptr));
    vershina->setText(QString());
    poligon->setText(QString());
    label_21->setText(
        QCoreApplication::translate("MainWindow", "FILE NAME:", nullptr));
    label_vershina->setText(
        QCoreApplication::translate("MainWindow", "peaks", nullptr));
    label_poligon->setText(
        QCoreApplication::translate("MainWindow", "ribs", nullptr));
    groupBox->setTitle(
        QCoreApplication::translate("MainWindow", "ribs", nullptr));
    radio_stipple->setText(
        QCoreApplication::translate("MainWindow", "stipple", nullptr));
    radio_whole->setText(
        QCoreApplication::translate("MainWindow", "whole", nullptr));
    label_vershina_3->setText(
        QCoreApplication::translate("MainWindow", "size", nullptr));
    groupBox_2->setTitle(
        QCoreApplication::translate("MainWindow", "peaks", nullptr));
    radio_no_show->setText(
        QCoreApplication::translate("MainWindow", "no peaks", nullptr));
    radio_krug->setText(
        QCoreApplication::translate("MainWindow", "krug", nullptr));
    radio_kvadrat->setText(
        QCoreApplication::translate("MainWindow", "kvadrat", nullptr));
    label_vershina_2->setText(
        QCoreApplication::translate("MainWindow", "size", nullptr));
    groupBox_3->setTitle(
        QCoreApplication::translate("MainWindow", "peaks color", nullptr));
    label_23->setText(QCoreApplication::translate("MainWindow", "g", nullptr));
    label_24->setText(QCoreApplication::translate("MainWindow", "b", nullptr));
    label_22->setText(QCoreApplication::translate("MainWindow", "r", nullptr));
    groupBox_4->setTitle(
        QCoreApplication::translate("MainWindow", "ribs color", nullptr));
    label_25->setText(QCoreApplication::translate("MainWindow", "r", nullptr));
    label_26->setText(QCoreApplication::translate("MainWindow", "g", nullptr));
    label_27->setText(QCoreApplication::translate("MainWindow", "b", nullptr));
    groupBox_5->setTitle(
        QCoreApplication::translate("MainWindow", "fon color", nullptr));
    label_28->setText(QCoreApplication::translate("MainWindow", "g", nullptr));
    label_29->setText(QCoreApplication::translate("MainWindow", "b", nullptr));
    label_30->setText(QCoreApplication::translate("MainWindow", "r", nullptr));
    change_perspective->setText(QCoreApplication::translate(
        "MainWindow", "Change Perspective", nullptr));
    pushButton_2->setText(
        QCoreApplication::translate("MainWindow", "Apply", nullptr));
    pushButton_3->setText(
        QCoreApplication::translate("MainWindow", "screnshot jpeg", nullptr));
    pushButton_4->setText(
        QCoreApplication::translate("MainWindow", "screnshot bmp", nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H
