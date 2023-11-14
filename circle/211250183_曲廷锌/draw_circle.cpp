#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "vel_ctrl"); // Initialize the node
    ros::NodeHandle n;

    // Create a publisher for the first robot's velocity
    ros::Publisher vel_pub1 = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    // Create a publisher for the second robot's velocity
    ros::Publisher vel_pub2 = n.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 10);

    ROS_INFO("Random111111quu movement start...");

    // Set up a random number generator
    srand(time(0));

    while (ros::ok())
    {
        geometry_msgs::Twist vel_cmd1;
        geometry_msgs::Twist vel_cmd2;

        // Generate random linear and angular velocities for the first robot
        vel_cmd1.linear.x = static_cast<double>(rand()) / static_cast<double>(RAND_MAX) * 2.0 - 1.0;
        vel_cmd1.angular.z = static_cast<double>(rand()) / static_cast<double>(RAND_MAX) * 2.0 - 1.0;

        // Generate random linear and angular velocities for the second robot
        vel_cmd2.linear.x = vel_cmd1.linear.x;
        vel_cmd2.angular.z = vel_cmd1.angular.z;

        // Publish velocity commands for both robots
        vel_pub1.publish(vel_cmd1);
        vel_pub2.publish(vel_cmd2);

        ros::spinOnce();
        ros::Duration(1.0).sleep(); // Wait for 1 second before sending the next random command
    }

    return 0;
}
