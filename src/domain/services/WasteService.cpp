#include "domain/services/WasteService.h"

#include "data/repositories/WasteRepository.h"

namespace waste::domain {

WasteService::WasteService(waste::data::WasteRepository &waste_repository)
    : waste_repository_(waste_repository) {}

void WasteService::addEntry(const WasteEntry &entry) {
  waste_repository_.addEntry(entry);
}

std::vector<WasteEntry> WasteService::listEntries() const {
  return waste_repository_.listEntries();
}

}
