#include "ObjectParser.h"

#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace s21;

void ObjectParser::parse(const std::string& address, ObjectData& object) {
  try {
    std::ifstream file(address);
    if (!file.is_open()) {
      throw std::runtime_error("Ошибка открытия файла");
    }

    countVertAndFacet(file, object);
    if (allocMem(object) != 0) {
      throw std::runtime_error("Ошибка выделения памяти");
    }

    file.clear();
    file.seekg(0, std::ios::beg);
    if (parseVertAndFacet(file, object) != 0) {
      throw std::runtime_error("Ошибка парсинга файла");
    }

    file.close();
  } catch (const std::exception& e) {
    std::cerr << "Исключение: " << e.what() << std::endl;
    // Возможно, нужно добавить дополнительные действия при обработке исключения
  }
}

int ObjectParser::parseVertAndFacet(std::ifstream& file, ObjectData& object) {
  std::string line;
  size_t i = 0;
  size_t vertexesCount = 0;
  size_t facetsIndexCount = 0;
  while (std::getline(file, line)) {
    if (line.empty() || line[0] == '#' || line[0] == 'g') {
      continue;
    }
    if (line.compare(0, 2, "v ") == 0) {
      vertexesCount++;
      double x, y, z;
      sscanf(line.c_str(), "v %lf %lf %lf", &x, &y, &z);
      object.vertexes_arr[i++] = x;
      object.vertexes_arr[i++] = y;
      object.vertexes_arr[i++] = z;
    } else if (line.compare(0, 2, "f ") == 0) {
      int firstIndex = 0;
      int isFirstIndex = 0;
      std::istringstream facetsStream(line.substr(2));
      int facetsIntValue;
      while (facetsStream >> facetsIntValue) {
        if (facetsIntValue) {
          if (facetsIntValue < 0) {
            facetsIntValue += vertexesCount + 1;
          }
          object.vertexes_in_facets[facetsIndexCount] = facetsIntValue;

          if (!isFirstIndex) {
            firstIndex = facetsIntValue;
            isFirstIndex = 1;
          } else {
            object.vertexes_in_facets[++facetsIndexCount] = facetsIntValue;
          }
          facetsIndexCount++;
        }
      }

      object.vertexes_in_facets[facetsIndexCount] = firstIndex;
      facetsIndexCount++;
    }
  }
  return (object.vertexes_arr.empty() || object.vertexes_in_facets.empty());
}

void ObjectParser::countVertAndFacet(std::ifstream& file, ObjectData& object) {
  std::string line;
  while (std::getline(file, line)) {
    if (line.compare(0, 2, "v ") == 0) {
      object.count_vertexes++;
    } else if (line.compare(0, 2, "f ") == 0) {
      std::istringstream facetsStream(line.substr(2));
      int vertexIndex;
      while (facetsStream >> vertexIndex) {
        if (vertexIndex) {
          object.count_facets++;
        }
      }
    }
  }
}

int ObjectParser::allocMem(ObjectData& object) {
  object.vertexes_arr.resize(object.count_vertexes * 3);
  object.vertexes_in_facets.resize(object.count_facets * 2);
  return object.vertexes_arr.empty() || object.vertexes_in_facets.empty();
  ;
}
