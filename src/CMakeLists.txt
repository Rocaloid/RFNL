aux_source_directory(./DFT SRC_LIST)
aux_source_directory(./FMath SRC_LIST)
aux_source_directory(./FWindow SRC_LIST)
aux_source_directory(./Interp SRC_LIST)
aux_source_directory(./Vec SRC_LIST)
aux_source_directory(. SRC_LIST)

set(CMAKE_C_FLAGS "-Ofast -I${TopDir}/src")

add_library(RFNL SHARED ${SRC_LIST})
target_include_directories(RFNL PUBLIC "${CMAKE_SOURCE_DIR}/src")
TARGET_LINK_LIBRARIES(RFNL RUtil2)

install(FILES DFT/DFT.h
              DFT/BitRev.h
              DFT/_DFT_Gnrc.h
              DFT/_DFT_Arch.h
              DFT/_BitRev_Gnrc.h
              DESTINATION /usr/include/RFNL/DFT/)
install(FILES FMath/FMath.h
              FMath/_FMath_Comm.h
              FMath/_FMath_Gnrc.h
              FMath/_FMath_Pk_Gnrc.h
              DESTINATION /usr/include/RFNL/FMath/)
install(FILES Vec/Vec.h
              Vec/_VecBasic_Gnrc.h
              Vec/_VecMath_Gnrc.h
              DESTINATION /usr/include/RFNL/Vec/)
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
              DESTINATION /usr/include/RFNL/Interp/)
install(FILES FWindow/FWindow.h
              FWindow/FWindow_Gnrc.h
              FWindow/_FWindow_Gnrc.h
              DESTINATION /usr/include/RFNL/FWindow/)
install(FILES Include/RFNL.h
              DESTINATION /usr/include/)

if(CYGWIN)
    MESSAGE("")
    MESSAGE("=======     BEGIN WARNING     =======")
    MESSAGE("You are building this project in Cygwin!")
    MESSAGE("All static libraries will be installed in /usr/lib!")
    MESSAGE("And shared libraries will be installed in /usr/bin!")
    MESSAGE("=======      END WARNING      =======")
    MESSAGE("")
    SET_TARGET_PROPERTIES(RFNL PROPERTIES CMAKE_SHARED_LIBRARY_PREFIX "cyg")
    SET(CMAKE_FIND_LIBRARY_SUFFIXES ".dll" ".dll.a" ".a")
    install(TARGETS RFNL 
            ARCHIVE DESTINATION /usr/lib
            LIBRARY DESTINATION /usr/bin
            COMPONENT library)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    install(TARGETS RFNL 
            ARCHIVE DESTINATION /usr/lib64
            LIBRARY DESTINATION /usr/lib64
            COMPONENT library)
else()
    install(TARGETS RFNL 
            ARCHIVE DESTINATION /usr/lib
            LIBRARY DESTINATION /usr/lib
            COMPONENT library)
endif()