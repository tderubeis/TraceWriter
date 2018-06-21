cmake_minimum_required( VERSION 3.9 )

project( TraceWriter VERSION 1.0 )

include_directories ("${PROJECT_SOURCE_DIR}/include")
set(SRCFILES "${PROJECT_SOURCE_DIR}/src")

# add the executable
add_executable(TraceWriter "${SRCFILES}/TraceWriter.cpp")

# install
install (TARGETS TraceWriter DESTINATION bin)
