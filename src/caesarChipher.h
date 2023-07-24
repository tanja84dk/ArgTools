#ifndef TANJA84DK_ARGTOOLS_CEASAR_CHIPHER_H_PRIVATE
#define TANJA84DK_ARGTOOLS_CEASAR_CHIPHER_H_PRIVATE
#include <Tanja84dk/tools/tools.h>

#include "pxx.h"

namespace chipher {
namespace ceasar {

void encoding(const int chipher_shift_key, const std::string &input_data);
void decoding(const int chipher_shift_key, const std::string &input_data);

void decoding_brute_force(const std::string &input_data);

}  // namespace ceasar
}  // namespace chipher

#endif  // TANJA84DK_ARGTOOLS_CEASAR_CHIPHER_H_PRIVATE