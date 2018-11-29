set(MODULE_NAME lib1)

project(${MODULE_NAME})

find_package(Glog REQUIRED)

find_package(tinyxml2 QUIET)
if (tinyxml2_FOUND)
  add_definitions("/DWITH_TINYXML2")
  set(tinyxml2_libs PRIVATE tinyxml2::tinyxml2)
else()
  set(tinyxml2_libs "")
endif()

add_library(${MODULE_NAME}
    # headers
    include/lib1/Lib1.h
    # sources
    src/Lib1.cpp
)


target_include_directories(${MODULE_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
target_link_libraries(${MODULE_NAME} PUBLIC glog::glog ${tinyxml2_libs})

add_executable(${MODULE_NAME}_tests tests/Lib1Tests.cpp)
target_link_libraries(${MODULE_NAME}_tests gtest_main ${MODULE_NAME})
