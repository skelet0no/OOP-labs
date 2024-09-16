# CMake generated Testfile for 
# Source directory: /workspaces/OOP-labs/laboratory-1
# Build directory: /workspaces/OOP-labs/laboratory-1/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyProjectTests "/workspaces/OOP-labs/laboratory-1/build/tests")
set_tests_properties(MyProjectTests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/OOP-labs/laboratory-1/CMakeLists.txt;34;add_test;/workspaces/OOP-labs/laboratory-1/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
