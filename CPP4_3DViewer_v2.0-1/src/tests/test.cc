#include <gtest/gtest.h>

#include "../3dmainwindow/controller/controller.h"

TEST(BasicTest, Test1) {
  std::vector<std::vector<double>> vertex;
  std::vector<std::vector<double>> polygons;
  s21::Controller controller_;
  controller_.DestroyPreviousModel();
  controller_.ReceiveModelFromFile("3dmainwindow/object/chel.obj");
  vertex = controller_.GetVertex();
  polygons = controller_.GetPolygons();
  ASSERT_NEAR(-0.101389, vertex[0][0], 1e-6);
  ASSERT_NEAR(0.366803, vertex[0][1], 1e-6);
  ASSERT_NEAR(-0.129426, vertex[0][2], 1e-6);

  // ... assert statements for other matrix values

  ASSERT_EQ(0, polygons[0][0]);
  ASSERT_EQ(1, polygons[0][1]);
  ASSERT_EQ(2, polygons[0][2]);

  // ... assert statements for other polygon values
}

TEST(BasicTest, Test3) {
  s21::File tmp;
  s21::Model vec;
  std::vector<std::vector<double>> vector_;
  std::vector<std::vector<double>> pol;
  vec = tmp.Parser("3dmainwindow/object/chel.obj");
  double rad = M_PI * 5.0 / 180;
  vector_ = vec.GetVertex();
  vec.Spin(s21::Model::CoordinateType::kX, rad, vector_);
  ASSERT_NEAR(-0.112283, vector_[0][0], 1e-6);
  ASSERT_NEAR(0.366803, vector_[0][1], 1e-6);
  ASSERT_NEAR(-0.120097, vector_[0][2], 1e-6);

  // ... assert statements for other matrix values

  vector_ = vec.GetVertex();
  vec.Spin(s21::Model::CoordinateType::kY, rad, vector_);
  ASSERT_NEAR(-0.101389, vector_[0][0], 1e-6);
  ASSERT_NEAR(0.354127, vector_[0][1], 1e-6);
  ASSERT_NEAR(-0.160903, vector_[0][2], 1e-6);

  // ... assert statements for other matrix values

  vector_ = vec.GetVertex();
  vec.Spin(s21::Model::CoordinateType::kZ, rad, vector_);
  ASSERT_NEAR(-0.069034, vector_[0][0], 1e-6);
  ASSERT_NEAR(0.374244, vector_[0][1], 1e-6);
  ASSERT_NEAR(-0.129426, vector_[0][2], 1e-6);

  // ... assert statements for other matrix values
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
