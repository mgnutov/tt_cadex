#include "func.h"

double tt::getDblRnd() { return rand() / 1e6; }

void tt::printCurves(const std::vector<std::shared_ptr<tt::Curve>> &curves,
                     const double t, std::string title) {
  std::cout << title << std::endl;
  for (const auto &curve : curves) {
    auto pnt = (*curve).getPoint(t);
    auto der = (*curve).getDerivative(t);
    std::printf(
        "%15s when t=%.2lf    coordinates: (%8.2lf, %8.2lf, %8.2lf),    first "
        "derivative: (%8.2lf, %8.2lf, %8.2lf)\n",
        typeid(*curve).name(), t, pnt.x, pnt.y, pnt.z, der.x, der.y, der.z);
  }
  std::cout << std::endl;
}
