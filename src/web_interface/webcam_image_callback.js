// Author: Sebastian Wallkötter
// Email: sebastian@wallkoetter.net
// License: MIT

// this file depends on:
// - setup_ROS.js
// it is included in index.html (because browsers don't yet support import)

// The callback executed whenever a new image is published in ROS
function webcam_stream_callback(message)
{    
    var imagedata = "data:image/jpeg;base64," + message.data;
    document.getElementById('webcam').setAttribute('src', imagedata);
}

//webcam_topic is a global variable defined in setup_ROS
// -- there should be a better way for this
webcam_topic.subscribe(webcam_stream_callback);
