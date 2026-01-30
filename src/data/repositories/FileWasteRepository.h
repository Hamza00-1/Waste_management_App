#pragma once

#include "data/repositories/WasteRepository.h"
#include "data/storage/FileWasteStore.h"

namespace waste::data {

class FileWasteRepository : public WasteRepository {
 public:
  explicit FileWasteRepository(FileWasteStore store);

  void addEntry(const waste::domain::WasteEntry &entry) override;
  std::vector<waste::domain::WasteEntry> listEntries() const override;

 private:
  FileWasteStore store_;
};

}
