#include "viewmodel/WasteViewModel.h"

namespace waste::viewmodel {

WasteViewModel::WasteViewModel(waste::domain::WasteService &waste_service)
    : waste_service_(waste_service) {}

const std::vector<waste::domain::WasteEntry> &WasteViewModel::entries() const {
  return entries_;
}

void WasteViewModel::refresh() { entries_ = waste_service_.listEntries(); }

void WasteViewModel::addEntry(const waste::domain::WasteEntry &entry) {
  waste_service_.addEntry(entry);
  refresh();
}

}
