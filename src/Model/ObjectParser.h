#ifndef OBJECTPARSER_H
#define OBJECTPARSER_H

#include <fstream>

#include "ObjectData.h"

namespace s21 {

class ObjectParser {
 public:
  void parse(const std::string& address, ObjectData& object);

 private:
  void countVertAndFacet(std::ifstream& file, ObjectData& object);
  int allocMem(ObjectData& object);
  int parseVertAndFacet(std::ifstream& file, ObjectData& object);
};

}  // namespace s21

#endif  // OBJECTPARSER_H
