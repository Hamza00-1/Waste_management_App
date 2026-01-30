#pragma once

#include <string>
#include <vector>

#include "domain/models/WasteEntry.h"

namespace waste::data {

class FileWasteStore {
 public:
  explicit FileWasteStore(std::string path);

  std::vector<waste::domain::WasteEntry> loadEntries() const;
  void saveEntries(const std::vector<waste::domain::WasteEntry> &entries) const;

 private:
  std::string path_;
};

}
