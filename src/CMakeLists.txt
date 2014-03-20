aux_source_directory(./DFT SRC_LIST)
aux_source_directory(./FMath SRC_LIST)
aux_source_directory(./FWindow SRC_LIST)
aux_source_directory(./Interp SRC_LIST)
aux_source_directory(./Vec SRC_LIST)
aux_source_directory(. SRC_LIST)

set(CMAKE_C_FLAGS "-Ofast -I${TopDir}/src")

add_library(RFNL SHARED ${SRC_LIST})
target_include_directories(RFNL PUBLIC "${CMAKE_SOURCE_DIR}/src")

install(FILES DFT/DFT.h
              DFT/BitRev.h
              DFT/_DFT_Gnrc.h
              DFT/_DFT_Arch.h
              DFT/_BitRev_Gnrc.h
              DESTINATION /usr/include/RFNL/DFT/)
install(FILES FMath/FMath.h
              FMath/_FMath_Comm.h
              DESTINATION /usr/include/RFNL/FMath/)
install(FILES Vec/Vec.h
              Vec/_VecBasic_Gnrc.h
              Vec/_VecMath_Gnrc.h
              DESTINATION /usr/include/RFNL/Vec/)
install(FILES Include/RFNL.h
              DESTINATION /usr/include/)

install(TARGETS RFNL LIBRARY DESTINATION /usr/lib)

