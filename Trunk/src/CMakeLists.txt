link_directories(${PROJECT_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME})
include_directories(${PROJECT_SOURCE_DIR}/extlibs/SFML/include)
link_libraries(sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

include_directories(${PROJECT_SOURCE_DIR}/inc)

set(INC ${PROJECT_SOURCE_DIR}/inc)
set(SRC ${PROJECT_SOURCE_DIR}/src)

set(PROJECT_FILES
	${SRC}/main.cpp
	${SRC}/parser.cpp
	${INC}/parser.hpp
	${SRC}/gui.cpp
	${INC}/gui.hpp
	${SRC}/button.cpp
	${INC}/button.hpp
	${SRC}/girl.cpp
	${INC}/girl.hpp
)

add_executable(MarkovLove ${PROJECT_FILES})

set_property(TARGET MarkovLove PROPERTY CXX_STANDARD 14)
set_property(TARGET MarkovLove PROPERTY CXX_STANDARD_REQUIRED ON)
