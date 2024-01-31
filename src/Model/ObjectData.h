#ifndef OBJECTDATA_H
#define OBJECTDATA_H

#include <iostream>
#include <vector>

namespace s21 {

class ObjectData {
 public:
  size_t count_vertexes = 0;
  size_t count_facets = 0;
  std::vector<double> vertexes_arr;
  std::vector<int> vertexes_in_facets;
};

}  // namespace s21

#endif  // OBJECTDATA_H
