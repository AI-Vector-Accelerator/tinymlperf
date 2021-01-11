
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
/// \brief Example of tinyMLPerf submission timers.cc file for posix.

#include "../timers.h"

#include <time.h>

namespace mlperf {
namespace tiny {

int32_t TicksPerSecond() { return CLOCKS_PER_SEC; }


#ifdef CV32E40P
unsigned long getCycles(void){
	unsigned long numberOfCyclesExecuted;
	asm volatile ("rdcycle %0" : "=r"(numberOfCyclesExecuted));
	return numberOfCyclesExecuted;
}

int32_t CurrentTimeTicks() { return static_cast<int32_t>(getCycles()); }

#else 
int32_t CurrentTimeTicks() { return static_cast<int32_t>(clock()); }
#endif

}  // namespace tiny
}  // namespace mlperf
