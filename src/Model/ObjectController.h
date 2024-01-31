#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H

#include "ObjectData.h"

namespace s21 {

class ObjectController {
 public:
  void moveX(ObjectData& object, const double coefficient);
  void moveY(ObjectData& object, const double coefficient);
  void moveZ(ObjectData& object, const double coefficient);
  void changeScale(ObjectData& object, const double coefficient);
  void rotateX(ObjectData& object, double angle);
  void rotateY(ObjectData& object, double angle);
  void rotateZ(ObjectData& object, double angle);
};

}  // namespace s21

#endif  // OBJECTCONTROLLER_H
