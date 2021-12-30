#include "console_command_handler.hpp"

int main(int argc, char** argv) {
  console_command_handler ccn;
  ccn.v_main(ccn.parse_console_args(argc, argv));
  return 0;
}