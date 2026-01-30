#pragma once

#include "data/repositories/UserRepository.h"
#include "data/storage/FileUserStore.h"

namespace waste::data {

class FileUserRepository : public UserRepository {
 public:
  explicit FileUserRepository(FileUserStore store);

  std::optional<waste::domain::User> findByUsername(
      const std::string &username) const override;
  void save(const waste::domain::User &user) override;
  std::vector<waste::domain::User> listAll() const override;

 private:
  FileUserStore store_;
};

}
