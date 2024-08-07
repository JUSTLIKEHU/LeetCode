#pragma once

#include "easy/solution.h"

#define REGISTER_SOLUTION_EASY_FUNCTION(global_obj, func_name, func_ptr) \
  do {                                                       \
    global_obj.registerFunction(#func_name, func_ptr);    \
  } while (0) \

#define REGISTER_SOLUTION_EASY_STATIC_FUNCTION(global_obj, func_name, func_ptr) \
  do {                                                             \
    global_obj.registerStaticFunction(#func_name, func_ptr);    \
  } while (0)
  