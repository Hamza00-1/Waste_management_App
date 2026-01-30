#include "presentation/views/DashboardView.h"

namespace waste::presentation {

void DashboardView::setGreeting(const std::string &greeting) {
  greeting_ = greeting;
}

const std::string &DashboardView::greeting() const { return greeting_; }

}
