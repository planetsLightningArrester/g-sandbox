# Sum lib
set(This Sum)

# Add sum.cpp and sum.hpp as libraries of the tests which imports the "Sum" lib
set(Headers
  sum.hpp
)

set(Sources
  sum.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

# Library links' names => GTest and the ones defined here on $This
set(Links gtest_main ${This})

# List of the tests
set(TestsName SingleArgument MultipleArguments InvalidArgument)

foreach(TestName IN LISTS TestsName)
  # The test command
  add_executable(${TestName} test/${TestName}.cpp)
  # Add the libs to the test
  target_link_libraries(${TestName} PUBLIC ${Links})
  # Add the test
  add_test(NAME ${TestName} COMMAND ${TestName})
endforeach()
