#include "test.h"

TEST(Circle, getPoint) {
  tt::Circle c(1.5);
  EXPECT_EQ(c.getPoint(M_PI_2), tt::Point({0, 1.5, 0}));
}

TEST(Circle, getDerivative) {
  tt::Circle c(1.5);
  EXPECT_EQ(c.getDerivative(M_PI_2), tt::Point({-1.5, 0, 0}));
}

TEST(Circle, NegotiveArg) { EXPECT_ANY_THROW(tt::Circle c(-1.5)); }

TEST(Ellipse, getPoint) {
  tt::Ellipse e(1.5, 1.0);
  EXPECT_EQ(e.getPoint(M_PI_2), tt::Point({0, 1, 0}));
}

TEST(Ellipse, getDerivative) {
  tt::Ellipse e(1.5, 1.0);
  EXPECT_EQ(e.getDerivative(M_PI_2), tt::Point({-1.5, 0, 0}));
}

TEST(Ellipse, NegotiveArg) { EXPECT_ANY_THROW(tt::Ellipse e(-1.5, 2.5)); }

TEST(Helixe, getPoint) {
  tt::Helixe e(1.5, 2.5);
  double t = M_PI_2;
  EXPECT_EQ(e.getPoint(t), tt::Point({0, 1.5, 2.5 * t / (2 * M_PI)}));
}

TEST(Helixe, getDerivative) {
  tt::Helixe e(1.5, 2.5);
  double t = M_PI_2;
  EXPECT_EQ(e.getDerivative(t), tt::Point({-1.5, 0, 2.5 / (2 * M_PI)}));
}

TEST(Helixe, NegotiveArg) { EXPECT_ANY_THROW(tt::Helixe e(-1.5, 2.5)); }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}