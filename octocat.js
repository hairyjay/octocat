var ref = new Firebase("https://octocat.firebaseio.com");
var gitRef= ref.child("github").child("octocat").child("commits");
var deviceID    = "53ff6c066667574848441267";
var accessToken = "81d67b882612d03d0be36a3bcccc2ff70076e3fa";

gitRef.on('child_added', function(data){
    var eventData = data.val();
    if (eventData['commits'] != null){
        var requestURL = "https://api.spark.io/v1/devices/" + deviceID + "/commit/";
        $.post( requestURL, { params: 0, access_token: accessToken });
    }
    else{
        var requestURL = "https://api.spark.io/v1/devices/" + deviceID + "/other/";
        $.post( requestURL, { params: 0, access_token: accessToken });
    }
});