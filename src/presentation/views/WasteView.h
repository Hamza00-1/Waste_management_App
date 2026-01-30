#pragma once

#include <vector>

#include "domain/models/WasteEntry.h"
#include "viewmodel/WasteViewModel.h"

namespace waste::presentation {

class WasteView {
 public:
  explicit WasteView(waste::viewmodel::WasteViewModel &view_model);

  void refresh();
  void addEntry(const waste::domain::WasteEntry &entry);
  const std::vector<waste::domain::WasteEntry> &entries() const;

 private:
  waste::viewmodel::WasteViewModel &view_model_;
};

}
