
#ifndef COMMON_HPP_
#define COMMON_HPP_

#include <string>

struct console_commands {
  std::string __url_s{};
  uint16_t __depth_s = 1;
  uint16_t __network_threads_s = 1;
  uint16_t __parser_threads_s = 1;
  std::string __output_s{};
};

#endif  // COMMON_HPP_
