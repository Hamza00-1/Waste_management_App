#include "domain/services/AuthService.h"

#include <sstream>

#include "data/repositories/UserRepository.h"
#include "domain/models/User.h"

namespace waste::domain {

AuthService::AuthService(waste::data::UserRepository &user_repository)
    : user_repository_(user_repository) {}

AuthResult AuthService::authenticate(const std::string &username,
                                     const std::string &password) {
  auto user = user_repository_.findByUsername(username);
  if (!user.has_value()) {
    return {false, "User not found."};
  }

  if (user->password_hash != hashPassword(password)) {
    return {false, "Invalid credentials."};
  }

  return {true, "Authenticated."};
}

AuthResult AuthService::registerUser(const std::string &username,
                                     const std::string &password) {
  auto existing = user_repository_.findByUsername(username);
  if (existing.has_value()) {
    return {false, "Username already exists."};
  }

  waste::domain::User user{username, hashPassword(password)};
  user_repository_.save(user);
  return {true, "User registered."};
}

std::string AuthService::hashPassword(const std::string &password) const {
  std::ostringstream stream;
  stream << "hash:" << password;
  return stream.str();
}

}
