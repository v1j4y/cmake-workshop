#include "greeting.hpp"
#include "hello_world.hpp"

std::string say_greeting() {

#ifdef MY_DEFINITION
#pragma message("inside greeting.cpp")
#endif

  return say_hello_world();
}
