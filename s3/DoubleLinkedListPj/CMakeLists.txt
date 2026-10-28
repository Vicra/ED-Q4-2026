cmake_minimum_required(VERSION 3.19)
project(DoubleLinkedListPj LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(DoubleLinkedListPj
    main.cpp
    dllnode.h dllnode.cpp
    doublelinkedlist.h doublelinkedlist.cpp
)

target_link_libraries(DoubleLinkedListPj
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS DoubleLinkedListPj
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
