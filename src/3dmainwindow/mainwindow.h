#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qdebug.h>

#include <QMainWindow>
#include <QSettings>
#include <QThread>

#include "./gifimage/qgifimage.h"

/*!
 *@mainpage 3DViewer v1.0
 * Программа предоставляет возможность:
    - Загружать каркасную модель из файла формата obj (поддержка только списка
 вершин и поверхностей).
    - Перемещать модель на заданное расстояние относительно осей X, Y, Z.
    - Поворачивать модель на заданный угол относительно своих осей X, Y, Z
    - Масштабировать модель на заданное значение.
 * Графический пользовательский интерфейс содержит:
    - Кнопку для выбора файла с моделью и поле для вывода его названия.
    - Зону визуализации каркасной модели.
    - Кнопку/кнопки и поля ввода для перемещения модели.
    - Кнопку/кнопки и поля ввода для поворота модели.
    - Кнопку/кнопки и поля ввода для масштабирования модели.
    - Информацию о загруженной модели - название файла, кол-во вершин и ребер.
 *- Программа позволяет настраивать тип проекции (параллельная и центральная)
 - Программа позволяет настраивать тип (сплошная, пунктирная), цвет и толщину
 ребер, способ отображения (отсутствует, круг, квадрат), цвет и размер вершин
 - Программа позволяет выбирать цвет фона
 - Настройки сохранятся между перезапусками программы
 - Программа позволяет сохранять полученные ("отрендеренные") изображения в файл
 в форматах bmp и jpeg
 - Программа позволяет по специальной кнопке записывать небольшие "скринкасты" -
 текущие пользовательские аффинные преобразования загруженного объекта в
 gif-анимацию (640x480, 10fps, 5s)
 */

namespace Ui {
class MainWindow;
}
/*!
 * \brief The Timer_class class время для гифки
 */
class Timer_class : public QObject {
 public:
  QTimer *timer;
};
/*!
 * \brief The MainWindow class бекенд
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
   * @brief сохраняет гифку
   */
  void save_gif();

  /*!
   * @brief общая функция сохранения
   */
  void saving_frames();
  /*!
   * @brief кнопка выбора файла
   */
  void on_pushButton_clicked();
  /*!
   * @brief увеличивает масштаб
   */
  void on_scale_plus_clicked();
  /*!
   * @brief уменьшает масштаб
   */
  void on_scale_sub_clicked();
  /*!
   * @brief поворачивает по оси х на себя
   */
  void on_rotation_x_down_clicked();
  /*!
   * @brief поворачивает по оси х от себя
   */
  void on_rotation_x_push_clicked();
  /*!
   * @brief поворачивает по оси у в лево
   */
  void on_rotation_y_left_clicked();
  /*!
   * @brief поворачивает по оси у вправо
   */
  void on_rotation_y_right_clicked();
  /*!
   * @brief поворачивает по оси z в лево
   */
  void on_rotation_z_left_clicked();
  /*!
   * @brief поворачивает по оси z в право
   */
  void on_rotation_z_right_clicked();
  /*!
   * @brief двигает фигуру вверх
   */
  void on_muving_up_clicked();
  /*!
   * @brief двигает фигуру в лево
   */
  void on_muving_left_clicked();
  /*!
   * @brief двигает фигуру в право
   */
  void on_muving_right_clicked();
  /*!
   * @brief двигает фигуру вниз
   */
  void on_muving_down_clicked();
  /*!
   * @brief сплошная линия ребер
   */
  void on_radio_whole_clicked();
  /*!
   * @brief отключает вершины
   */
  void on_radio_no_show_clicked();
  /*!
   * @brief отображает точки круглыми
   */
  void on_radio_krug_clicked();
  /*!
   * @brief отображает точки квадратными
   */
  void on_radio_kvadrat_clicked();
  /*!
   * @brief размер точек
   * @param arg1 число max 20
   */
  void on_size_peaks_valueChanged(int arg1);
  /*!
   * @brief толщина ребер
   * @param arg1 число max 20
   */
  void on_size_ribs_valueChanged(int arg1);
  /*!
   * @brief насыщенность красного цвета вершин
   * @param arg1 число max 127
   */
  void on_peaks_color_r_valueChanged(int arg1);
  /*!
   * @brief насыщенность зеленого цвета вершин
   * @param arg1 число max 127
   */
  void on_peaks_color_g_valueChanged(int arg1);
  /*!
   * @brief насыщенность синего цвета вершин
   * @param arg1 число max 127
   */
  void on_peaks_color_b_valueChanged(int arg1);
  /*!
   * @brief насыщенность красного цвета ребер
   * @param arg1 число max 127
   */
  void on_ribs_color_r_valueChanged(int arg1);
  /*!
   * @brief насыщенность зеленого цвета ребер
   * @param arg1 число max 127
   */
  void on_ribs_color_g_valueChanged(int arg1);
  /*!
   * @brief насыщенность синего цвета ребер
   * @param arg1 число max 127
   */
  void on_ribs_color_b_valueChanged(int arg1);
  /*!
   * @brief делает ребра прерывистыми
   */
  void on_radio_stipple_clicked();
  /*!
   * @brief насыщенность красного цвета фона
   * @param arg1 число max 1
   */
  void on_fon_color_r_valueChanged(int arg1);
  /*!
   * @brief насыщенность зеленого цвета фона
   * @param arg1 число max 1
   */
  void on_fon_color_g_valueChanged(int arg1);

  /*!
   * @brief насыщенность синего цвета фона
   * @param arg1 число max 1
   */
  void on_fon_color_b_valueChanged(int arg1);

  /*!
   * @brief меняет вид проекции параллельная/центральная
   */
  void on_change_perspective_clicked();
  /*!
   * @brief кнопка применения изменений
   */
  void on_pushButton_2_clicked();

  /*!
   * @brief кнопка для гифки
   */
  void on_gif_button_clicked();

  /*!
   * @brief скриншот jpeg
   */
  void on_pushButton_3_clicked();

  /*!
   * @brief скриншот bmp
   */
  void on_pushButton_4_clicked();

 private:
  Ui::MainWindow *ui;
};

#endif  // MAINWINDOW_H
