#include "data/repositories/FileUserRepository.h"

namespace waste::data {

FileUserRepository::FileUserRepository(FileUserStore store)
    : store_(std::move(store)) {}

std::optional<waste::domain::User> FileUserRepository::findByUsername(
    const std::string &username) const {
  auto users = store_.loadUsers();
  for (const auto &user : users) {
    if (user.username == username) {
      return user;
    }
  }
  return std::nullopt;
}

void FileUserRepository::save(const waste::domain::User &user) {
  auto users = store_.loadUsers();
  users.push_back(user);
  store_.saveUsers(users);
}

std::vector<waste::domain::User> FileUserRepository::listAll() const {
  return store_.loadUsers();
}

}
