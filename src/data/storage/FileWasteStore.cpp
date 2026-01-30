#include "data/storage/FileWasteStore.h"

#include <fstream>
#include <sstream>

namespace waste::data {

FileWasteStore::FileWasteStore(std::string path) : path_(std::move(path)) {}

std::vector<waste::domain::WasteEntry> FileWasteStore::loadEntries() const {
  std::vector<waste::domain::WasteEntry> entries;
  std::ifstream file(path_);
  if (!file.is_open()) {
    return entries;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream stream(line);
    waste::domain::WasteEntry entry;
    std::string weight;
    if (std::getline(stream, entry.id, ',') &&
        std::getline(stream, entry.type, ',') &&
        std::getline(stream, weight, ',') &&
        std::getline(stream, entry.created_at)) {
      entry.weight_kg = std::stod(weight);
      entries.push_back(entry);
    }
  }

  return entries;
}

void FileWasteStore::saveEntries(
    const std::vector<waste::domain::WasteEntry> &entries) const {
  std::ofstream file(path_, std::ios::trunc);
  for (const auto &entry : entries) {
    file << entry.id << ',' << entry.type << ',' << entry.weight_kg << ','
         << entry.created_at << '\n';
  }
}

}
