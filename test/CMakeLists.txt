cmake_minimum_required(VERSION 3.19)
project(test LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(test
    main.cpp
)

target_link_libraries(test
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS test
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
