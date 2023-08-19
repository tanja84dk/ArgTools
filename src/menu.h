#ifndef TANJA84DK_ARGTOOLS_MENU_H_PRIVATE
#define TANJA84DK_ARGTOOLS_MENU_H_PRIVATE
#include <fmt/core.h>

#include <iostream>
#include <vector>

#include "pxx.h"

namespace Tanja84dk {
namespace argtools {

class Menu {
   public:
    Menu() noexcept = default;
    Menu(const std::vector<std::string> &menu_options_vector) { this->menu_options_vector_ = menu_options_vector; };
    void print_title(const std::string &title) const noexcept;

    void print_menu(const std::string &title, bool is_main_menu = false,
                    const std::vector<std::string> &menu_options_vector = {}) const noexcept;

    void print_options(bool is_main_menu = false) const noexcept;
    void print_options(const std::vector<std::string> &menu_options_vector, bool is_main_menu = false) noexcept;

   private:
    std::string menu_title_ = {};
    std::vector<std::string> menu_options_vector_{};
};

}  // namespace argtools
}  // namespace Tanja84dk

#endif  // TANJA84DK_ARGTOOLS_MENU_H_PRIVATE