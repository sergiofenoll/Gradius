CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
PROJECT(Gradius)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/Modules/)
SET(CMAKE_CXX_FLAGS "-Wall")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# FILE(GLOB SRC src/*.cpp src/*.hpp)

SET(SRC
	src/main.cpp
	
	src/controllers/CollisionController.hpp
	src/controllers/Controller.hpp
	src/controllers/EventController.hpp
	src/controllers/MoveController.hpp

	src/entities/Entity.hpp

	src/helpers/Game.cpp
	src/helpers/Game.hpp
	src/helpers/Singleton.hpp
	src/helpers/Stopwatch.cpp
	src/helpers/Stopwatch.hpp
	src/helpers/Transformation.cpp
	src/helpers/Transformation.hpp

	src/views/View.hpp)

INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

ADD_EXECUTABLE(gradius ${SRC})

TARGET_LINK_LIBRARIES(gradius ${SFML_LIBRARIES})
