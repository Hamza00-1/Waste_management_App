#pragma once

#include <string>

namespace waste::presentation {

class DashboardView {
 public:
  void setGreeting(const std::string &greeting);
  const std::string &greeting() const;

 private:
  std::string greeting_;
};

}
