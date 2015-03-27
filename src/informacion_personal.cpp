#include <stdlib.h>
#include <stdio.h>
#include <ros/ros.h>
#include <interaccion/inf_personal_usuario.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


int main(int argc, char **argv)
{
    ros::init(argc, argv, "inf_personal");
    ros::NodeHandle n;
    ros::Publisher informacion_personal = n.advertise<interaccion::inf_personal_usuario>("inf_personal",1);
    ros::Rate loop_rate(1);
    interaccion::inf_personal_usuario mensaje;
    string idioma;
    string nombres;
    string aoi;

    while(ros::ok())
    {
        ROS_INFO("\n Introduzca su nombre :  ");
        cin >> mensaje.nombre;
        ROS_INFO("\n Introduzca su edad:  ");
        cin >> aoi;
        mensaje.edad = atoi(aoi.c_str());
        ROS_INFO("\n Introduzca los idiomas que habla, si no habla mas introduzca 0 por favor: ");
        cin >> idioma;
        while (idioma != "0")
        {
        mensaje.idiomas.push_back(idioma);
        cin >> idioma;
        }
        informacion_personal.publish(mensaje);
    }
}


