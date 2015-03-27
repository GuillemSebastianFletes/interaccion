#include <stdlib.h>
#include <stdio.h>
#include <ros/ros.h>
#include <sstream>
#include <string>
#include <vector>
#include <std_msgs/String.h>

using namespace std;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "emocion_topic");
    ros::NodeHandle n;
    ros::Publisher emocion = n.advertise<std_msgs::String>("emocion",1);
    ros::Rate loop_rate(1);
    std_msgs::String mensaje;
    while (ros::ok())
    {
        ROS_INFO("\n What's up?");
        cin >> mensaje.data;
        emocion.publish(mensaje);
    }
}
