#pragma once

#include <string>

namespace waste::data {
class UserRepository;
}

namespace waste::domain {

struct AuthResult {
  bool success = false;
  std::string message;
};

class AuthService {
 public:
  explicit AuthService(waste::data::UserRepository &user_repository);

  AuthResult authenticate(const std::string &username,
                          const std::string &password);
  AuthResult registerUser(const std::string &username,
                          const std::string &password);

 private:
  std::string hashPassword(const std::string &password) const;

  waste::data::UserRepository &user_repository_;
};

}
