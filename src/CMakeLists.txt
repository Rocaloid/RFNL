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
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/RFNL/DFT/)
install(FILES FMath/FMath.h
              FMath/_FMath_Comm.h
              FMath/_FMath_Gnrc.h
              FMath/_FMath_Pk_Gnrc.h
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/RFNL/FMath/)
install(FILES Vec/Vec.h
              Vec/_VecBasic_Gnrc.h
              Vec/_VecMath_Gnrc.h
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/RFNL/Vec/)
install(FILES Interp/Interp.h
              Interp/InterpBase_Gnrc.h
              Interp/_InterpBase_Gnrc.h
              Interp/GenPeak_Gnrc.h
              Interp/_GenPeak_Gnrc.h
              Interp/MatchInterp_Gnrc.h
              Interp/_MatchInterp_Gnrc.h
              Interp/MapStretch_Gnrc.h
              Interp/_MapStretch_Gnrc.h
              Interp/OffsetFetch_Gnrc.h
              Interp/_OffsetFetch_Gnrc.h
              Interp/Resample_Gnrc.h
              Interp/_Resample_Gnrc.h
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/RFNL/Interp/)
install(FILES FWindow/FWindow.h
              FWindow/FWindow_Gnrc.h
              FWindow/_FWindow_Gnrc.h
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/RFNL/FWindow/)
install(FILES Include/RFNL.h
              DESTINATION ${CMAKE_INSTALL_PREFIX}/include/)

if(CYGWIN OR WIN32)
    message(STATUS "You are compiling this project as COFF.")
    install(TARGETS RFNL 
            ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
            LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
            RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
            COMPONENT library)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(STATUS "You are compiling this project as 64bit.")
    install(TARGETS RFNL 
            ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib64
            LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib64
            COMPONENT library)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    message(STATUS "You are compiling this project as 32bit.")
    install(TARGETS RFNL 
            ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
            LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
            COMPONENT library)
else()
    message(FATAL_ERROR "Your system is unsupported!")
endif()