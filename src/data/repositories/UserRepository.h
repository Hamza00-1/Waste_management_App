#pragma once

#include <optional>
#include <vector>

#include "domain/models/User.h"

namespace waste::data {

class UserRepository {
 public:
  virtual ~UserRepository() = default;

  virtual std::optional<waste::domain::User> findByUsername(
      const std::string &username) const = 0;
  virtual void save(const waste::domain::User &user) = 0;
  virtual std::vector<waste::domain::User> listAll() const = 0;
};

}
