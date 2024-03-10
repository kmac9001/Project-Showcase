var render;
var serveDirection;
var serveAngle;
var ball;
//number of frames rendered
var count;
var lPt=0;
var rPt=0;
var paddleL;
var paddleR;
var map = {};
var running = 1;

window.onload = function(){
    //alert("load");
    //alert(document.getElementById('ball').offsetTop);
    //alert(document.getElementById('ball').offsetLeft);

    ball = {
        x: document.getElementById('ball').offsetLeft,
        y: document.getElementById('ball').offsetTop,
        xVel: 0,
        yVel: 0
    };

    paddleL = {
        x: document.getElementById('paddleL').offsetLeft,
        y: document.getElementById('paddleL').offsetTop
    };

    paddleR = {
        x: document.getElementById('paddleR').offsetLeft,
        y: document.getElementById('paddleR').offsetTop
    };
    startGame();
}



function startGame(){
    alert("Get ready, and have fun!");
    //alert(ball.x + "," + ball.y);
    count = 0;
    clearInterval(render);
    render = setInterval(() => {
        updatePosition()
    }, 10);
    serveDirection = 1;
    document.getElementById('scoreR').innerHTML = rPt;
    document.getElementById('scoreL').innerHTML = lPt;
    newPoint();
}

function newPoint(){
    //alert("new point");
    document.getElementById('ball').style.left = 400 + "px";
    document.getElementById('ball').style.top = 300 + "px";
    ball.x = 400;
    ball.y = 300;
    var yQuad = 1;
    serveAngle = Math.floor(Math.random() * (135-44)) + 45;
    if(serveAngle > 90){
        serveAngle = 180 - serveAngle;
        yQuad = -1;
    } 
    if(serveDirection)
{        ball.xVel = 3 * (serveAngle / 90);
        serveDirection = 0;
}    else{
        ball.xVel = - (3 * (serveAngle / 90));
        serveDirection = 1;
    }

    ball.yVel = yQuad * (3 - Math.abs(ball.xVel));
    //document.getElementById('count').innerHTML = "angle: " + serveAngle + " velocity: " + (Math.abs(ball.xVel) + Math.abs(ball.yVel));
}

function updatePosition(){
    var moveX = ball.x + ball.xVel;
    var moveY = ball.y + ball.yVel;
    var xCol;
    var yCol;
    var lp = 0;
    var rp = 0;

    
    //document.getElementById('count').innerHTML = "check keys";
    onkeydown = onkeyup = function(e){
        map[e.key] = e.type == 'keydown';

    }
    
    //document.getElementById('count').innerHTML = map['ArrowUp'] +" "+ map['ArrowDown'];

    if((map['ArrowUp'] && !map['ArrowDown'])){
        if(paddleR.y - 3 >= 0){
            paddleR.y -= 3;
            document.getElementById('paddleR').style.top = paddleR.y + "px";
            rp = 1;
        }
    }
    else if (map['ArrowDown'] && !map['ArrowUp']){
        if(paddleR.y + 78 <= 600){
            paddleR.y += 3;
            document.getElementById('paddleR').style.top = paddleR.y + "px";
            rp = 1;
        }
    }

    if((map['w'] && !map['s'])){
        if(paddleL.y - 3 >= 0){
            paddleL.y -= 3;
            document.getElementById('paddleL').style.top = paddleL.y + "px";
            lp = 1;
        }
    }
    else if (map['s'] && !map['w']){
        if(paddleL.y + 78 <= 600){
            paddleL.y += 3;
            document.getElementById('paddleL').style.top = paddleL.y + "px";
            lp = 1;
        }
    }
    
    if (moveX < 10 && (moveY <= paddleL.y + 75 && moveY + 25 >= paddleL.y)){
        xCol = 1;
    }
    else if (moveX > 765 && (moveY <= paddleR.y + 75 && moveY +25 >= paddleR.y)){
        xCol = 1;
    }
    else if(moveX < 0 && (moveY > paddleL.y + 75 || moveY  < paddleL.y)){
        xCol = 1;
        rPt++;
        document.getElementById('scoreR').innerHTML = rPt;
        newPoint();
    }
    else if (moveX > 775){
        xCol = 1;
        lPt++;
        document.getElementById('scoreL').innerHTML = lPt;
        newPoint();
    }
    else
        xCol = 0;

    if(moveY > 0 && moveY + 25 < 600)
        yCol = 0;
    else
        yCol = 1;
    
    if(!xCol && !yCol){
        //alert("move");
        ball.x = moveX;
        ball.y = moveY;
        document.getElementById('ball').style.left = ball.x + "px";
        document.getElementById('ball').style.top = ball.y + "px";
    }
    if(xCol){
        ball.xVel = -(ball.xVel *1.002);
        if(ball.x < 400 && lp){
            ball.yVel *= 1.002;
        }
        if(ball.x > 400 && rp) {
            ball.yVel *= 1.002;
        }
        if(moveX > 400)
            document.getElementById('ball').style.left = "775px"
        else
            document.getElementById('ball').style.left = "0px"
    }

    if(yCol){
        ball.yVel = -(ball.yVel *1.001);
        if(moveY > 300)
            document.getElementById('ball').style.top = "575px"
        else
            document.getElementById('ball').style.top = "0px"
    }
    
    if(lPt == 10){
        alert("Red Player Wins!");
        lPt = 0;
        rPt = 0;
        startGame();
    }
    else if (rPt == 10){
        alert("Blue Player Wins!");
        lPt = 0;
        rPt = 0;
        startGame();
    }

    //frame counter
    //count++;
}

function pause() {
    if(running){
        clearInterval(render);
        running = 0;
        document.getElementById('pbut').innerHTML = "unpause";
    }
    else{
        render = setInterval(() => {
            updatePosition()
        }, 10);
        running = 1;
        document.getElementById('pbut').innerHTML = "pause";
    }
}