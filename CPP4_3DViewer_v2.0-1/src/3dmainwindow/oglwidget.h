#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <qopenglfunctions.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <QFileDialog>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QSettings>
#include <QThread>
#include <QTimer>
#include <QWidget>

#include "controller/controller.h"
#include "parser/parser.h"

#define GL_SILENCE_DEORECATIONS

namespace s21 {
/**
 * @brief класс отрисовки
 *
 */
class OGLWidget : public QOpenGLWidget {
 public:
  int flag = 1;
  QSettings settings;
  OGLWidget(QWidget *parent = 0);
  ~OGLWidget();
  void ParseObjectModel(const std::string &path);
  void SettingsSave(std::pair<int, int> pair_key);
  std::string path;
  void paintGL() override;
  QString *path1;
  void ShowObject();
  int presp = 0;
  void resizeGL(int w, int h) override;

  std::vector<std::vector<double>> vertex;
  std::vector<std::vector<double>> polygons;
  s21::Controller controller_;
  int settings_[20];

 private:
  double x;
  double y;
  int xa = 0;
  float XRoad, YRoad, ZRoad;
  QPoint mPos;
  QTimer tmr;

  void drawCube(float a);
  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;
  void mouseWheeel(QMoveEvent *);
  void initializeGL() override;

 protected:
};

class Observer {
 public:
  Observer(){};
  ~Observer(){};

  /*!
   * @brief сохранение настроек в массив
   * @param key_value пара: ключ, значение
   * @param window виджет
   */
  void StateImpulse(std::pair<int, int> key_value, OGLWidget *window) {
    window->SettingsSave(key_value);
  };

  /*!
   * @brief сохранение настроек в файл
   * @param color значение
   * @param number ключ
   * @param window виджет
   */
  void SettingChanges(int color, int number, OGLWidget *window) {
    StateImpulse(controller_.SettingChanges(color, number), window);
  };

  /*!
   * @brief сохранение настроек в файл
   * @param number ключ
   * @param window виджет
   */
  void SettingChanges(int number, OGLWidget *window) {
    StateImpulse(controller_.SettingChanges(number), window);
  };

  /*!
   * @brief Get the Settings object
   * @param arr массив настроек
   */
  void GetSettings(int *arr) { controller_.GetSettings(arr); }

 private:
  s21::Controller controller_;
};

}  // namespace s21

#endif  // OGLWIDGET_H
