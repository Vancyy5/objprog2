cmake_minimum_required(VERSION 3.10)
project(StudentuVertinimas CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(TBB QUIET)
if(TBB_FOUND)
    message(STATUS "Intel TBB found")
    add_compile_definitions(HAS_TBB)
else()
    message(STATUS "Intel TBB not found, attempting to use compiler-provided parallel algorithms")
   
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(-ltbb)
    endif()
endif()


if(MSVC)
    
    add_compile_options(/W4)
else()
    
    add_compile_options(-Wall -Wextra -O3)
endif()


set(SOURCES
    main.cpp
    funkcijos.cpp
    laikas.cpp
    strategija1.cpp
    strategija2.cpp
    strategija3.cpp
)


set(HEADERS
    funkcijos.h
    laikas.h
    lib.h
    strategija1.h
    strategija2.h
    strategija3.h
)


add_executable(StudentuVertinimas ${SOURCES} ${HEADERS})


target_include_directories(StudentuVertinimas PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


if(TBB_FOUND)
    target_link_libraries(StudentuVertinimas PRIVATE TBB::tbb)
else()
    
    if(NOT MSVC)  
        target_link_libraries(StudentuVertinimas PRIVATE tbb)
    endif()
endif()


set_target_properties(StudentuVertinimas PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)


file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin/test_files)


install(TARGETS StudentuVertinimas
    RUNTIME DESTINATION bin
)


option(BUILD_TESTING "Build the testing tree." OFF)
if(BUILD_TESTING)
    enable_testing()
   
endif()