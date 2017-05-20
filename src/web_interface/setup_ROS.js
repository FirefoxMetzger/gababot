// Author: Sebastian Wallkötter
// Email: sebastian@wallkoetter.net
// License: MIT

//get handle to ROSBridge and define responses top opening / closing of the 
//connection
var rosBridge = new ROSLIB.Ros
({
    url : 'ws://ros-master.ddns.net:9090'
});

// callback upon connect -- turn 'led' green
rosBridge.on
(
	'connection', 
	() => {document.getElementById("bridge_on_led").style.background = "green";}
);

// callback upon discconect -- turn 'led' red
rosBridge.on
(
	'close',
	()=>{document.getElementById("bridge_on_led").style.background = "red";}
);

// callback upon error -- report that there has been an issue
rosBridge.on
(
	'error', 
	(error)=>{document.getElementById("bridge_on_error_message").innerHTML = 
	"There was an error connecting to the server";}
);

//declare publishers 

//-- again global variables. There has to be a nicer way to this
// but then JS is a scripting language...
var keyboard_topic = new ROSLIB.Topic({
ros : rosBridge,
name : '/keyboard',
messageType : '/jake/Keyboard'
});

//declare subscribers
var webcam_topic = new ROSLIB.Topic({
ros : rosBridge,
name : '/camera/image/compressed',
messageType : 'sensor_msgs/CompressedImage'
});

var slam_pose_topic = new ROSLIB.Topic({
ros : rosBridge,
name : '/lsd_slam/pose',
messageType : 'geometry_msgs/PoseStamped'
});
