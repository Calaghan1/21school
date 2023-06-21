#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/qdebug.h>

#include <QMainWindow>
#include <QtCore/QSettings>
#include <QtCore/QThread>
#include <map>

#include "gifimage/qgifimage.h"
#include "oglwidget.h"

/*!
 * @mainpage 3DViewer v1.0
 * The program provides the following features:
 * - Loading a wireframe model from an obj file (supporting only vertex and
 * surface lists).
 * - Moving the model by a specified distance along the X, Y, and Z axes.
 * - Rotating the model by a specified angle around its X, Y, and Z axes.
 * - Scaling the model by a specified value.
 *
 * The graphical user interface includes:
 * - A button for selecting a file with the model and a field for displaying its
 * name.
 * - The visualization area for the wireframe model.
 * - Button(s) and input fields for moving the model.
 * - Button(s) and input fields for rotating the model.
 * - Button(s) and input fields for scaling the model.
 * - Information about the loaded model, including the file name, number of
 * vertices, and edges.
 *
 * The program allows adjusting the projection type (parallel and central).
 * The program allows adjusting the edge type (solid, dashed), color, and
 * thickness, as well as the vertex display mode (none, circle, square), color,
 * and size. The program allows selecting the background color. The settings
 * persist between program restarts. The program allows saving rendered images
 * to files in BMP and JPEG formats. The program allows recording small
 * "screencasts" by capturing the current user affine transformations of the
 * loaded object into a GIF animation (640x480, 10fps, 5s).
 */

namespace Ui {
class MainWindow;
}

namespace s21 {
/*!
 * \brief The Timer_class class - Timer for GIF
 */
class Timer_class : public QObject {
 public:
  QTimer *timer;
};

/*!
 * \brief The MainWindow class - Backend
 */
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  QSettings settings;
  QGifImage gif;
  float time;
  QTimer *timer;
  int option = 0;

 private slots:
  /*!
   * @brief Save the GIF
   */
  void save_gif();

  /*!
   * @brief Common saving function
   */
  void saving_frames();

  /*!
   * @brief File selection button
   */
  void on_pushButton_clicked();

  /*!
   * @brief Increase the scale
   */
  void on_scale_plus_clicked();

  /*!
   * @brief Decrease the scale
   */
  void on_scale_sub_clicked();

  /*!
   * @brief Rotate around the X-axis in a negative direction
   */
  void on_rotation_x_down_clicked();

  /*!
   * @brief Rotate around the X-axis in a positive direction
   */
  void on_rotation_x_push_clicked();

  /*!
   * @brief Rotate around the Y-axis to the left
   */
  void on_rotation_y_left_clicked();

  /*!
   * @brief Rotate around the Y-axis to the right
   */
  void on_rotation_y_right_clicked();

  /*!
   * @brief Rotate around the Z-axis to the left
   */
  void on_rotation_z_left_clicked();

  /*!
   * @brief Rotate around the Z-axis to the right
   */
  void on_rotation_z_right_clicked();

  /*!
   * @brief Move the figure up
   */
  void on_moving_up_clicked();

  /*!
   * @brief Move the figure to the left
   */
  void on_moving_left_clicked();

  /*!
   * @brief Move the figure to the right
   */
  void on_moving_right_clicked();

  /*!
   * @brief Move the figure down
   */
  void on_moving_down_clicked();

  /*!
   * @brief Change the projection view (parallel/central)
   */
  void on_change_perspective_clicked();

  /*!
   * @brief Button for GIF
   */
  void on_gif_button_clicked();

  /*!
   * @brief Save screenshot as JPEG
   */
  void on_pushButton_3_clicked();

  /*!
   * @brief Save screenshot as BMP
   */
  void on_pushButton_4_clicked();

  /*!
   * @brief Save settings to file
   *
   * @param arg1 - Value
   */
  void SettingsSelect(int arg1);

  /*!
   * @brief Save settings to file
   */
  void SettingsSelect();

 private:
  s21::Observer observer_;
  Ui::MainWindow *ui;
  s21::Controller set;
  std::map<std::string, int> set_check_;
};
}  // namespace s21

#endif  // MAINWINDOW_H
