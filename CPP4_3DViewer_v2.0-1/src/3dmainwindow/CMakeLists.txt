cmake_minimum_required(VERSION 3.5)

project(3DViewer VERSION 0.1)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    3rdParty/giflib/dgif_lib.c
    3rdParty/giflib/egif_lib.c
    3rdParty/giflib/gif_err.c
    3rdParty/giflib/gif_font.c
    3rdParty/giflib/gif_hash.c
    3rdParty/giflib/gifalloc.c
    3rdParty/giflib/quantize.c
    gifimage/doc/snippets/doc_src_qtgifimage.cpp
    gifimage/qgifimage.cpp
    3rdParty/giflib/gif_hash.h
    3rdParty/giflib/gif_lib.h
    3rdParty/giflib/gif_lib_private.h
    gifimage/qgifglobal.h
    gifimage/qgifimage.h
    gifimage/qgifimage_p.h

    simple_matrix/simple_matrix.cc
    simple_matrix/simple_matrix.h
    simple_matrix/s21_matrix_oop.h
    simple_matrix/s21_matrix_oop.cc

    model/model.cc
    model/model.h
    model/settings.cc
    model/settings.h
    controller/controller.cc
    controller/controller.h
    parser/parser.cc
    parser/parser.h

    oglwidget.h
    oglwidget.cc
    mainwindow.cc
    mainwindow.h

    main.cc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(3DViewer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET 3DViewer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(3DViewer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(3DViewer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(3DViewer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(3DViewer PRIVATE Qt6::OpenGLWidgets)

set_target_properties(3DViewer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(3DViewer)
endif()


if (MYLIB_TEST)

include (CTest)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(
  hello_test
  ../tests/test.cc
  model/model.cc
  model/model.h
  model/settings.cc
  model/settings.h
  controller/controller.cc
  controller/controller.h
  parser/parser.cc
  parser/parser.h
  simple_matrix/simple_matrix.cc
  simple_matrix/simple_matrix.h
  simple_matrix/s21_matrix_oop.cc
  simple_matrix/s21_matrix_oop.cc
  )

target_link_libraries(
  hello_test
Qt${QT_VERSION_MAJOR}::Widgets
  GTest::gtest_main
  )


include(GoogleTest)
gtest_discover_tests(hello_test)

endif()
