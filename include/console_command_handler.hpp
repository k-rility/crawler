

#ifndef CONSOLE_COMMAND_HANDLER_HPP_
#define CONSOLE_COMMAND_HANDLER_HPP_

// boost

#include <boost/program_options.hpp>

// std

#include <iostream>

#include "common.hpp"

namespace po = boost::program_options;

// class that handles commands in the terminal

class console_command_handler {
 public:
  console_command_handler(const console_command_handler &) = delete;

  console_command_handler();

  po::variables_map parse_console_args(int argc, char **argv) const;

  std::string print_help() const;

  uint16_t v_main(po::variables_map &&) const;

  void read_commands(po::variables_map &&);

 private:
  po::options_description __desc{"Allowed options"};
  console_commands __commands;
};

#endif  // CONSOLE_COMMAND_HANDLER_HPP_
