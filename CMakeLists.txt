cmake_minimum_required(VERSION 3.6)
project(db_Assignment1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Views/main.cpp Controllers/UserController.cpp Controllers/UserController.h Models/User.cpp Models/User.h Models/Movie.cpp Models/Movie.h Models/UserRent.cpp Models/UserRent.h Services/FileService.cpp Services/FileService.h Controllers/MovieController.cpp Controllers/MovieController.h Data Data/users.txt Data/movies.txt Data/userRent.txt Data/temp.txt)
add_executable(db_Assignment1 ${SOURCE_FILES})