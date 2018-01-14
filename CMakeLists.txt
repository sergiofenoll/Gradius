CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
PROJECT(Gradius)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/Modules/)
SET(CMAKE_CXX_FLAGS "-Wall -std=c++14")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

SET(SRC
		src/main.cpp

		src/controllers/Controller.hpp

		src/models/Entity.hpp
		src/models/PlayerShipEntity.cpp
		src/models/PlayerShipEntity.hpp
		src/models/EnemyShipEntity.cpp
		src/models/EnemyShipEntity.hpp
		src/models/BulletEntity.hpp
		src/models/ObstacleEntity.hpp

		src/models/ModelData.hpp

		src/models/Game.cpp
		src/models/Game.hpp
		src/utils/json.hpp
        src/utils/Singleton.hpp
		src/utils/Stopwatch.hpp
        src/utils/Transformation.hpp

        src/views/View.hpp
        src/views/View.cpp
        src/utils/Level.hpp src/utils/Level.cpp src/models/EnemyShipEntity.cpp src/models/BorderEntity.cpp src/models/BorderEntity.hpp src/controllers/Controller.cpp src/models/BulletEntity.cpp src/models/Entity.cpp src/models/ModelData.cpp src/models/ObstacleEntity.cpp src/exceptions/BaseException.hpp)

INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

ADD_EXECUTABLE(gradius ${SRC})

TARGET_LINK_LIBRARIES(gradius ${SFML_LIBRARIES})
