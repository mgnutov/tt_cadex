#ifndef TT_LIBS_CURVES_H_
#define TT_LIBS_CURVES_H_

#include <cmath>
#include <stdexcept>

#define EPS 1e-6

namespace tt {

struct Point {
  double x, y, z;
  bool operator==(const Point& o) const&;
};

class Curve {
 public:
  virtual ~Curve() = 0;
  virtual Point getPoint(const double t) const& = 0;
  virtual Point getDerivative(const double t) const& = 0;

};  // class Curve

class Circle : public Curve {
 public:
  explicit Circle(double radius_);
  Point getPoint(const double t) const& override;
  Point getDerivative(const double t) const& override;

 private:
  double radius_;

};  // class Circle

class Ellipse : public Curve {
 public:
  explicit Ellipse(double radiusX, double radiusY);
  Point getPoint(const double t) const& override;
  Point getDerivative(const double t) const& override;

 private:
  double radiusX_;
  double radiusY_;

};  // class Ellipse

class Helixe : public Curve {
 public:
  explicit Helixe(double radius, double step);
  Point getPoint(const double t) const& override;
  Point getDerivative(const double t) const& override;

 private:
  double radius_;
  double step_;

};  // class Helixe

}  // namespace tt

#endif  // TT_LIBS_CURVES_H_