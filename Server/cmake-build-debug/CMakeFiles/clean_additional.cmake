# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Messenger_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Messenger_autogen.dir/ParseCache.txt"
  "Messenger_autogen"
  )
endif()
