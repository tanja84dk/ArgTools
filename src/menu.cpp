
#include "menu.h"

#include <fmt/core.h>

#include <string>
#include <vector>

#include "ArgToolsConfig.h"

using namespace Tanja84dk::argtools;

void Menu::print_title(const std::string &title) const noexcept {
    fmt::print(
        "----------------------------\n"
        "\t{}\n"
        "----------------------------\n",
        title);
}

void Menu::print_options(const std::vector<std::string> &menu_options_vector, bool is_main_menu) noexcept {
    this->menu_options_vector_ = menu_options_vector;
    this->print_options(is_main_menu);
}

void Menu::print_options(bool is_main_menu) const noexcept {
    for (std::size_t i = 0; i < this->menu_options_vector_.size(); i++) {
        fmt::print("[{}] {}\n", i + 1, this->menu_options_vector_[i]);
    }
    if (is_main_menu) {
        fmt::print(
            "[9] About\n"
            "[0] Exit\n"
            "----------------------------\n"
            "This is Version {}.{}.{}-dev\n",
            ArgTools_VERSION_MAJOR, ArgTools_VERSION_MINOR, ArgTools_VERSION_PATCH);
    } else {
        fmt::print("[0] Back\n");
    }
    fmt::print(
        "----------------------------\n"
        "Enter your choice: ");
}

void Menu::print_menu(const std::string &title, bool is_main_menu,
                      const std::vector<std::string> &menu_options_vector) const noexcept {
    this->print_title(title);
    if (menu_options_vector.empty()) {
        this->print_options(is_main_menu);
        return;
    }
    return;
}