#include <stdlib.h>
#include <stdio.h>
#include <ros/ros.h>
#include <interaccion/pos_usuario.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int main(int argc, char **argv)
{
    ros::init(argc, argv, "");
    ros::NodeHandle n;
    ros::Publisher posicion_usuario = n.advertise<interaccion::pos_usuario>("posicion_usuario",1);
    ros::Rate loop_rate(1);

    interaccion::pos_usuario mensaje;
    string aoi;

    while (ros::ok())
    {
        ROS_INFO ("\n Introduzca la coordenada x: ");
        cin >> aoi;
        mensaje.x = atoi(aoi.c_str());
        ROS_INFO ("\n Introduzca la coordenada y: ");
        cin >> aoi;
        mensaje.y = atoi(aoi.c_str());
        ROS_INFO ("\n Introduzca la coordenada x: ");
        cin >> aoi;
        mensaje.z = atoi(aoi.c_str());
        posicion_usuario.publish(mensaje);
    }
}

