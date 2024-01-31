#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

#include "../Model/ObjectModel.h"

namespace s21 {

class Controller {
 public:
  Controller() = default;

  void Object(const std::string& address) { model_.loadObject(address); }

  void moveX(const double coefficient) { model_.moveX(coefficient); }
  void moveY(const double coefficient) { model_.moveY(coefficient); }
  void moveZ(const double coefficient) { model_.moveZ(coefficient); }
  void changeScale(const double coefficient) {
    model_.changeScale(coefficient);
  }

  void rotateX(double angle) { model_.rotateX(angle); }
  void rotateY(double angle) { model_.rotateY(angle); }
  void rotateZ(double angle) { model_.rotateZ(angle); }

  std::vector<int> vertexes_in_facets() {
    return model_.getVertexes_in_facets();
  }
  std::vector<double> vertexes_arr() { return model_.getVertexes_arr(); }
  int count_vertexes() { return model_.getCount_vertexes(); }
  int count_facets() { return model_.getCount_facets(); }

 private:
  ObjectModel model_;
};

}  // namespace s21

#endif  // CONTROLLER_H