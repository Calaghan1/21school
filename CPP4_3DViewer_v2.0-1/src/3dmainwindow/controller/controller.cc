#include "controller.h"

#include <algorithm>
#include <memory>

#include "model/model.h"

namespace s21 {

Controller::Controller() noexcept {
  model_ =
      std::make_unique<Model>();     // Create a new instance of the Model class
  file_ = std::make_unique<File>();  // Create a new instance of the File class
}

Controller::~Controller() noexcept {
  // Destructor, no additional cleanup required
}

void Controller::SpinX(double x, std::vector<std::vector<double>>& vertex_) {
  model_->Spin(Model::CoordinateType::kX, x, vertex_);
}

void Controller::SpinY(double x, std::vector<std::vector<double>>& vertex_) {
  model_->Spin(Model::CoordinateType::kY, x, vertex_);
}

void Controller::SpinZ(double x, std::vector<std::vector<double>>& vertex_) {
  model_->Spin(Model::CoordinateType::kZ, x, vertex_);
}

void Controller::Scale(double mul, std::vector<std::vector<double>>& vertex_) {
  model_->Scale(mul, vertex_);  // Call the Scale method of the Model class to
                                // scale the vertices
}

/*!
 * @brief Runs the s21::Model class method to save settings to a file based on a
 * key.
 *
 * @param color The value
 * @param number The key
 * \return std::pair<int, int> A pair: key, value
 */
std::pair<int, int> Controller::SettingChanges(int color, int number) {
  return model_->SettingChanges(
      color, number);  // Call the SettingChanges method of the Model class to
                       // save settings to a file
}

/*!
 * @brief Runs the s21::Model class method to save settings to a file based on a
 * key.
 *
 * @param number The key
 * \return std::pair<int, int> A pair: key, value
 */
std::pair<int, int> Controller::SettingChanges(int number) {
  return model_->SettingChanges(
      number);  // Call the SettingChanges method of the Model class to save
                // settings to a file
}

/*!
 * @brief Runs the s21::Model class method to save all settings from the file to
 * an array.
 *
 * @param arr The settings array
 */
void Controller::GetSettings(int* arr) {
  model_->GetSettings(arr);  // Call the GetSettings method of the Model class
                             // to retrieve settings from the file
}

/*!
 * @brief Runs the s21::Model class method to save settings from the file to an
 * array based on a key.
 *
 * @param arr The settings array
 * @param x A pair: key, value
 */
void Controller::SaveSettings(int* arr, std::pair<int, int> x) {
  model_->SaveSettings(arr, x);  // Call the SaveSettings method of the Model
                                 // class to save settings to an array
}

/*!
 * @brief Runs the file parser.
 *
 * @param path The path to the file
 * \return std::pair<std::vector<std::vector<double>>,
 * std::vector<std::vector<double>>> A pair of two-dimensional vectors: vertices
 * and polygons
 */
void Controller::ReceiveModelFromFile(const std::string& path) {
  model_ = std::make_unique<Model>(
      file_->Parser(path));  // Call the Parser method of the File class to
                             // parse the file and create a new Model instance
}

void Controller::DestroyPreviousModel() {
  if (model_) {
    model_.reset();  // Destroy the previous model by resetting the unique_ptr
  }
}

std::vector<std::vector<double>>& Controller::GetVertex() {
  return model_->GetVertex();
}

std::vector<std::vector<double>>& Controller::GetPolygons() {
  return model_->GetPolygons();
}

}  // namespace s21
