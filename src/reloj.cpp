#include <stdlib.h>
#include <stdio.h>
#include <ros/ros.h>
#include <sstream>
#include <string>
#include <vector>
#include <std_msgs/Bool.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <std_msgs/String.h>

using namespace std;

ros::Time previous_time;
std_msgs::Bool empiezo;
std_msgs::Bool tengo_algo;

void startCallback (const std_msgs::Bool::ConstPtr &msg)
{
    previous_time = ros::Time::now();
    empiezo = *msg;
}

void resetCallback (const std_msgs::Bool::ConstPtr &msg)
{
    previous_time = ros::Time::now();
}

void timerCallback(const ros::TimerEvent&)
{
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("still_alive", 0);
    std_msgs::String str;
    str.data = "El reloj sigue funcionando";
    pub.publish(str);
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "reloj");
    ros::NodeHandle n;
    ros::Rate loop_rate(3);
    ros::Timer timer = n.createTimer(ros::Duration(1), timerCallback);
    ros::Subscriber sub = n.subscribe("start_topic", 1, startCallback);
    ros::Subscriber sub2 = n.subscribe("reset_topic", 1, resetCallback);
    while(ros::ok())
    {
        if (empiezo.data)
        {
            ros::Time hora = ros::Time::now();
            stringstream sshora;
            sshora << hora;
            string str = sshora.str();
            cout << "Son las: ";
            cout << str <<endl;
            ros::Duration difference = ros::Time::now() - previous_time;
            std::stringstream ssDuration;
            ssDuration << difference;
            str = ssDuration.str();
            cout << "han pàsado:";
            cout << str;
            cout << " s" << endl;
        }

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
