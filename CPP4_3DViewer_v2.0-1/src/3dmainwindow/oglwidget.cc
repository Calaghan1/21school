#include "oglwidget.h"

#include "mainwindow.h"

namespace s21 {
OGLWidget::OGLWidget(QWidget *parent) : QOpenGLWidget(parent) {
  ParseObjectModel(path);
}

OGLWidget::~OGLWidget() {}

/*!
 * @brief считывание координат
 *
 * @param mo координаты мыши
 */
void OGLWidget::mousePressEvent(QMouseEvent *mo) { mPos = mo->pos(); }

/*!
 * @brief движение сцены
 *
 * @param mo координаты курсора мыши
 */
void OGLWidget::mouseMoveEvent(QMouseEvent *mo) {
  XRoad = 1 / M_PI * (mo->pos().y() - mPos.y());
  YRoad = 1 / M_PI * (mo->pos().x() - mPos.x());
  update();
}

void OGLWidget::initializeGL() { glEnable(GL_DEPTH_TEST); }

void OGLWidget::paintGL() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (presp == 0) {
    glFrustum(-1, 1, -1, 1, 2, 6);
    glTranslatef(0, 0, -3);
  } else {
    glOrtho(-1, 1, -1, 1, -1, 5);
    glTranslatef(0, 0, -0);
  }
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_TEST);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0, 0, 0);
  glRotatef(XRoad, 1, 0, 0);
  glRotatef(YRoad, 0, 1, 0);
  ShowObject();
}

void OGLWidget::ParseObjectModel(const std::string &path) {
  controller_.DestroyPreviousModel();
  controller_.ReceiveModelFromFile(path);
  vertex = controller_.GetVertex();
  polygons = controller_.GetPolygons();
};

/*!
 * @brief сохранение настроек
 *
 * @param pair_key пара: ключ, значение
 */
void OGLWidget::SettingsSave(std::pair<int, int> pair_key) {
  controller_.SaveSettings(settings_, pair_key);
  ShowObject();
  update();
};

/*!
 * @brief отрисовка модели
 */
void OGLWidget::ShowObject() {
  glClearColor(settings_[8], settings_[9], settings_[10], 0);
  glEnable(GL_LINE_STIPPLE);   // запуск отрисовки
  glMatrixMode(GL_MODELVIEW);  // инициализация матрицы
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // очищает цвет и матрицы
  glLineWidth(settings_[1]);
  glColor3b(settings_[5], settings_[6], settings_[7]);  // цвет
  if (settings_[16]) {
    glLineStipple(0, 40);  // пунктирная линия
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
  for (size_t i = 0; i < polygons.size(); i++) {
    glBegin(settings_[17]);
    for (size_t j = 0; j < polygons[i].size(); j++) {
      glVertex3d(vertex[polygons[i][j]][0], vertex[polygons[i][j]][1],
                 vertex[polygons[i][j]][2]);
    }
    glEnd();
  }
  glColor3b(settings_[2], settings_[3], settings_[4]);
  glPointSize(settings_[0]);  // толщина точек
  if (settings_[18] == 1) {
    glEnable(GL_POINT_SMOOTH);  // круглые точки значение 2832
  } else {
    glDisable(GL_POINT_SMOOTH);  // отключает круглые точки
  }
  glBegin(settings_[11]);  // значение 0, при 10к ничего не видно
  for (size_t i = 0; i < vertex.size(); i++) {
    glVertex3d(vertex[i][0], vertex[i][1], vertex[i][2]);
  }
  glEnd();
};

void OGLWidget::resizeGL(int w, int h) {}

}  // namespace s21
