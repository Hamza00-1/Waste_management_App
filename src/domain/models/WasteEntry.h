#pragma once

#include <string>

namespace waste::domain {

struct WasteEntry {
  std::string id;
  std::string type;
  double weight_kg = 0.0;
  std::string created_at;
};

}
