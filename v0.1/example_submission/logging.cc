
/* Copyright 2020 The MLPerf Authors. All Rights Reserved.
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
/// \file
/// \brief Example of tinyMLPerf submission logging.cc file for posix.

#include "../logging.h"

#include <stdarg.h>
#include <stdio.h>
#include <iostream>

namespace mlperf {
namespace tiny {

#ifdef CV32E40P
void LogToHost(const char* format, ...) {
  va_list args;
  char out_str[256] = "\0"; 
  va_start(args, format);
  vsprintf(out_str, format, args);
  va_end(args);

  std::cout << out_str << std::endl;
}

#else

void LogToHost(const char* format, ...) {
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
}

#endif // CV32E40P

}  // namespace tiny
}  // namespace mlperf
