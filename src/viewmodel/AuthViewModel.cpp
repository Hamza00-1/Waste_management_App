#include "viewmodel/AuthViewModel.h"

namespace waste::viewmodel {

AuthViewModel::AuthViewModel(waste::domain::AuthService &auth_service)
    : auth_service_(auth_service) {}

const std::string &AuthViewModel::statusMessage() const {
  return status_message_;
}

bool AuthViewModel::isAuthenticated() const { return authenticated_; }

void AuthViewModel::login(const std::string &username,
                          const std::string &password) {
  auto result = auth_service_.authenticate(username, password);
  authenticated_ = result.success;
  status_message_ = result.message;
}

void AuthViewModel::registerUser(const std::string &username,
                                 const std::string &password) {
  auto result = auth_service_.registerUser(username, password);
  authenticated_ = result.success;
  status_message_ = result.message;
}

}
