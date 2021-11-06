#include "hello_world.hpp"
#include "world.hpp"

std::string say_hello_world() {

#ifdef MY_DEFINITION
#pragma message("inside hello_world.cpp")
#endif

  return "Hello " + say_world();
}
