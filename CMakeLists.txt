cmake_minimum_required(VERSION 3.14)
project(Dungeon_Quest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES main.cpp Character.cpp Character.h Fonts.cpp Fonts.h Music.cpp Music.h Background.cpp Background.h Enemy.cpp Enemy.h Dependencies.h Sound.cpp Sound.h TileMap.h TileMap.cpp Animation.cpp Animation.h Level.cpp Level.h Fireball.cpp Fireball.h)

set(SOURCE_FILES main.cpp Character.cpp Character.h Fonts.cpp Fonts.h Music.cpp Music.h Enemy.cpp Enemy.h Dependencies.h Sound.cpp Sound.h TileMap.h TileMap.cpp Animation.cpp Animation.h Level.cpp Level.h Fireball.cpp Fireball.h)

add_executable(Dungeon_Quest ${SOURCE_FILES})

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Dungeon_Quest sfml-system sfml-window sfml-graphics sfml-audio sfml-network)


