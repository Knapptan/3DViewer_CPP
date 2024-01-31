#include "ObjectController.h"

#include <cmath>

using namespace s21;

void ObjectController::moveX(ObjectData& object, const double coefficient) {
  for (size_t i = 0; i < object.count_vertexes * 3; i += 3) {
    object.vertexes_arr[i] += coefficient;
  }
}

void ObjectController::moveY(ObjectData& object, const double coefficient) {
  for (size_t i = 1; i < object.count_vertexes * 3; i += 3) {
    object.vertexes_arr[i] += coefficient;
  }
}

void ObjectController::moveZ(ObjectData& object, const double coefficient) {
  for (size_t i = 2; i < object.count_vertexes * 3; i += 3) {
    object.vertexes_arr[i] += coefficient;
  }
}

void ObjectController::changeScale(ObjectData& object,
                                   const double coefficient) {
  if (coefficient != 0) {
    for (size_t i = 0; i < object.count_vertexes * 3; i++) {
      object.vertexes_arr[i] *= coefficient;
    }
  }
}

void ObjectController::rotateX(ObjectData& object, double angle) {
  double oldY, oldZ;
  angle *= M_PI / 180;
  size_t i = 1;
  while (i < object.count_vertexes * 3) {
    oldY = object.vertexes_arr[i];
    oldZ = object.vertexes_arr[i + 1];
    object.vertexes_arr[i] = oldY * cos(angle) + oldZ * sin(angle);
    object.vertexes_arr[i + 1] = -oldY * sin(angle) + oldZ * cos(angle);
    i += 3;
  }
}

void ObjectController::rotateY(ObjectData& object, double angle) {
  double oldX, oldZ;
  angle *= M_PI / 180;
  size_t i = 0;
  while (i < object.count_vertexes * 3) {
    oldX = object.vertexes_arr[i];
    oldZ = object.vertexes_arr[i + 2];
    object.vertexes_arr[i] = oldX * cos(angle) + oldZ * sin(angle);
    object.vertexes_arr[i + 2] = -oldX * sin(angle) + oldZ * cos(angle);
    i += 3;
  }
}

void ObjectController::rotateZ(ObjectData& object, double angle) {
  double oldX, oldY;
  angle *= M_PI / 180;
  size_t i = 0;
  while (i < object.count_vertexes * 3) {
    oldX = object.vertexes_arr[i];
    oldY = object.vertexes_arr[i + 1];
    object.vertexes_arr[i] = oldX * cos(angle) + oldY * sin(angle);
    object.vertexes_arr[i + 1] = -oldX * sin(angle) + oldY * cos(angle);
    i += 3;
  }
}
