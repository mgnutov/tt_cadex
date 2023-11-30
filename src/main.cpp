#include "func.h"

using namespace tt;

int main() {
  std::srand(std::time(nullptr));
  const size_t COUNT = 30;

  std::vector<std::shared_ptr<Curve>> curves;
  curves.reserve(COUNT);
  for (size_t i = 0; i < COUNT; ++i) {
    int curveType = rand() % 3;
    if (curveType == 0)
      curves.push_back(std::make_shared<Circle>(getDblRnd()));
    else if (curveType == 1)
      curves.push_back(std::make_shared<Ellipse>(getDblRnd(), getDblRnd()));
    else
      curves.push_back(std::make_shared<Helixe>(getDblRnd(), getDblRnd()));
  }
  std::string title = "All curves";
  printCurves(curves, M_PI_4, title);

  std::vector<std::shared_ptr<Curve>> circles;
  circles.reserve(COUNT / 3);
  std::copy_if(curves.begin(), curves.end(), std::back_inserter(circles),
               [](const std::shared_ptr<Curve> &ptr) {
                 return dynamic_cast<Circle *>(ptr.get());
               });
  std::sort(circles.begin(), circles.end(), [](auto &c1, auto &c2) {
    return dynamic_cast<Circle *>(c1.get())->getRadius() <
           dynamic_cast<Circle *>(c2.get())->getRadius();
  });
  printCurves(circles, M_PI_4, title = "Sorted circles");

  std::clock_t start = clock();
  double sumstl = std::accumulate(
      circles.begin(), circles.end(), 0.0, [](double sum, auto circle) {
        return sum + dynamic_cast<Circle *>(circle.get())->getRadius();
      });
  std::clock_t end = clock();
  std::cout << "Total sum of radii (STL): " << sumstl
            << "\tTaken time: " << end - start << std::endl;

#ifdef PARALLEL
  start = clock();
  double sumomp = parallelComputation(circles);
  end = clock();
  std::cout << "Total sum of radii (OMP): " << sumomp
            << "\tTaken time: " << end - start << std::endl;
#endif

  return 0;
}