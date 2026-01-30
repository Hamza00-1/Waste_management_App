#pragma once

#include <vector>

#include "domain/models/WasteEntry.h"

namespace waste::data {

class WasteRepository {
 public:
  virtual ~WasteRepository() = default;

  virtual void addEntry(const waste::domain::WasteEntry &entry) = 0;
  virtual std::vector<waste::domain::WasteEntry> listEntries() const = 0;
};

}
