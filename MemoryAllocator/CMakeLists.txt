# Add source files to the executable
add_executable(CMakeTarget 
    src/FixedPool.cpp
    src/DynamicPool.cpp
    src/Manager.cpp
 "include/CommonStructs.h")

# Add include directories
target_include_directories(CMakeTarget PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Set C++ standard
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# Create a folder for header files in your IDE
source_group("Header Files" FILES
    include/FixedPool.h
    include/DynamicPool.h
    include/Manager.h
)