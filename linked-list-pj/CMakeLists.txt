cmake_minimum_required(VERSION 3.19)
project(linked-list-pj LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(linked-list-pj
    main.cpp
    node.h node.cpp
    linkedlist.h linkedlist.cpp
)

target_link_libraries(linked-list-pj
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS linked-list-pj
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
