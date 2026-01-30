#include "presentation/views/WasteView.h"

namespace waste::presentation {

WasteView::WasteView(waste::viewmodel::WasteViewModel &view_model)
    : view_model_(view_model) {}

void WasteView::refresh() { view_model_.refresh(); }

void WasteView::addEntry(const waste::domain::WasteEntry &entry) {
  view_model_.addEntry(entry);
}

const std::vector<waste::domain::WasteEntry> &WasteView::entries() const {
  return view_model_.entries();
}

}
