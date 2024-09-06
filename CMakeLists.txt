cmake_minimum_required(VERSION 3.26)
project(NeuralNet_Training)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# MongoDB C++ driver
# find_package(mongocxx REQUIRED)
# find_package(bsoncxx REQUIRED)

# add_definitions(-DBSONCXX_POLY_USE_STD=1)

add_executable(NeuralNet_Training main.cpp
        Neuron.cpp
        Sigmoid.cpp
        ImportData.cpp)

# include_directories("/opt/homebrew/Cellar/mongo-cxx-driver/3.10.2/include/bsoncxx/v_noabi")
# include_directories("/opt/homebrew/Cellar/mongo-cxx-driver/3.10.2/include/mongocxx/v_noabi")

# Include directories for mongocxx and bsoncxx on M1/M2 Macs (Apple Silicon)
#include_directories(${BSONCXX_INCLUDE_DIRS})
#include_directories(${MONGOCXX_INCLUDE_DIRS})
#include_directories("/opt/homebrew/include/mongocxx/v_noabi")
#include_directories("/opt/homebrew/include/bsoncxx/v_noabi")
#include_directories("/opt/homebrew/include/libmongoc-1.0")
#include_directories("/opt/homebrew/include/libbson-1.0")

# Link the MongoDB C++ drivers to your target
# target_link_libraries(NeuralNet_Training ${MONGOCXX_LIBRARIES} ${BSONCXX_LIBRARIES})