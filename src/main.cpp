#include "func.h"

using namespace tt;

int main() {
  std::srand(std::time(nullptr));

  std::vector<std::shared_ptr<Curve>> curves;
  for (size_t i = 0; i < 20; ++i) {
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
  std::copy_if(curves.begin(), curves.end(), std::back_inserter(circles),
               [](const std::shared_ptr<Curve> &ptr) {
                 return typeid(*ptr).name() == typeid(Circle).name();
               });
  std::sort(circles.begin(), circles.end(), [](auto &c1, auto &c2) {
    return (*dynamic_cast<Circle *>(c1.get())).getRadius() <
           (*dynamic_cast<Circle *>(c2.get())).getRadius();
  });
  printCurves(circles, M_PI_4, title = "Sorted circles");

  double sum = std::accumulate(
      circles.begin(), circles.end(), 0, [](double sum, auto circle) {
        return sum + (*dynamic_cast<Circle *>(circle.get())).getRadius();
      });

  std::cout << "Total sum of radii: " << sum << std::endl;

  return 0;
}