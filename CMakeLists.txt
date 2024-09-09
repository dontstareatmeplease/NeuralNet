#cmake_minimum_required(VERSION 3.26)
#project(NeuralNet_Training)
#
#set(CMAKE_CXX_STANDARD 20)
#
#include_directories("/opt/homebrew/opt/mongo-cxx-driver/include/mongocxx/v_noabi")
#include_directories("/opt/homebrew/opt/mongo-cxx-driver/include/bsoncxx/v_noabi")
#
#find_package(mongocxx REQUIRED)
#find_package(bsoncxx REQUIRED)
#
#add_executable(NeuralNet_Training main.cpp
#        Sigmoid.cpp
#        DbOperations.cpp
#        GlobalVariables.cpp
#        Private.cpp)
#
#target_link_libraries(NeuralNet_Training PRIVATE mongocxx_shared bsoncxx_shared)

cmake_minimum_required(VERSION 3.26)
project(NeuralNet_Training)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("/Users/kevinliang/vcpkg/installed/arm64-osx/include/bsoncxx/v_noabi")
include_directories("/Users/kevinliang/vcpkg/installed/arm64-osx/include/mongocxx/v_noabi")

find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

add_executable(NeuralNet_Training main.cpp
        Training/Normalization.h
        Training/Normalization.cpp
        DbOperations.h
        DbOperations.cpp
        GlobalVariables.h
        GlobalVariables.cpp
        Private.h
        Private.cpp
        Training/ForwardPropagation.cpp
        Training/ForwardPropagation.h
        Training/MakeTrainingSample.cpp
        Training/MakeTrainingSample.h
        Training/BackPropagation.cpp
        Training/BackPropagation.h)

#target_link_libraries(NeuralNet_Training ${MONGOCXX_LIBRARIES} ${BSONCXX_LIBRARIES})

target_link_libraries(NeuralNet_Training
        /Users/kevinliang/vcpkg/installed/arm64-osx/lib/libbsoncxx-static.a
        /Users/kevinliang/vcpkg/installed/arm64-osx/lib/libmongocxx-static.a
        /Users/kevinliang/vcpkg/installed/arm64-osx/lib/libbson-static-1.0.a
        /Users/kevinliang/vcpkg/installed/arm64-osx/lib/libmongoc-static-1.0.a
        "-framework CoreFoundation"
        "-framework Security"
        "-lz"
        "-lresolv"  # Add this for DNS resolver functions
        /Users/kevinliang/vcpkg/installed/arm64-osx/lib/libutf8proc.a  # Add utf8proc library
)