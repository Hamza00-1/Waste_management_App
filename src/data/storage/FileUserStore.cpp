#include "data/storage/FileUserStore.h"

#include <fstream>
#include <sstream>

namespace waste::data {

FileUserStore::FileUserStore(std::string path) : path_(std::move(path)) {}

std::vector<waste::domain::User> FileUserStore::loadUsers() const {
  std::vector<waste::domain::User> users;
  std::ifstream file(path_);
  if (!file.is_open()) {
    return users;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream stream(line);
    std::string username;
    std::string password_hash;
    if (std::getline(stream, username, ':') &&
        std::getline(stream, password_hash)) {
      users.push_back({username, password_hash});
    }
  }

  return users;
}

void FileUserStore::saveUsers(
    const std::vector<waste::domain::User> &users) const {
  std::ofstream file(path_, std::ios::trunc);
  for (const auto &user : users) {
    file << user.username << ':' << user.password_hash << '\n';
  }
}

}
