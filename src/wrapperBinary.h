#ifndef TANJA84DK_ARGTOOLS_WRAPPER_BINARY_H_PRIVATE
#define TANJA84DK_ARGTOOLS_WRAPPER_BINARY_H_PRIVATE
#include <Tanja84dk/tools/tools.h>

#include "pxx.h"

namespace chipher {
namespace binary {

void encoding(void);
void encoding(const std::string &data);
void decoding_string(const std::string &inputFilename);

}  // namespace binary
}  // namespace chipher

#endif  // TANJA84DK_ARGTOOLS_WRAPPER_BINARY_H_PRIVATE