aux_source_directory(./TestDFT Test1)
add_executable(TestDFT ${Test1})
target_link_libraries(TestDFT RFNL)
target_link_libraries(TestDFT RUtil2)
target_link_libraries(TestDFT m)

aux_source_directory(./TestVec Test2)
add_executable(TestVec ${Test2})
target_link_libraries(TestVec RFNL)
target_link_libraries(TestVec RUtil2)
target_link_libraries(TestVec m)

aux_source_directory(./TestMath Test3)
add_executable(TestMath ${Test3})
target_link_libraries(TestMath RFNL)
target_link_libraries(TestMath RUtil2)
target_link_libraries(TestMath m)

add_test(TestDFT TestDFT)
add_test(TestVec TestVec)
add_test(TestMath TestMath)

get_filename_component(TestDir "." ABSOLUTE)
get_filename_component(TopDir ${CMAKE_SOURCE_DIR} ABSOLUTE)
set(CMAKE_C_FLAGS "-Ofast -I${TestDir}/TestDFT -I${TopDir}/src")

