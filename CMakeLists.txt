cmake_minimum_required(VERSION 2.8.3)
project(interaccion)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  rospy
  std_msgs
)


add_message_files(
  FILES
  inf_personal_usuario.msg
  pos_usuario.msg
  usuario.msg
)

add_service_files(
  FILES
  multiply.srv
)
## Generate added messages and services with any dependencies listed here
generate_messages(
DEPENDENCIES
std_msgs)


## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package()

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)


## Declare a cpp executable
 add_executable(nodo_informacion_personal src/informacion_personal.cpp)
 add_executable(nodo_emocion_usuario src/emocion_usuario.cpp)
 add_executable(nodo_posicion_usuario src/posicion_usuario.cpp)
 add_executable(nodo_empaquetador src/empaquetador.cpp)
 add_executable(nodo_dialogo src/dialogo.cpp)
 add_executable(nodo_multiplicador src/multiplicador.cpp)
 add_executable(nodo_reloj src/reloj.cpp)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
# add_dependencies(beginner_tutorials_node beginner_tutorials_generate_messages_cpp)

## Specify libraries to link a library or executable target against
 target_link_libraries(nodo_informacion_personal  ${catkin_LIBRARIES})

target_link_libraries(nodo_emocion_usuario  ${catkin_LIBRARIES} )

 target_link_libraries(nodo_posicion_usuario  ${catkin_LIBRARIES} )

 target_link_libraries(nodo_empaquetador  ${catkin_LIBRARIES}  )

 target_link_libraries(nodo_dialogo  ${catkin_LIBRARIES} )
 add_dependencies(nodo_dialogo interaccion_gencpp)

 target_link_libraries(nodo_multiplicador  ${catkin_LIBRARIES} )
 add_dependencies(nodo_multiplicador interaccion_gencpp)

target_link_libraries(nodo_reloj ${catkin_LIBRARIES})
