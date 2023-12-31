cmake_minimum_required(VERSION 3.23)
project(Hanoi_Scientific)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

FILE(GLOB SOURCES sources/*.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES}) 
add_executable(testing tests/e2e_full_answer.cpp)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC include)
target_include_directories(testing PUBLIC include)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost REQUIRED)
if(Boost_FOUND)
    target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIRS}) 
    target_link_libraries(${CMAKE_PROJECT_NAME} ${Boost_LIBRARIES})
    target_include_directories(testing PUBLIC ${Boost_INCLUDE_DIRS}) 
    target_link_libraries(testing ${Boost_LIBRARIES})
endif()

