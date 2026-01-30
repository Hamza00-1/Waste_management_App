#pragma once

#include <string>

#include "viewmodel/AuthViewModel.h"

namespace waste::presentation {

class LoginView {
 public:
  explicit LoginView(waste::viewmodel::AuthViewModel &view_model);

  void submitLogin(const std::string &username, const std::string &password);
  void submitRegistration(const std::string &username,
                          const std::string &password);
  const std::string &statusMessage() const;

 private:
  waste::viewmodel::AuthViewModel &view_model_;
};

}
