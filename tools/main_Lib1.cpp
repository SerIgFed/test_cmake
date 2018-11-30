#include "lib1/Lib1.h"

#include <boost/program_options.hpp>
#include <glog/logging.h>
#include <iostream>

int main(int argc, char **argv) {
  std::ios_base::sync_with_stdio(false);
  namespace po = boost::program_options;
  int param;

  try {
    po::options_description desc("Run Lib1");
    // clang-format off
    desc.add_options()
        ("help",                                             "Print help message")
        ("param", po::value<int>(&param)->default_value(-1), "param value (-1=default)")
        ;
    // clang-format on
    boost::program_options::variables_map vm;
    boost::program_options::store(
        boost::program_options::parse_command_line(argc, argv, desc), vm);

    if (vm.count("help")) {
      std::cout << desc << std::endl;
      return -1;
    }
    boost::program_options::notify(vm);
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return -2;
  }

  lib1::Lib1 t;
  auto res = t.dummy(param);

  LOG(INFO) << "res = " << res << std::endl;

  return 0;
}
