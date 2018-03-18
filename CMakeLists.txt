cmake_minimum_required(VERSION 3.8)
project(igrca)

set(CMAKE_CXX_STANDARD 11)

FILE(COPY boats DESTINATION .)

set(SOURCE_FILES main.cpp P5c.h MainMenu.h Button.h LevelSelector.h Level1.h boats Level2.h VegovecBoat.h IceBerg.h AntarcticBoat.h Atol.h SouthSeaBoat.h Level3.h Pirate.h ChinaSeaBoat.h QuestionBox.h)
add_executable(igrca ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(DevIL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${IL_INCLUDE_DIRS})
target_link_libraries(igrca ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${IL_LIBRARIES} ${ILU_LIBRARIES} ${ILUT_LIBRARIES})