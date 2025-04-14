#include <ros/ros.h>
#include "mybot_room_coordinates.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int room_index = -1;
int last_room_index = -1;  
ros::Publisher status_pub;

void roomCallback(const std_msgs::Int32::ConstPtr& Room_msg) {
    int room = Room_msg->data;

    if (room >= 1 && room <= num_rooms && room != last_room_index) {  
        room_index = room;
        last_room_index = room;  
        ROS_INFO("Room index updated to: %d", room);

        std_msgs::String status_msg;
        status_msg.data = "Moving to Room " + std::to_string(room_index);
        status_pub.publish(status_msg);
    } else {
        ROS_WARN("Invalid or duplicate room number received: %d", room);
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "room_number");
    ros::NodeHandle n;

    status_pub = n.advertise<std_msgs::String>("room_status", 10);
    ros::Subscriber sub = n.subscribe("room_number", 10, roomCallback);
    MoveBaseClient ac("move_base", true);

    while (!ac.waitForServer(ros::Duration(5.0))) {
        ROS_INFO("Waiting for move_base action server...");
    }

    move_base_msgs::MoveBaseGoal goal;
    ros::Rate loop_rate(10);

    while (ros::ok()) {
        ros::spinOnce();

        if (room_index >= 1 && room_index <= num_rooms) {
            std_msgs::String status_msg;

           
            goal.target_pose.header.frame_id = "map";
            goal.target_pose.header.stamp = ros::Time::now();
            goal.target_pose.pose.position.x = x_axis[room_index - 1];
            goal.target_pose.pose.position.y = y_axis[room_index - 1];
            goal.target_pose.pose.orientation.w = 1.0;

            ROS_INFO("Sending goal to Room index: %d", room_index);
            ac.sendGoal(goal);
            ac.waitForResult();

            if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
                ROS_INFO("Successfully reached Room: %d", room_index);
                status_msg.data = "Successfully reached Room " + std::to_string(room_index);
            } else {
                ROS_WARN("Failed to reach Room: %d", room_index);
                status_msg.data = "Failed to reach Room " + std::to_string(room_index);
            }

            status_pub.publish(status_msg);
            room_index = -1;  
        }

        loop_rate.sleep();
    }

    return 0;
}
