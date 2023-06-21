#ifndef SETTINGS
#define SETTINGS
#include <QtCore/QCoreApplication>
#include <QtCore/QSettings>
#include <iostream>

namespace s21 {

class Settings {
 public:
  Settings();
  Settings(QSettings *set);
  Settings(Settings &&) = delete;
  Settings(const Settings &) = delete;
  Settings &operator=(Settings &&) = delete;
  Settings &operator=(const Settings &) = delete;
  ~Settings();
  std::pair<int, int> SettingChanges(int color, int number);
  std::pair<int, int> SettingChanges(int number);
  void GetSettings(int *arr);

 private:
  QSettings set;
};

}  // namespace s21

#endif  // !SETTINGS
