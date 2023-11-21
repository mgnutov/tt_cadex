#include "curves.h"

tt::Curve::~Curve() {}

tt::Circle::Circle(double r) : radius_(r) {
  if (radius_ < 0) throw std::invalid_argument("Radius must be positive");
}

tt::Coordinates tt::Circle::getPoint(const double t) const& {
  return Coordinates{radius_ * cos(t), radius_ * sin(t), 0};
}

tt::Coordinates tt::Circle::getDerivative(const double t) const& {
  return Coordinates{-radius_ * sin(t), radius_ * cos(t), 0};
}

double tt::Circle::getRadius() const& { return radius_; }

tt::Ellipse::Ellipse(double rx, double ry) : radiusX_(rx), radiusY_(ry) {
  if (radiusX_ < 0 || radiusY_ < 0)
    throw std::invalid_argument("Radius must be positive");
}

tt::Coordinates tt::Ellipse::getPoint(const double t) const& {
  return Coordinates{radiusX_ * cos(t), radiusY_ * sin(t), 0};
}

tt::Coordinates tt::Ellipse::getDerivative(const double t) const& {
  return Coordinates{-radiusX_ * sin(t), radiusY_ * cos(t), 0};
}

tt::Helixe::Helixe(double radius, double step) : radius_(radius), step_(step) {
  if (radius_ < 0) throw std::invalid_argument("Radius must be positive");
}

tt::Coordinates tt::Helixe::getPoint(const double t) const& {
  return Coordinates{radius_ * cos(t), radius_ * sin(t),
                     step_ * t / (2 * M_PI)};
}

tt::Coordinates tt::Helixe::getDerivative(const double t) const& {
  return Coordinates{-radius_ * sin(t), radius_ * cos(t), step_ / (2 * M_PI)};
}

bool tt::Coordinates::operator==(const Coordinates& o) const& {
  return fabs(x - o.x) < EPS && fabs(y - o.y) < EPS && fabs(z - o.z) < EPS;
}
