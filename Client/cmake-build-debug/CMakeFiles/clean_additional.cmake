# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Messenger_Viewer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Messenger_Viewer_autogen.dir/ParseCache.txt"
  "Messenger_Viewer_autogen"
  )
endif()
