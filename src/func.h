#ifndef TT_FUNC_H_
#define TT_FUNC_H_

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

#include "lib/curves.h"

namespace tt {

double getDblRnd();
void printCurves(const std::vector<std::shared_ptr<tt::Curve>> &curves,
                 const double t, const std::string &title);

}  // namespace tt

#endif  // TT_FUNC_H_