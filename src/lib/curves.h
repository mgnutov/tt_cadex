#ifndef TT_LIB_CURVES_H_
#define TT_LIB_CURVES_H_

#include <cmath>
#include <stdexcept>

#define EPS 1e-6

namespace tt {

struct Coordinates {
  double x, y, z;
  bool operator==(const Coordinates& o) const&;
};

class Curve {
 public:
  virtual ~Curve() = 0;
  virtual Coordinates getPoint(const double t) const& = 0;
  virtual Coordinates getDerivative(const double t) const& = 0;

};  // class Curve

class Circle : public Curve {
 public:
  explicit Circle(double radius_);
  Coordinates getPoint(const double t) const& override;
  Coordinates getDerivative(const double t) const& override;
  double getRadius() const&;

 private:
  double radius_;

};  // class Circle

class Ellipse : public Curve {
 public:
  explicit Ellipse(double radiusX, double radiusY);
  Coordinates getPoint(const double t) const& override;
  Coordinates getDerivative(const double t) const& override;

 private:
  double radiusX_;
  double radiusY_;

};  // class Ellipse

class Helixe : public Curve {
 public:
  explicit Helixe(double radius, double step);
  Coordinates getPoint(const double t) const& override;
  Coordinates getDerivative(const double t) const& override;

 private:
  double radius_;
  double step_;

};  // class Helixe

}  // namespace tt

#endif  // TT_LIB_CURVES_H_