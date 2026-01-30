#pragma once

#include <string>

#include "domain/services/AuthService.h"

namespace waste::viewmodel {

class AuthViewModel {
 public:
  explicit AuthViewModel(waste::domain::AuthService &auth_service);

  const std::string &statusMessage() const;
  bool isAuthenticated() const;

  void login(const std::string &username, const std::string &password);
  void registerUser(const std::string &username, const std::string &password);

 private:
  waste::domain::AuthService &auth_service_;
  bool authenticated_ = false;
  std::string status_message_;
};

}
