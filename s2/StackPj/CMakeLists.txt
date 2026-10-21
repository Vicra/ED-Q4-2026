cmake_minimum_required(VERSION 3.19)
project(StackPj LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(StackPj
    main.cpp
    stack.h stack.cpp
    node.h node.cpp
)

target_link_libraries(StackPj
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS StackPj
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
