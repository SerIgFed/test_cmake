#include "lib1/Lib1.h"

#ifdef WITH_TINYXML2
#include <tinyxml2.h>
#endif

namespace lib1 {

int Lib1::dummy(int param) const {
  LOG(INFO) << "dummy(" << param << ")" << std::endl;

#ifdef WITH_TINYXML2
  const auto tiny_flag = "ON";
#else
  const auto tiny_flag = "OFF";
#endif

  LOG(INFO) << "WITH_TINYXML2 is " << tiny_flag << std::endl;

  return param;
}

} // namespace lib1
