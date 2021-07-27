cmake_minimum_required(VERSION 3.4)

#Configuration parameters of cmake
set(CMAKE_CXX_COMPILER g++)#requires g++ to be available on PATH
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Project)

enable_language(CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 
set(CMAKE_VERBOSE_MAKEFILE TRUE) 
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

#Source files here
set(SOURCE_FILES
        textures

        include/Kobieta.h
        src/Kobieta.cpp
        include/Julek.h
        src/Julek.cpp

        include/Notes.h
        src/Notes.cpp
        include/Button.h
        src/Button.cpp
        include/Kawa.h
        src/Kawa.cpp
        include/ECTS.h
        src/ECTS.cpp
        include/Pickup.h
        src/Pickup.cpp
        include/Massage.h
        src/Massage.cpp
        include/Villain.h
        src/Villain.cpp
        include/DEADLINE.h
        include/BEST.h
        src/DEADLINE.cpp
        src/BEST.cpp

        include/Character.h
        src/Character.cpp
        include/TextureMenager.h
        src/TextureMenager.cpp
        include/Gameboard.h
        src/Gameboard.cpp
        include/Game.h
        src/Game.cpp
        src/main.cpp)
        

add_executable(Project ${SOURCE_FILES})

target_include_directories(Project PUBLIC include)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(Project ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})


#TESTs
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

#Test source files here
set(SOURCE_TEST_FILES

        textures

        include/Kobieta.h
        src/Kobieta.cpp
        include/Julek.h
        src/Julek.cpp

        include/Notes.h
        src/Notes.cpp
        include/Button.h
        src/Button.cpp
        include/Kawa.h
        src/Kawa.cpp
        include/ECTS.h
        src/ECTS.cpp
        include/Pickup.h
        src/Pickup.cpp
        include/Massage.h
        src/Massage.cpp
        include/Villain.h
        src/Villain.cpp
        include/DEADLINE.h
        include/BEST.h
        src/DEADLINE.cpp
        src/BEST.cpp

        include/Character.h
        src/Character.cpp
        include/TextureMenager.h
        src/TextureMenager.cpp
        include/Gameboard.h
        src/Gameboard.cpp
        include/Game.h
        src/Game.cpp

        test/GameTests.cpp
        test/CharacterTests.cpp
        test/GameboardTests.cpp
        test/master.cpp)

add_executable(TestProject ${SOURCE_TEST_FILES})



target_include_directories(TestProject PUBLIC include)

target_link_libraries (TestProject
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

enable_testing()

add_test(NAME Test COMMAND TestProject
        --report_level=detailed
        --log_level=all
        --color_output=yes)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
