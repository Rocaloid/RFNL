aux_source_directory(./TestDFT Test1)
add_executable(TestDFT ${Test1})
target_link_libraries(TestDFT RFNL)
target_link_libraries(TestDFT RUtil2)
target_link_libraries(TestDFT m)

add_test(TestDFT TestDFT)

get_filename_component(TestDir "." ABSOLUTE)
get_filename_component(TopDir ${CMAKE_SOURCE_DIR} ABSOLUTE)
set(CMAKE_C_FLAGS "-I${TestDir}/TestDFT -I${TopDir}/src")

