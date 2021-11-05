#include "world.hpp"

std::string say_world() {

#ifdef MY_DEFINITION
#pragma message("inside world.cpp")
#endif

  return "world";
}
