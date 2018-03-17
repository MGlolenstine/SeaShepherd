cmake_minimum_required(VERSION 3.8)
project(igrca)

set(CMAKE_CXX_STANDARD 11)

#link_libraries("${PROJECT_SOURCE_DIR}/libs/dlls/")

FILE(COPY boats DESTINATION .)

set(SOURCE_FILES main.cpp P5c.h MainMenu.h Button.h LevelSelector.h Level1.h boats Level2.h VegovecBoat.h IceBerg.h AntarcticBoat.h Atol.h SouthSeaBoat.h Level3.h Pirate.h ChinaSeaBoat.h)
add_executable(igrca ${SOURCE_FILES})

set(GLUT_LIBRARY "C:/MinGW/lib/freeglut.lib")
set(IL_LIBRARY "C:/MinGW/lib/libIL.a")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(DevIL REQUIRED)
#find_package(IL REQUIRED)

#set(IL_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/libs/includes)
#set(ILU_LIBRARIES ${PROJECT_SOURCE_DIR}/libs/dlls/ILU)
#set(ILUT_LIBRARIES ${PROJECT_SOURCE_DIR}/libs/dlls/ILUT)

include_directories(${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${IL_INCLUDE_DIRS})
target_link_libraries(igrca ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${IL_LIBRARIES} ${ILU_LIBRARIES} ${ILUT_LIBRARIES})