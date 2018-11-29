project(tools)

find_package(Boost COMPONENTS program_options REQUIRED)
find_package(Glog REQUIRED)

add_executable(run_Lib1 main_Lib1.cpp)
target_link_libraries(run_Lib1 lib1 Boost::program_options glog::glog)
