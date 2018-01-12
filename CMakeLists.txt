CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
PROJECT(Gradius)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/Modules/)
SET(CMAKE_CXX_FLAGS "-Wall")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# FILE(GLOB SRC src/*.cpp src/*.hpp)

SET(SRC
		src/main.cpp

		src/controllers/Controller.hpp

        src/entities/Entity.hpp
        src/entities/PlayerShipEntity.cpp
        src/entities/PlayerShipEntity.hpp
		src/entities/EnemyShipEntity.cpp
		src/entities/EnemyShipEntity.hpp
		src/entities/BulletEntity.hpp
		src/entities/ObstacleEntity.hpp

		src/models/Model.hpp

		src/utils/Game.cpp
        src/utils/Game.hpp
		src/utils/json.hpp
        src/utils/Singleton.hpp
		src/utils/Stopwatch.hpp
        src/utils/Transformation.hpp

        src/views/View.hpp
        src/views/View.cpp
        src/utils/Level.hpp src/utils/Level.cpp src/entities/EnemyShipEntity.cpp src/entities/BorderEntity.cpp src/entities/BorderEntity.hpp)

INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

ADD_EXECUTABLE(gradius ${SRC})

TARGET_LINK_LIBRARIES(gradius ${SFML_LIBRARIES})
