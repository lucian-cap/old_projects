/*
Completed by Chase Perry using Dr. Mihail's code from the "simple three.js example" as a starter. 
Spoke with Christian, Sean, and Mickey a little to discuss ideas about implementation.
*/



var width = window.innerWidth;
var height = window.innerHeight;
var cubeHolder = [];
var cameraX, cameraY, cameraZ, cameraRotateY, cameraRotateX;
cameraX = 0;
cameraY = 0;
cameraZ = 500;
cameraRotateX = 0;
cameraRotateY = 0;
var lastX = 0;
var lastY = 0;
var trackMovement = 0;


var renderer = new THREE.WebGLRenderer({ antialias: true });
renderer.setSize(width, height);
document.body.appendChild(renderer.domElement);
document.addEventListener("keydown", doKeyDown, false);
document.addEventListener("mousemove", mouseMove, false );
document.addEventListener("mousedown", mouseDown, false );
 
// create scene object
var scene = new THREE.Scene;

// create simple geometry and add to scene
var cubeGeometry; 
var cubeMaterial; 
var cube;
var x, y, z; 

for(var i = 0; i < 200; i++){
    cubeGeometry = new THREE.CubeGeometry(5, 15, 5);
    cubeMaterial = new THREE.MeshLambertMaterial({color: 0xff0000});
    cube = new THREE.Mesh(cubeGeometry, cubeMaterial);
    x = Math.random() * 1000 - 500;
    y = Math.random() * 1000 - 500;
    z = Math.random() * 1000 - 500;
    cube.position.set(x, y, -1 * z);
    cubeHolder.push(cube);
    console.log(cubeHolder.length);
}
 
 

// create perspective camera
var camera = new THREE.PerspectiveCamera(45, width / height, 0.1, 10000);
camera.position.x = cameraX;
camera.position.y = cameraY;
camera.position.z = cameraZ;
camera.rotation.x = cameraRotateX;
camera.rotation.y = cameraRotateY;
// add to scene and renderer
scene.add(camera); 
renderer.render(scene, camera);
// create the view matrix
camera.lookAt(0, 0, 0);

// add lighting and add to scene 
/*
var pointLight = new THREE.PointLight(0xaabbcc);
pointLight.position.set(0, 0, 50);
scene.add(pointLight);
*/

var light = new THREE.AmbientLight(0x404040, 2);
scene.add(light);
for(var i = 0; i < cubeHolder.length; i++){
    scene.add(cubeHolder[i]);
}



/*
var skyboxGeometry = new THREE.CubeGeometry(10000, 10000, 10000);
var skyboxMaterial = new THREE.MeshBasicMaterial({ color: 0xff0000, side: THREE.DoubleSide });
var skybox = new THREE.Mesh(skyboxGeometry, skyboxMaterial);
scene.add(skybox);
 */
 
renderer.render(scene, camera);


function render() {
    camera.position.x = cameraX;
    camera.position.y = cameraY;
    camera.position.z = cameraZ;
    camera.rotation.x = cameraRotateX;
    camera.rotation.y = cameraRotateY;
    renderer.render(scene, camera);
    requestAnimationFrame(render);
    for(var i = 0; i < cubeHolder.length; i++){
        cubeHolder[i].rotation.y += 0.01;
    }
    //cameraY += 1;
    //cameraX += 1;
    //console.log(cameraY);
    
	
}
render();





function doKeyDown(evt){
    var code = evt.keyCode;


    switch(code){
        case 87: //this is the W key

            var changeZ = 10 * Math.cos(cameraRotateX);
            var changeY = 10 * Math.sin(cameraRotateX);
            cameraZ -= changeZ;
            cameraY += changeY;
            break;
        case 68: //this is the D key
            cameraX += 10;
            break;
        case 83: //this is the S key
            var changeZ = 10 * Math.cos(cameraRotateX);
            var changeY = 10 * Math.sin(cameraRotateX);
            cameraZ += changeZ;
            cameraY -= changeY;
            break;
        case 65: //this is the A key
            cameraX -= 10;
            break;
        
    }
}

function mouseMove(evt){
    var x = evt.clientX;
    var y = evt.clientY;


    if(trackMovement == 1){

        if(lastX > x){
            cameraRotateY += 0.01;
        }
        else if(lastX < x){
            cameraRotateY -= 0.01;
        }
        lastX = x;

        if(lastY > y){
            cameraRotateX += 0.01;
        }
        else if(lastY < y){
            cameraRotateX -= 0.01;
        }
        lastY = y;
    }

}

function mouseDown(){
    if(trackMovement == 1 ){
        trackMovement = 0;
    }
    else if(trackMovement == 0){
        trackMovement = 1;
    }
}

