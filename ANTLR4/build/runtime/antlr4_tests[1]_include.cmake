if(EXISTS "/workspaces/fish/ANTLR4/build/runtime/antlr4_tests[1]_tests.cmake")
  include("/workspaces/fish/ANTLR4/build/runtime/antlr4_tests[1]_tests.cmake")
else()
  add_test(antlr4_tests_NOT_BUILT antlr4_tests_NOT_BUILT)
endif()
