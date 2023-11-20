#include "curves.h"

tt::Curve::~Curve() {}

tt::Circle::Circle(double r) : radius_(r) {
  if (radius_ < 0) throw std::invalid_argument("Radius must be positive");
}

tt::Point tt::Circle::getPoint(const double t) const& {
  return Point{radius_ * cos(t), radius_ * sin(t), 0};
}

tt::Point tt::Circle::getDerivative(const double t) const& {
  return Point{-radius_ * sin(t), radius_ * cos(t), 0};
}

tt::Ellipse::Ellipse(double rx, double ry) : radiusX_(rx), radiusY_(ry) {
  if (radiusX_ < 0 || radiusY_ < 0)
    throw std::invalid_argument("Radius must be positive");
}

tt::Point tt::Ellipse::getPoint(const double t) const& {
  return Point{radiusX_ * cos(t), radiusY_ * sin(t), 0};
}

tt::Point tt::Ellipse::getDerivative(const double t) const& {
  return Point{-radiusX_ * sin(t), radiusY_ * cos(t), 0};
}

tt::Helixe::Helixe(double radius, double step) : radius_(radius), step_(step) {
  if (radius_ < 0) throw std::invalid_argument("Radius must be positive");
}

tt::Point tt::Helixe::getPoint(const double t) const& {
  return Point{radius_ * cos(t), radius_ * sin(t), step_ * t / (2 * M_PI)};
}

tt::Point tt::Helixe::getDerivative(const double t) const& {
  return Point{-radius_ * sin(t), radius_ * cos(t), step_ / (2 * M_PI)};
}

bool tt::Point::operator==(const Point& o) const& {
  return fabs(x - o.x) < EPS && fabs(y - o.y) < EPS && fabs(z - o.z) < EPS;
}
