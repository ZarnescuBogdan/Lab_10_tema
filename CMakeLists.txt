cmake_minimum_required(VERSION 3.21)
project(Lab_9_live)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab_9_live main.cpp Product/Product.cpp Product/Product.h Repo/Repo.cpp Repo/Repo.h Tests/tests.h Tests/tests.cpp)
