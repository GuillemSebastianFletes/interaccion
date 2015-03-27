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
#include "interaccion/multiply.h"
#include <std_msgs/UInt32.h>
#include <std_msgs/Bool.h>

using namespace std;
std_msgs::Bool first_time;

void dialogoCallback(const interaccion::usuario::ConstPtr &msg)
{
    //mensaje initalitation
    interaccion::usuario mensaje;
    mensaje = *msg;

    //time initalation
    ros::Time tiempo;

    //publisher and service initalitation
    ros::NodeHandle nh;
    ros::Publisher start = nh.advertise<std_msgs::Bool>("start_topic",1);
    ros::Publisher restart = nh.advertise<std_msgs::Bool>("reset_topic",1);
    ros::ServiceClient client = nh.serviceClient<interaccion::multiply>("multiply_by_two");
    interaccion::multiply srv;

    //time publishers
    if(first_time.data)
    {
        start.publish(first_time);
    }
    else
    {
        start.publish(first_time);
    }

    //server initalitation and printing msg
    srv.request.a = mensaje.infPersonal.edad;
    cout << "El usuario se llama " << mensaje.infPersonal.nombre << cout;
    if (client.call(srv))
    {
        printf("tiene %d",srv.response.mul);
    }
    else
    {
        ROS_ERROR("Failed to call service add_two_ints");
        return;
    }
    cout << endl;
    cout <<  "habla los siguientes idiomas: ";
    cout << mensaje.infPersonal.idiomas.data();
    cout << endl;
    cout << "El usuario se siente: " << mensaje.emocion <<endl;
    printf("las cordenadas son: %d %d %d", mensaje.posicion.x, mensaje.posicion.y,mensaje.posicion.z);
    cout << endl;

}

void timerCallback (const std_msgs::String::ConstPtr &msg)
{
    cout << msg->data << endl;
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "dialogo");
    first_time.data = true;
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("user_topic", 1, dialogoCallback);
    ros::Subscriber sub2 = n.subscribe("still_alive",1,timerCallback);
    ros::Publisher empaquetado = n.advertise<interaccion::usuario>("user_topic",1);
    ros::spin();
}

