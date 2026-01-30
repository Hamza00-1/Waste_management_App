#pragma once

#include <string>

namespace waste::domain {

struct User {
  std::string username;
  std::string password_hash;
};

}
