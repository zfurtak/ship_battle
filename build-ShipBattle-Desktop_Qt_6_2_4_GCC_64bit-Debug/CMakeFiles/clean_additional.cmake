# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ShipBattle_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ShipBattle_autogen.dir/ParseCache.txt"
  "ShipBattle_autogen"
  )
endif()
