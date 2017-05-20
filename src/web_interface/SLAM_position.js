// Author: Sebastian Wallkötter
// Email: sebastian@wallkoetter.net
// License: MIT

// this file depends on:
// - setup_ROS.js
// it is included in index.html (because browsers don't yet support import)

// The callback executed whenever LSD-SLAM publishes a new pose
function slam_pose_callback(message)
{
    // constant -- number of digits to show
    digits = 1e5;

    // update position
    temp = Math.round(message.pose.position.x*digits)/digits;
    document.getElementById("SLAM_pos_x").innerHTML = temp;
    temp = Math.round(message.pose.position.y*digits)/digits;
    document.getElementById("SLAM_pos_y").innerHTML = temp;
    temp = Math.round(message.pose.position.z*digits)/digits;
    document.getElementById("SLAM_pos_z").innerHTML = temp;
    
    // update rotation quaternion
    temp = Math.round(message.pose.orientation.x*digits)/digits;
    document.getElementById("SLAM_rot_x").innerHTML = temp;
    temp = Math.round(message.pose.orientation.y*digits)/digits;
    document.getElementById("SLAM_rot_y").innerHTML = temp;
    temp = Math.round(message.pose.orientation.z*digits)/digits;
    document.getElementById("SLAM_rot_z").innerHTML = temp;
    temp = Math.round(message.pose.orientation.w*digits)/digits;
    document.getElementById("SLAM_rot_w").innerHTML = temp;
}

//webcam_topic is a global variable defined in setup_ROS
// -- there should be a better way for this
slam_pose_topic.subscribe(slam_pose_callback);
console.log("Callback loaded");
