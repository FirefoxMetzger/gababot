
function webcam_stream_callback(message)
{
    //var canvas = document.getElementById("webcam");
    //var ctx = canvas.getContext("2d");
    
    var imagedata = "data:image/jpeg;base64," + message.data;
    
    //ctx.drawImage(imagedata,0,0);
    document.getElementById('webcam').setAttribute('src', imagedata);
}

webcam_topic.subscribe(webcam_stream_callback);
