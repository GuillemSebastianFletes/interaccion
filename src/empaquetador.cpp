#include <stdlib.h>
#include <stdio.h>
#include <ros/ros.h>
#include <interaccion/usuario.h>
#include <sstream>
#include <string>
#include <vector>
#include <interaccion/inf_personal_usuario.h>
#include <interaccion/pos_usuario.h>
#include <std_msgs/String.h>


using namespace std;
interaccion::usuario mensaje;



void inf_personal_Callback(const interaccion::inf_personal_usuario::ConstPtr& msg )
{
    mensaje.infPersonal = *msg;
   // cout << "personal" << endl;

}

void posicion_Callback(const interaccion::pos_usuario::ConstPtr& msg )
{
    mensaje.posicion = *msg;
   // cout << "posicion" << endl;

}

void emocion_Callback(const std_msgs::String::ConstPtr& msg)
{
    mensaje.emocion = msg->data;
    //cout << "emocion" << endl;
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "empaquetador");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("inf_personal", 1, inf_personal_Callback);
    ros::Subscriber sub1 = n.subscribe("emocion", 1, emocion_Callback);
    ros::Subscriber sub2 = n.subscribe("posicion_usuario", 1, posicion_Callback);
    ros::Publisher empaquetado = n.advertise<interaccion::usuario>("user_topic",1);
    ros::Duration seconds_sleep(1);

    while(ros::ok())
    {
        if(mensaje.posicion.x != 0  && mensaje.emocion != "" && mensaje.infPersonal.edad !=0)
        {
            empaquetado.publish(mensaje);
            mensaje.posicion.x = 0;
            mensaje.emocion = "";
            mensaje.infPersonal.edad = 0;
            mensaje.infPersonal.idiomas.clear();
        }
        ros::spinOnce();
        seconds_sleep.sleep();
    }
}




