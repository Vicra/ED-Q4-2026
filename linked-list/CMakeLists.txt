cmake_minimum_required(VERSION 3.19)
project(linked-list LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(linked-list
    main.cpp
    node.h node.cpp
)

target_link_libraries(linked-list
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS linked-list
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
