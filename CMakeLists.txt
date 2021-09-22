cmake_minimum_required(VERSION 3.5)

project(InstrPanel LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -eexecution-charset:utf-8")


# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(InstrPanel SHARED
    main.cpp
    mainwindow.cpp
	instrpanel_ybb.cpp
	instrpanel_dlc_a.cpp
	instrpanel_jsc.cpp
	instrpanel_zdc.cpp
	instrpanel_jsc_c.cpp
	instrpanel_ybb_b.cpp
	instrpanel_dlc_b.cpp
	instrpanel_jsc_b.cpp
	topwindow.cpp
	panelbase.cpp
	panelveri0.cpp
	panelveri1.cpp
	panelveri2.cpp
	panelveri3.cpp
	protocol.cpp
	uartctl.cpp
    mainwindow.h
	common.h
	rsc.qrc
	)
else()
  add_executable(InstrPanel
    main.cpp
    mainwindow.cpp
	instrpanel_ybb.cpp
	instrpanel_dlc_a.cpp
	instrpanel_dlc_d.cpp
	instrpanel_jsc.cpp
	instrpanel_jsc_d.cpp
	instrpanel_zdc.cpp
	instrpanel_zdc_d.cpp
	instrpanel_jsc_c.cpp
	instrpanel_ybb_b.cpp
	instrpanel_dlc_b.cpp
	instrpanel_jsc_b.cpp
	topwindow.cpp
	panelbase.cpp
	panelveri0.cpp
	panelveri1.cpp
	panelveri2.cpp
	panelveri3.cpp
	protocol.cpp
	uartctl.cpp
	mainwindow.h
	common.h
	mainwindow.ui
	rsc.qrc
  )
endif()

target_link_libraries(InstrPanel PRIVATE pthread Qt5::Widgets)
