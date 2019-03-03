cmake_minimum_required(VERSION 2.8.9)
PROJECT(check)
add_compile_options(-std=c++11)
add_compile_options(-std=c++14)
ADD_EXECUTABLE(check 
main.cpp
transition.cpp
ads.cpp
func.cpp
checking.cpp
alphabet.cpp
predicate.cpp
coreach.cpp
allpath.cpp
)



