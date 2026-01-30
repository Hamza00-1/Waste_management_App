#pragma once

#include <vector>

#include "domain/models/WasteEntry.h"
#include "domain/services/WasteService.h"

namespace waste::viewmodel {

class WasteViewModel {
 public:
  explicit WasteViewModel(waste::domain::WasteService &waste_service);

  const std::vector<waste::domain::WasteEntry> &entries() const;

  void refresh();
  void addEntry(const waste::domain::WasteEntry &entry);

 private:
  waste::domain::WasteService &waste_service_;
  std::vector<waste::domain::WasteEntry> entries_;
};

}
