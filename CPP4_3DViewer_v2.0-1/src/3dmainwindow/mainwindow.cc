#include "mainwindow.h"

#include <QTimer>

#include "oglwidget.h"
#include "ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->radio_whole, SIGNAL(clicked()), this, SLOT(SettingsSelect()));
  connect(ui->radio_no_show, SIGNAL(clicked()), this, SLOT(SettingsSelect()));
  connect(ui->radio_stipple, SIGNAL(clicked()), this, SLOT(SettingsSelect()));
  connect(ui->radio_krug, SIGNAL(clicked()), this, SLOT(SettingsSelect()));
  connect(ui->radio_kvadrat, SIGNAL(clicked()), this, SLOT(SettingsSelect()));

  connect(ui->size_peaks, SIGNAL(valueChanged(int)), this,
          SLOT(SettingsSelect(int)));
  connect(ui->size_ribs, SIGNAL(valueChanged(int)), this,
          SLOT(SettingsSelect(int)));
  connect(ui->peaks_color_r, SIGNAL(valueChanged(int)), this,
          SLOT(SettingsSelect(int)));
  connect(ui->peaks_color_g, SIGNAL(valueChanged(int)), this,
          SLOT(SettingsSelect(int)));
  connect(ui->peaks_color_b, SIGNAL(valueChanged(int)), this,
          SLOT(SettingsSelect(int)));
  connect(ui->ribs_color_r, SIGNAL(valueChanged(int)), this,
          SLOT(SettingsSelect(int)));
  connect(ui->ribs_color_g, SIGNAL(valueChanged(int)), this,
          SLOT(SettingsSelect(int)));
  connect(ui->ribs_color_b, SIGNAL(valueChanged(int)), this,
          SLOT(SettingsSelect(int)));
  connect(ui->fon_color_r, SIGNAL(valueChanged(int)), this,
          SLOT(SettingsSelect(int)));
  connect(ui->fon_color_g, SIGNAL(valueChanged(int)), this,
          SLOT(SettingsSelect(int)));
  connect(ui->fon_color_b, SIGNAL(valueChanged(int)), this,
          SLOT(SettingsSelect(int)));
  set_check_.emplace("size_peaks", 0);
  set_check_.emplace("size_ribs", 1);
  set_check_.emplace("peaks_color_r", 2);
  set_check_.emplace("peaks_color_g", 3);
  set_check_.emplace("peaks_color_b", 4);
  set_check_.emplace("ribs_color_r", 5);
  set_check_.emplace("ribs_color_g", 6);
  set_check_.emplace("ribs_color_b", 7);
  set_check_.emplace("fon_color_r", 8);
  set_check_.emplace("fon_color_g", 9);
  set_check_.emplace("fon_color_b", 10);
  set_check_.emplace("radio_no_show", 11);
  set_check_.emplace("radio_stipple", 12);
  set_check_.emplace("radio_whole", 13);
  set_check_.emplace("radio_krug", 14);
  set_check_.emplace("radio_kvadrat", 15);
  set_check_.emplace("ribs/sposob", 16);
  set_check_.emplace("ribs/no_show_2", 17);
  set_check_.emplace("peaks/sposob", 18);
  set_check_.emplace("peaks/no_show", 19);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  QString str =
      QFileDialog::getOpenFileName(this, "Select File", "", "OBJ File (*.obj)");
  ui->label->setText(str);
  QByteArray add1 = str.toUtf8();
  if (str.length() > 0) {
    observer_.GetSettings(ui->widget->settings_);
    ui->widget->path = str.toUtf8().constData();
    ui->widget->ParseObjectModel(ui->widget->path);
    ui->vershina->setText(QString::number((int)ui->widget->vertex.size()));
    ui->poligon->setText(QString::number((int)ui->widget->polygons.size()));
    int k = 0;
    int l = 0;
    while (l < str.length()) {
      if (str.data()[l] == '/') {
        k = l + 1;
      }
      l++;
    }
    QString info;
    for (int i = 0; i < str.length() - k; i++) {
      info += str.data()[k + i];
    }
    ui->label_2->setText(info);
  }
}

void MainWindow::on_scale_plus_clicked() {
  double step = 1 + ui->masht->value() / 200.0;
  ui->widget->controller_.Scale(step, ui->widget->vertex);
  ui->widget->update();
}

void MainWindow::on_scale_sub_clicked() {
  double step = 1 - ui->masht->value() / 200.0;
  ui->widget->controller_.Scale(step, ui->widget->vertex);
  ui->widget->update();
}

void MainWindow::on_rotation_x_down_clicked() {
  double rad = M_PI * ui->x_right->value() / 180;
  ui->widget->controller_.SpinX(-rad, ui->widget->vertex);
  ui->widget->update();
}

void MainWindow::on_rotation_x_push_clicked() {
  double rad = M_PI * ui->x_right->value() / 180;
  ui->widget->controller_.SpinX(rad, ui->widget->vertex);
  ui->widget->update();
}

void MainWindow::on_rotation_y_left_clicked() {
  double rad = M_PI * ui->y_right->value() / 180;
  ui->widget->controller_.SpinY(-rad, ui->widget->vertex);
  ui->widget->update();
}

void MainWindow::on_rotation_y_right_clicked() {
  double rad = M_PI * ui->y_right->value() / 180;
  ui->widget->controller_.SpinY(rad, ui->widget->vertex);
  ui->widget->update();
}

void MainWindow::on_rotation_z_left_clicked() {
  double rad = M_PI * ui->z_right->value() / 180;
  ui->widget->controller_.SpinZ(-rad, ui->widget->vertex);
  ui->widget->update();
}

void MainWindow::on_rotation_z_right_clicked() {
  double rad = M_PI * ui->z_right->value() / 180;
  ui->widget->controller_.SpinZ(rad, ui->widget->vertex);
  ui->widget->update();
}

void MainWindow::on_moving_up_clicked() {
  double step = ui->sdvig->value() / 200.0;
  for (size_t i = 0; i < ui->widget->vertex.size(); i++) {
    ui->widget->vertex[i][1] += step;
  }
  ui->widget->update();
}

void MainWindow::on_moving_left_clicked() {
  double step = ui->sdvig->value() / 200.0;
  for (size_t i = 0; i < ui->widget->vertex.size(); i++) {
    ui->widget->vertex[i][0] -= step;
  }
  ui->widget->update();
}

void MainWindow::on_moving_right_clicked() {
  double step = ui->sdvig->value() / 200.0;
  for (size_t i = 0; i < ui->widget->vertex.size(); i++) {
    ui->widget->vertex[i][0] += step;
  }
  ui->widget->update();
}

void MainWindow::on_moving_down_clicked() {
  double step = ui->sdvig->value() / 200.0;
  for (size_t i = 0; i < ui->widget->vertex.size(); i++) {
    ui->widget->vertex[i][1] -= step;
  }
  ui->widget->update();
}

void MainWindow::SettingsSelect(int arg1) {
  QSpinBox *button = (QSpinBox *)sender();
  QString str = button->objectName();
  std::string spinbox_ = str.toLocal8Bit().constData();
  auto iter = set_check_.find(spinbox_);
  if (iter != set_check_.end()) {
    observer_.SettingChanges(arg1, iter->second, ui->widget);
  }
}

void MainWindow::SettingsSelect() {
  QSpinBox *button = (QSpinBox *)sender();
  QString str = button->objectName();
  std::string spinbox_ = str.toLocal8Bit().constData();
  auto iter = set_check_.find(spinbox_);
  if (iter != set_check_.end()) {
    observer_.SettingChanges(iter->second, ui->widget);
  }
}

void MainWindow::on_change_perspective_clicked() {
  if (ui->widget->presp == 0) {
    ui->widget->presp = 1;
  } else {
    ui->widget->presp = 0;
  }
  ui->widget->update();
}

void MainWindow::on_gif_button_clicked() {
  ui->gif_button->setEnabled(false);
  option = 0;
  save_gif();
  timer = new QTimer(0);
  connect(timer, SIGNAL(timeout()), this, SLOT(saving_frames()));
  timer->setInterval(100);
  timer->start();
}

void MainWindow::save_gif() {
  time = 0.0;
  QGifImage gif(QSize(600, 400));
  QVector<QRgb> ctable;
  ctable << qRgb(255, 255, 255) << qRgb(0, 0, 0) << qRgb(255, 0, 0)
         << qRgb(0, 255, 0) << qRgb(0, 0, 255) << qRgb(255, 255, 0)
         << qRgb(0, 255, 255) << qRgb(255, 0, 255);
  gif.setGlobalColorTable(ctable, Qt::black);
}
void MainWindow::saving_frames() {
  if (!ui->pushButton_3->isEnabled() || !ui->pushButton_4->isEnabled()) {
    if (time == 100) {
      timer->stop();
      QString name;
      if (!ui->pushButton_3->isEnabled()) {
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_3->setText("Save image");
        name = QFileDialog::getSaveFileName(this, tr("Save file"), "Jpeg_image",
                                            tr("*.jpeg"));
      } else {
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_4->setText("Save image");
        name = QFileDialog::getSaveFileName(this, tr("Save file"), "BMP_image",
                                            tr("*.bmp"));
      }
      gif.setDefaultDelay(100);
      gif.save(name);
    } else {
      gif.addFrame(ui->widget->grab().toImage());
    }
  }
  if (!ui->gif_button->isEnabled()) {
    if (time == 5000) {
      timer->stop();
      ui->gif_button->setEnabled(true);
      ui->gif_button->setText("Save GIF");
      QString name = QFileDialog::getSaveFileName(this, tr("Save file"),
                                                  "GIF_image", tr("*.gif"));
      gif.setDefaultDelay(100);
      gif.save(name);
    } else {
      gif.addFrame(ui->widget->grab().toImage());
      ui->gif_button->setText(QString::number(time * 0.001, 'f', 3));
    }
  }
  time += 100;
}

void MainWindow::on_pushButton_3_clicked() {
  ui->pushButton_3->setEnabled(false);
  save_gif();
  timer = new QTimer(0);
  connect(timer, SIGNAL(timeout()), this, SLOT(saving_frames()));
  timer->setInterval(100);
  timer->start();
}

void MainWindow::on_pushButton_4_clicked() {
  ui->pushButton_4->setEnabled(false);
  save_gif();
  timer = new QTimer(0);
  connect(timer, SIGNAL(timeout()), this, SLOT(saving_frames()));
  timer->setInterval(100);
  timer->start();
}

}  // namespace s21
