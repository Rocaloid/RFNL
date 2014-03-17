aux_source_directory(./DFT SRC_LIST)
aux_source_directory(./FMath SRC_LIST)
aux_source_directory(./FWindow SRC_LIST)
aux_source_directory(./Interp SRC_LIST)
aux_source_directory(./Vec SRC_LIST)

set(CMAKE_C_FLAGS "-Ofast -I${TopDir}/src")

add_library(RFNL SHARED ${SRC_LIST})
target_include_directories(RFNL PUBLIC "${CMAKE_SOURCE_DIR}/src")

install(FILES DFT/DFT.h
              DFT/BitRev.h
              DFT/_DFT_Generic.h
              DFT/_BitRev_Generic.h
              DESTINATION /usr/include/RFNL/DFT/)
install(FILES Include/RFNL.h
              DESTINATION /usr/include/)

install(TARGETS RFNL LIBRARY DESTINATION /usr/lib)

