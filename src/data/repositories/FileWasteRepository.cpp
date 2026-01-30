#include "data/repositories/FileWasteRepository.h"

namespace waste::data {

FileWasteRepository::FileWasteRepository(FileWasteStore store)
    : store_(std::move(store)) {}

void FileWasteRepository::addEntry(const waste::domain::WasteEntry &entry) {
  auto entries = store_.loadEntries();
  entries.push_back(entry);
  store_.saveEntries(entries);
}

std::vector<waste::domain::WasteEntry> FileWasteRepository::listEntries() const {
  return store_.loadEntries();
}

}
