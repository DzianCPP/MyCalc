# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MyCalc_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MyCalc_autogen.dir\\ParseCache.txt"
  "MyCalc_autogen"
  )
endif()
