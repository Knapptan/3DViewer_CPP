#ifndef OBJECTMODEL_H
#define OBJECTMODEL_H

#include "ObjectController.h"
#include "ObjectData.h"
#include "ObjectParser.h"

namespace s21 {

class ObjectModel {
 public:
  ObjectModel() = default;

  void loadObject(const std::string& address) { parser_.parse(address, data_); }

  void moveX(const double coefficient) {
    controller_.moveX(data_, coefficient);
  }
  void moveY(const double coefficient) {
    controller_.moveY(data_, coefficient);
  }
  void moveZ(const double coefficient) {
    controller_.moveZ(data_, coefficient);
  }
  void changeScale(const double coefficient) {
    controller_.changeScale(data_, coefficient);
  }

  void rotateX(double angle) { controller_.rotateX(data_, angle); }
  void rotateY(double angle) { controller_.rotateY(data_, angle); }
  void rotateZ(double angle) { controller_.rotateZ(data_, angle); }

  std::vector<int> getVertexes_in_facets() { return data_.vertexes_in_facets; }
  std::vector<double> getVertexes_arr() { return data_.vertexes_arr; }
  int getCount_vertexes() { return data_.count_vertexes; }
  int getCount_facets() { return data_.count_facets; }

 private:
  ObjectController controller_;
  ObjectData data_;
  ObjectParser parser_;
};

}  // namespace s21

#endif  // OBJECTMODEL_H
