#include "ros/ros.h"
#include "interaccion/multiply.h"
#include <interaccion/inf_personal_usuario.h>

bool add(interaccion::multiply::Request  &req, interaccion::multiply::Response &res)
{
    res.mul = req.a * 2;
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "multiplyer");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("multiply_by_two", add);
    ros::spin();

    return 0;
}
