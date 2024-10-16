#include <iostream>
#include <vector>

class Dict {
public:
  std::vector<std::string> Value;
  std::vector<std::string> Key;
  int getIndex(std::string key) const {
    for (int i = 0; i < Key.size(); i++) {
      if (Key[i] == key) {
        return i;
      }
    }
    return -1;
  }
  Dict() { std::cout << ""; }
  void update(std::string key, std::string value) {
    Value.push_back(value);
    Key.push_back(key);
  }

  void update(std::string key, int value) {
    Value.push_back(std::to_string(value));
    Key.push_back(key);
  }

  int operator[](int index) {
    if (index <= Value.size()) {
      return std::stoi(Value[getIndex(std::to_string(index))]);
    } else {
      throw std::out_of_range("Key does not Exist i");
    }
  }
  std::string &operator[](std::string index) {
    if (getIndex(index) != -1) {
      return Value[getIndex(index)];
    } else {
      return Value[0];
    }
  }
};
class SList {};

std::ostream &operator<<(std::ostream &os, const Dict &d) {
  for (unsigned int i = 0; i < d.Value.size(); i++) {
    if (i == 0) {
      os << "{";
    }
    os << "\"" << d.Key[i] << "\""
       << ": " << d.Value[d.getIndex(d.Key[i])] << ", ";
    if (i == d.Value.size() - 1) {
      os << "}";
    }
  }
  return os;
}


int main() {
  Dict Car_Cost = Dict();
  Car_Cost.update("Honda", 20000);
  Car_Cost.update("BMW", 30000);
  std::cout << Car_Cost["BMW"];
}