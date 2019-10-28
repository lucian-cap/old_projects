


//gets the size of the window so the game screen will 
//take up the entire window
var width = window.innerWidth;
var height = window.innerHeight;

//creates the canvas object, giving it the properties gotten
//above so it takes the entire browser
var renderer = new THREE.WebGLRenderer({ antialias: true });
renderer.setSize(width, height);
renderer.shadowMap.enabled = true;



//adds the actual canvas object to the html doc so the game
//screen appears
document.body.appendChild(renderer.domElement);


//creates the scene object, which will have all the shapes/lights
//added to it
var scene = new THREE.Scene;
scene.background = new THREE.Color(0xffffff);



//the following couple of lines create the object to be added
//to the scene
var geometry = new THREE.PlaneGeometry( 10000, 10000);
var material = new THREE.MeshLambertMaterial( {color: 0xA0A0A0} );
var plane = new THREE.Mesh( geometry, material );
plane.rotation.x += (270 * (3.1415/180));
plane.position.y = -1.0;
scene.add( plane );



var cubeMaterialTemp = new THREE.TextureLoader().load('skyscraper.jpg');
var cubeMaterial = new THREE.MeshLambertMaterial({ map: cubeMaterialTemp});
var buildingCollection = [];


//creates the camera object and adds it to the scene
var camera = new THREE.PerspectiveCamera(45, width / height, 0.1, 10000);
camera.position.x = 0;
camera.position.y = 0;
camera.position.z = 100;


scene.add(camera);



//creates the light object to give more light to the scene
var ambientLight = new THREE.AmbientLight(0xffffff);
scene.add(ambientLight);




//begins series of variable initializations
var firstMouseMove = true; //this is used for whent the users mouse first starts moving
var trackMouse = false;
var camPos = {x: 0, y: 0, z: 0}; //this is a JS obj which holds the cams current position
var camMove = new THREE.Vector3(0, 0, 0);
var camStrafe = new THREE.Vector3(0, 0, 0);
var cameraLookAt = new THREE.Vector3(0, 0, -1);
var cameraRight = new THREE.Vector3(1, 0, 0);
var cameraUp = new THREE.Vector3().crossVectors(cameraRight, cameraLookAt);
var oldMousePos = {x: 0, y: 0};


document.addEventListener('mousemove', handleMouseMove, false);
document.addEventListener('keydown', doKeyDown, false);
document.addEventListener('keyup', doKeyUp, false);
document.addEventListener('mousedown', handleMouseDown, false);





createBuildings();
render(); //this calls the render function below to start 
//producting the images on the canvas


function createBuildings(){

    for(var i = 0; i < 200; i++){
        var len = Math.random() * 50 + 15;
        var cubeGeometry = new THREE.CubeGeometry(Math.random() * 10 + 5, len, Math.random() * 5 + 10);
        var cube = new THREE.Mesh(cubeGeometry, cubeMaterial);
        cube.position.x = (Math.random() * 1000) - 500;
        cube.position.y = len / 2.0 - 1.0;
        cube.position.z = (Math.random() * 1000) - 500;
        buildingCollection.push(cube);
    }

    for(var i = 0; i < buildingCollection.length; i++){
        scene.add(buildingCollection[i]);
    }


}




function render(){

    camera.position.add(camMove);
    camera.position.add(camStrafe);

    var newLookAt = new THREE.Vector3().addVectors(camera.position, cameraLookAt);
    camera.lookAt(newLookAt);
    camera.up = cameraUp;


    renderer.render(scene, camera);
    requestAnimationFrame(render);




}

function handleMouseMove(evt){
    if(trackMouse){
        //if this is the first time the mouse has been detected
        //by this function then the location of the mouse is saved
        if(firstMouseMove){
            oldMousePos.x = evt.clientX;
            oldMousePos.y = evt.clientY;
            firstMouseMove = false;
            return;
        }

        //gets the angle to rotate by
        var yaw = (oldMousePos.x - evt.clientX) / 200.0; //gets x rotation (side to side)
        var pitch = (oldMousePos.y - evt.clientY) / 200.0; //gets y rotation (front to back)

        cameraLookAt.applyAxisAngle(new THREE.Vector3(0, 1, 0), yaw);
        cameraRight.applyAxisAngle(new THREE.Vector3(0, 1, 0), yaw);

        cameraLookAt.applyAxisAngle(cameraRight, pitch);

        //saves the new location of the mouse as the old location
        oldMousePos.x = evt.clientX;
        oldMousePos.y = evt.clientY;
    }




}


function handleMouseDown(evt){
    if(trackMouse == false){
        trackMouse = true;
    }
    else if(trackMouse == true){
        trackMouse = false;
    }
}


function doKeyDown(evt){
    var code = evt.keyCode;

    switch(code){
        case 65: // a key
            camStrafe.x = -cameraRight.x;
            camStrafe.y = -cameraRight.y;
            camStrafe.z = -cameraRight.z;
            break;
        case 68: //d key
            camStrafe.x = cameraRight.x;
            camStrafe.y = cameraRight.y;
            camStrafe.z = cameraRight.z;
            break;
        case 87: //w key
            camMove.x = cameraLookAt.x;
            camMove.y = cameraLookAt.y;
            camMove.z = cameraLookAt.z;
            break;
        case 83: //s key
            camMove.x = -cameraLookAt.x;
            camMove.y = -cameraLookAt.y;
            camMove.z = -cameraLookAt.z;
            break;
    }
}



function doKeyUp(evt){
    var code = evt.keyCode;

    switch(code){
        case 65: //a key
            camStrafe.x = 0;
            camStrafe.y = 0;
            camStrafe.z = 0;
            break;
        case 68: //d key
            camStrafe.x = 0;
            camStrafe.y = 0;
            camStrafe.z = 0;
            break;
        case 87: //w key
            camMove.x = 0;
            camMove.y = 0;
            camMove.z = 0;
            break;
        case 83: //s key
            camMove.x = 0;
            camMove.y = 0;
            camMove.z = 0;
            break;
    }
}