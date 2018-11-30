#ifndef LIB1
#define LIB1

#include <glog/logging.h>

namespace lib1 {

struct Lib1 {
  Lib1() { LOG(INFO) << "hello" << std::endl; }

  int dummy(int param = 0) const;
};

} // namespace lib1

#endif
