#pragma once

#include <vector>

#include "domain/models/WasteEntry.h"

namespace waste::data {
class WasteRepository;
}

namespace waste::domain {

class WasteService {
 public:
  explicit WasteService(waste::data::WasteRepository &waste_repository);

  void addEntry(const WasteEntry &entry);
  std::vector<WasteEntry> listEntries() const;

 private:
  waste::data::WasteRepository &waste_repository_;
};

}
