cmake_minimum_required(VERSION 3.21)
project(huffman_tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/api)
include_directories(src/api/funciones)
include_directories(src/api/tads)
include_directories(src/api/tads/huffman)

add_executable(huffman_tree
        src/api/funciones/arrays.hpp
        src/api/funciones/files.hpp
        src/api/funciones/lists.hpp
        src/api/funciones/strings.hpp
        src/api/funciones/tokens.hpp
        src/api/tads/huffman/HuffmanSetup.hpp
        src/api/tads/huffman/Progress.hpp
        src/api/tads/Array.hpp
        src/api/tads/BitReader.hpp
        src/api/tads/BitWriter.hpp
        src/api/tads/Coll.hpp
        src/api/tads/List.hpp
        src/api/tads/Map.hpp
        src/api/tads/Queue.hpp
        src/api/tads/Stack.hpp
        src/comprimir.hpp
        src/descomprimir.hpp
        src/main.cpp)
