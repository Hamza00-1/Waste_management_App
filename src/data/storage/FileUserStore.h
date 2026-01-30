#pragma once

#include <string>
#include <vector>

#include "domain/models/User.h"

namespace waste::data {

class FileUserStore {
 public:
  explicit FileUserStore(std::string path);

  std::vector<waste::domain::User> loadUsers() const;
  void saveUsers(const std::vector<waste::domain::User> &users) const;

 private:
  std::string path_;
};

}
