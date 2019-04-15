//Created by Chase Perry.



//creates the canvas object, and adds it the HTML webpage
var width = window.innerWidth;
var height = window.innerHeight;
var renderer = new THREE.WebGLRenderer({ antialias: true });
renderer.setSize(width, height);
document.body.appendChild(renderer.domElement);

//creates the scene object to which objects and lights will be added
var scene = new THREE.Scene;
scene.background = new THREE.Color(0x7EC0EE);

//creates a singular black cube and adds it to the scene
var targetGeometry = new THREE.CubeGeometry(5, 5, 5);


//the following couple of lines create the object to be added
//to the scene
var planeGeometry = new THREE.PlaneGeometry( 100000, 100000);
var planeMaterialImg = new THREE.TextureLoader().load('sand.jpg');
var planeMaterial = new THREE.MeshBasicMaterial( { map: planeMaterialImg } );
var plane = new THREE.Mesh( planeGeometry, planeMaterial);
plane.rotation.x += (270 * (3.1415/180));
plane.position.y = -1.5;
plane.name = "ground";
scene.add( plane );





//creates the camera of which the user will view the scene
var camera = new THREE.PerspectiveCamera(45, width / height, 0.1, 10000);
camera.position.x = 0;
camera.position.y = 5;
camera.position.z = 1000;
scene.add(camera);


var firstMouseMove = true; //this is used for whent the users mouse first starts moving
var trackMouse = false;
var camPos = {x: 0, y: 0, z: 0}; //this is a JS obj which holds the cams current position
var camMove = new THREE.Vector3(0, 0, 0);
var camStrafe = new THREE.Vector3(0, 0, 0);
var cameraLookAt = new THREE.Vector3(0, 0, -1);
var cameraRight = new THREE.Vector3(1, 0, 0);
var cameraUp = new THREE.Vector3().crossVectors(cameraRight, cameraLookAt);
var oldMousePos = {x: 0, y: 0};
var NUM_OF_TARGETS = 500;
var NUM_OF_BUILDINGS = 500;
var buildingMaterialImg = new THREE.TextureLoader().load( 'skyscraper.jpg' );
var buildingMaterial = new THREE.MeshBasicMaterial( { map: buildingMaterialImg } );
var sceneNum = 0;
document.getElementById("myAudio").loop = true;
var x = document.getElementById("myAudio");
var hitTargets = 0;







var raycaster = new THREE.Raycaster();
var mouse = new THREE.Vector2();


document.addEventListener('mousemove', onMouseMove, false);
document.addEventListener('keydown', doKeyDown, false);
document.addEventListener('keyup', doKeyUp, false);
document.addEventListener('mousedown', handleMouseDown, false);




window.alert("Alright! Listen up soldier! This is your final training test. Turn as many of the targets green as possible in 45 seconds! Use your mouse to hit the targets but be sure not to run into them!");
createTargets();
createBuildings();
setTimeout(endGame, 45000);
render();


function render(){
    x.play();
    camMove.x = cameraLookAt.x * 2;
    camMove.y = cameraLookAt.y * 2;
    camMove.z = cameraLookAt.z * 2;


    
    
    camera.position.add(camMove);
    camera.position.add(camStrafe);

    var newLookAt = new THREE.Vector3().addVectors(camera.position, cameraLookAt);
    camera.lookAt(newLookAt);
    camera.up = cameraUp;


    renderer.render(scene, camera);

    if(camera.position.y < 0){
        window.alert("You died! After all your training you should know not to fly into the ground!");
        location.reload();

    }

    raycaster.setFromCamera(mouse, camera);
    var intersects = raycaster.intersectObjects( scene.children );
    intersects.sort((a, b) => (a.distance - b.distance));


    if(intersects[0] != null){
        if(intersects[0].object.name == 'target'){
            intersects[ 0 ].object.material.color.setHex(0x00ff00);
            intersects[0].object.name = "hit";
            hitTargets++;
        }
        if(intersects[0].distance < 2){
                console.log(intersects[0]);
                endGame(intersects[0].object.name);
        }
    }

    requestAnimationFrame(render);



}

function endGame(hitObject){
    if(hitObject == "building"){
        window.alert("You hit a building! How do you think I can explain this to my superiors!");
    }
    else if(hitObject == "target" || hitObject == "hit"){
        window.alert("I thought I told you not to hit the targets! Go back and try again!");
    }
    else{
        if(hitTargets < 10){
            window.alert("You're a disappointment soldier! You only got " + hitTargets + " targets! I can't believe we wasted all this time training you! Get out of my sight!");
        }
        else if(hitTargets < 20){
            window.alert("You're horrible soldier! You only got " + hitTargets + " targets! I can't believe after all that training this is the best you can do! Go back to the basics!");
        }
        else if(hitTargets < 30){
            window.alert("Well soldier, that was terrible but I guess it'll do. You got " + hitTargets + " targets! I can't believe after all that training this is the best you can do!");
        }
        else if(hitTargets < 40){
            window.alert("Huh, well I wish it was better but I'll take it. You got " + hitTargets + " targets! It's time to get to the real fight!");
        }
        else if(hitTargets < 50){
            window.alert("That wasn't the best but it wasn't the worst soldier, congratulations. You got " + hitTargets + " targets!");
        }
        else if(hitTargets < 60){
            window.alert("I'm impressed soldier that was some fine shooting. You got " + hitTargets + " targets! I look forward to seeing how you do on the battlefield.");
        }
        else {
            window.alert("Outstanding soldier! You got " + hitTargets + " targets! I can't believe I even witnessed that!");
        }
    }
    location.reload();
}



function createTargets(){
    for(var i = 0; i < NUM_OF_TARGETS; i++){
        var targetMaterial = new THREE.MeshBasicMaterial({ color: 0xff0000 });
        var cube = new THREE.Mesh(targetGeometry, targetMaterial);
        cube.position.x = Math.random() * 1000 - 500;
        cube.position.y = (Math.random() * 150 + 50) / 2;
        cube.position.z = Math.random() * 1000 - 500;
        cube.name = "target";
        scene.add(cube);
    }    
}

function createBuildings(){
    for(var i = 0; i < NUM_OF_BUILDINGS; i++){
        var heightOfBuilding = Math.random() * 140 + 10;
        var buildingGeometry = new THREE.CubeGeometry(Math.random() * 20 + 5, heightOfBuilding, Math.random() * 20 + 5);
        var building = new THREE.Mesh(buildingGeometry, buildingMaterial);
        building.position.x = Math.random() * 1000 - 500;
        building.position.y = (heightOfBuilding / 2) - 1;
        building.position.z = Math.random() * 1000 - 500;
        building.name = "building";
        scene.add(building);
    }
}


function onMouseMove(evt){

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



    mouse.x = (evt.clientX / width) * 2 - 1;
    mouse.y = - (evt.clientY / height) * 2 + 1;


}

function doKeyDown(evt){
    var code = evt.keyCode;

    switch(code){
        case 65: // a key
            camStrafe.x = -cameraRight.x * 2;
            camStrafe.y = -cameraRight.y * 2;
            camStrafe.z = -cameraRight.z * 2;
            break;
        case 68: //d key
            camStrafe.x = cameraRight.x * 2;
            camStrafe.y = cameraRight.y * 2;
            camStrafe.z = cameraRight.z * 2;
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

function handleMouseDown(evt){
    if(trackMouse == false){
        trackMouse = true;
        oldMousePos.x = evt.clientX;
        oldMousePos.y = evt.clientY;
        firstMouseMove = false;
    }
    else if(trackMouse == true){
        trackMouse = false;
    }

    
}