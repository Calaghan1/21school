#include "settings.h"

namespace s21 {

Settings::Settings() {
  QCoreApplication::setOrganizationName("MyProg");
  QCoreApplication::setApplicationName("3dviewer");
}

Settings::~Settings(){};

/*!
 * @brief изменяет файл настроек
 *
 * @param color значение
 * @param number ключ
 * \return std::pair<int, int> возвращает пару: ключ, значение
 */
std::pair<int, int> Settings::SettingChanges(int color, int number) {
  std::pair<int, int> tmp;
  tmp.first = number;
  tmp.second = color;
  if (!number) {
    set.setValue("peaks/size", color);
  } else if (number == 1) {
    set.setValue("ribs/size", color);
  } else if (number == 2) {
    set.setValue("peaks/color_r", color);
  } else if (number == 3) {
    set.setValue("peaks/color_g", color);
  } else if (number == 4) {
    set.setValue("peaks/color_b", color);
  } else if (number == 5) {
    set.setValue("ribs/color_r", color);
  } else if (number == 6) {
    set.setValue("ribs/color_g", color);
  } else if (number == 7) {
    set.setValue("ribs/color_b", color);
  } else if (number == 8) {
    set.setValue("fon_color/color_r", color);
  } else if (number == 9) {
    set.setValue("fon_color/color_g", color);
  } else if (number == 10) {
    set.setValue("fon_color/color_b", color);
  }
  return tmp;
};

/*!
 * @brief изменяет файл настроек
 *
 * @param number ключ
 * \return std::pair<int, int> возвращает пару: ключ, значение
 */
std::pair<int, int> Settings::SettingChanges(int number) {
  std::pair<int, int> tmp;
  if (number == 11) {
    set.setValue("peaks/no_show", 10000);
  } else if (number == 12) {
    set.setValue("ribs/sposob", 1);
    set.setValue("ribs/no_show_2", 2);
  } else if (number == 13) {
    set.setValue("ribs/sposob", 0);
    set.setValue("ribs/no_show_2", 2);
  } else if (number == 14) {
    set.setValue("peaks/sposob", 1);
    set.setValue("peaks/no_show", 0);
  } else if (number == 15) {
    set.setValue("peaks/sposob", 0);
    set.setValue("peaks/no_show", 0);
  }
  tmp.first = number;
  return tmp;
};

/*!
 * @brief считывает настройки при запуске приложения
 *
 * @param arr записывает значения по ключам(ключ является индексом массива)
 */
void Settings::GetSettings(int *arr) {
  arr[0] = set.value("peaks/size").toInt();
  arr[1] = set.value("size_ribs").toInt();
  arr[2] = set.value("peaks/color_r").toInt();
  arr[3] = set.value("peaks/color_g").toInt();
  arr[4] = set.value("peaks/color_b").toInt();
  arr[5] = set.value("ribs/color_r").toInt();
  arr[6] = set.value("ribs/color_g").toInt();
  arr[7] = set.value("ribs/color_b").toInt();
  arr[8] = set.value("fon_color/color_r").toInt();
  arr[9] = set.value("fon_color/color_g").toInt();
  arr[10] = set.value("fon_color/color_b").toInt();
  arr[11] = set.value("peaks/no_show").toInt();
  arr[12] = set.value("ribs/sposob").toInt();
  arr[14] = set.value("peaks/sposob").toInt();
  arr[16] = set.value("ribs/sposob").toInt();
  arr[17] = set.value("ribs/no_show_2").toInt();
  arr[18] = set.value("peaks/sposob").toInt();
  arr[19] = set.value("peaks/no_show").toInt();
};
}  // namespace s21
