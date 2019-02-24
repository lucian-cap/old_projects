var graphics;
var frameNum = 0;

var canvas = document.getElementById("canvas");

function getContext(){
    graphics = canvas.getContext("2d");
    console.log("here");
}

function draw(){

    graphics.beginPath();
    graphics.rect(200, 200, 100, 100);
    graphics.fillStyle("red");
    graphics.fill();
    graphics.closePath();
    console.log(frameNum);
}

function doFrame(){
    frameNum++;

    if(frameNum%5 == 0){
        draw();
    }
}

function init(){
   requestAnimationFrame(doFrame); 
}

