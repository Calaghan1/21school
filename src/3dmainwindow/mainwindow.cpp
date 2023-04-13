#include "mainwindow.h"

#include <QTimer>

#include "oglwidget.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  QString str =
      QFileDialog::getOpenFileName(this, "Select File", "", "OBJ File (*.obj)");
  ui->label->setText(str);
  QByteArray add1 = str.toUtf8();
  if (str.length() > 0) {
      for (int i = 0; i < str.length(); i++) {
        ui->widget->path[i] = add1.data()[i];
      }
      ui->widget->path[str.length()] = '\0';
      ui->widget->pars_obj(ui->widget->path);
      ui->vershina->setText(QString::number(ui->widget->obj.v->vertex_mount));
      ui->poligon->setText(QString::number(ui->widget->obj.struct_count));
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
  mashtab(&ui->widget->obj, step);
  ui->widget->update();
}

void MainWindow::on_scale_sub_clicked() {
  double step = 1 - ui->masht->value() / 200.0;
  mashtab(&ui->widget->obj, step);
  ui->widget->update();
}

void MainWindow::on_rotation_x_down_clicked() {
  double rad = M_PI * ui->x_right->value() / 180;
  spin(2, -rad, &ui->widget->obj);
  ui->widget->update();
}

void MainWindow::on_rotation_x_push_clicked() {
  double rad = M_PI * ui->x_right->value() / 180;
  spin(2, rad, &ui->widget->obj);
  ui->widget->update();
}

void MainWindow::on_rotation_y_left_clicked() {
  double rad = M_PI * ui->y_right->value() / 180;
  spin(1, -rad, &ui->widget->obj);
  ui->widget->update();
}

void MainWindow::on_rotation_y_right_clicked() {
  double rad = M_PI * ui->y_right->value() / 180;
  spin(1, rad, &ui->widget->obj);
  ui->widget->update();
}

void MainWindow::on_rotation_z_left_clicked() {
  double rad = M_PI * ui->z_right->value() / 180;
  spin(3, -rad, &ui->widget->obj);
  ui->widget->update();
}

void MainWindow::on_rotation_z_right_clicked() {
  double rad = M_PI * ui->z_right->value() / 180;
  spin(3, rad, &ui->widget->obj);
  ui->widget->update();
}

void MainWindow::on_muving_up_clicked() {
  double step = ui->sdvig->value() / 200.0;
  for (int i = 0; i < ui->widget->obj.v->vertex_mount; i++) {
    ui->widget->obj.v->vertex_matrix[i][1] += step;
  }
  ui->widget->update();
}

void MainWindow::on_muving_left_clicked() {
  double step = ui->sdvig->value() / 200.0;
  for (int i = 0; i < ui->widget->obj.v->vertex_mount; i++) {
    ui->widget->obj.v->vertex_matrix[i][0] -= step;
  }
  ui->widget->update();
}

void MainWindow::on_muving_right_clicked() {
  double step = ui->sdvig->value() / 200.0;
  for (int i = 0; i < ui->widget->obj.v->vertex_mount; i++) {
    ui->widget->obj.v->vertex_matrix[i][0] += step;
  }
  ui->widget->update();
}

void MainWindow::on_muving_down_clicked() {
  double step = ui->sdvig->value() / 200.0;
  for (int i = 0; i < ui->widget->obj.v->vertex_mount; i++) {
    ui->widget->obj.v->vertex_matrix[i][1] -= step;
  }
  ui->widget->update();
}

void MainWindow::on_radio_stipple_clicked() {
  settings.setValue("ribs/sposob", 1);
  settings.setValue("ribs/no_show_2", 2);
}

void MainWindow::on_radio_whole_clicked() {
  settings.setValue("ribs/sposob", 0);
  settings.setValue("ribs/no_show_2", 2);
}

void MainWindow::on_radio_no_show_clicked() {
  settings.setValue("peaks/no_show", 10000);
}

void MainWindow::on_radio_krug_clicked() {
  settings.setValue("peaks/sposob", 1);
  settings.setValue("peaks/no_show", 0);
}

void MainWindow::on_radio_kvadrat_clicked() {
  settings.setValue("peaks/sposob", 0);
  settings.setValue("peaks/no_show", 0);
}

void MainWindow::on_size_peaks_valueChanged(int arg1) {
  settings.setValue("peaks/size", arg1);
}

void MainWindow::on_size_ribs_valueChanged(int arg1) {
  settings.setValue("ribs/size", arg1);
}

void MainWindow::on_peaks_color_r_valueChanged(int arg1) {
  settings.setValue("peaks/color_r", arg1);
}

void MainWindow::on_peaks_color_g_valueChanged(int arg1) {
  settings.setValue("peaks/color_g", arg1);
}

void MainWindow::on_peaks_color_b_valueChanged(int arg1) {
  settings.setValue("peaks/color_b", arg1);
}

void MainWindow::on_ribs_color_r_valueChanged(int arg1) {
  settings.setValue("ribs/color_r", arg1);
}

void MainWindow::on_ribs_color_g_valueChanged(int arg1) {
  settings.setValue("ribs/color_g", arg1);
}

void MainWindow::on_ribs_color_b_valueChanged(int arg1) {
  settings.setValue("ribs/color_b", arg1);
}

void MainWindow::on_fon_color_r_valueChanged(int arg1) {
  settings.setValue("fon_color/color_r", arg1);
}

void MainWindow::on_fon_color_g_valueChanged(int arg1) {
  settings.setValue("fon_color/color_g", arg1);
}

void MainWindow::on_fon_color_b_valueChanged(int arg1) {
  settings.setValue("fon_color/color_b", arg1);
}

void MainWindow::on_change_perspective_clicked() {
  if (ui->widget->presp == 0) {
    ui->widget->presp = 1;
  } else {
    ui->widget->presp = 0;
  }
  ui->widget->update();
}

void MainWindow::on_pushButton_2_clicked() { ui->widget->update(); }

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
