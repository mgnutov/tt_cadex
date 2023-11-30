#include "func.h"

double tt::getDblRnd() { return rand() / 1e6; }

void tt::printCurves(const std::vector<std::shared_ptr<tt::Curve>> &curves,
                     const double t, const std::string &title) {
  std::cout << title << std::endl;
  for (const auto &curve : curves) {
    auto pnt = curve->getPoint(t);
    auto der = curve->getDerivative(t);
    std::printf(
        "%15s when t=%.2lf    coordinates: (%8.2lf, %8.2lf, %8.2lf),    first "
        "derivative: (%8.2lf, %8.2lf, %8.2lf)\n",
        typeid(*curve).name(), t, pnt.x, pnt.y, pnt.z, der.x, der.y, der.z);
  }
  std::cout << std::endl;
}

#ifdef PARALLEL
double tt::parallelComputation(
    const std::vector<std::shared_ptr<tt::Curve>> &circles) {
  double result = 0;
#pragma omp parallel shared(circles) reduction(+ : result) num_threads(2)
  {
#pragma omp for
    for (const auto &circle : circles)
      // cppcheck-suppress useStlAlgorithm
      result += dynamic_cast<Circle *>(circle.get())->getRadius();
  }
  return result;
}
#endif
