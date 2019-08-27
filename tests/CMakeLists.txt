include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tests)
set(AME_TESTS
    test_ame
    )

foreach(entry ${AME_TESTS})
    add_executable(${entry} ${entry}.cpp ../ame16.cpp)
    add_test(${entry} ${entry})
endforeach(entry in ${AME_TESTS})
