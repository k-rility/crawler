
#include "console_command_handler.hpp"

console_command_handler::console_command_handler() {
  __desc.add_options()("help", "All commands")("url", po::value<std::string>(),
                                               "HTML page address")(
      "depth", po::value<uint16_t>(), "page search depth")(
      "network_threads", po::value<uint16_t>(),
      "number of threads to download pages")(
      "parser_threads", po::value<uint16_t>(),
      "number of threads to process pages")("output", po::value<std::string>(),
                                            "path to output file");
}

po::variables_map console_command_handler::parse_console_args(
    int argc, char **argv) const {
  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, __desc), vm);
  po::notify(vm);
  return vm;
}

std::string console_command_handler::print_help() const {
  std::stringstream out;
  out << __desc << std::endl;
  return out.str();
}

uint16_t console_command_handler::v_main(po::variables_map &&vm) const {
  if (vm.count("help")) {
    std::cout << print_help();
    return 0;
  }
  return 0;
}

void console_command_handler::read_commands(po::variables_map &&vm) {
  if (vm.count("url")) __commands.__url_s = vm["url"].as<std::string>();

  if (vm.count("depth")) __commands.__depth_s = vm["depth"].as<uint16_t>();

  if (vm.count("network_threads"))
    __commands.__network_threads_s = vm["network_threads"].as<uint16_t>();

  if (vm.count("parser_threads"))
    __commands.__parser_threads_s = vm["parser_threads"].as<uint16_t>();

  if (vm.count("output"))
    __commands.__output_s = vm["output"].as<std::string>();
}
