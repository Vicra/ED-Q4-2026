cmake_minimum_required(VERSION 3.19)
project(RatInMaze LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(RatInMaze
    main.cpp
)

target_link_libraries(RatInMaze
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS RatInMaze
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
