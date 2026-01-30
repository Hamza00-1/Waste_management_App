#include "presentation/views/LoginView.h"

namespace waste::presentation {

LoginView::LoginView(waste::viewmodel::AuthViewModel &view_model)
    : view_model_(view_model) {}

void LoginView::submitLogin(const std::string &username,
                            const std::string &password) {
  view_model_.login(username, password);
}

void LoginView::submitRegistration(const std::string &username,
                                   const std::string &password) {
  view_model_.registerUser(username, password);
}

const std::string &LoginView::statusMessage() const {
  return view_model_.statusMessage();
}

}
