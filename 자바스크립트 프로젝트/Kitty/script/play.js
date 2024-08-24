const Motion = {
    Forward: 0,
    Backward: 1,
    Upward: 2,
    Downward: 3
};

let gamePiece;
let background;
let moveDirection = Motion.Forward;
let obstacle = [new Image(), new Image(), new Image()];

const pos = [350, 700, 1000];

const cheight = 300;
const cwidth = 800;

function startGame() {
    gamePiece = new component(63, 74, ["../Kitty/Resource/image/Kitty01.png",
        "../Kitty/Resource/image/Kitty02.png", "../Kitty/Resource/image/UKitty.png"], 100, 220, "character");
    background = new component(cwidth, cheight,"../Kitty/Resource/image/background.png", 0, 0, "background");
    obstacle[0] = new component(45, 77, "../Kitty/Resource/image/Cactus01.png", pos[0], 200, "obstacle");
    obstacle[1] = new component(70, 44, "../Kitty/Resource/image/Cactus02.png", pos[1], 230, "obstacle");
    obstacle[2] = new component(43, 33, "../Kitty/Resource/image/Rock.png",pos[2], 240, "obstacle");

    gameArea.start();
}

function component(width, height, src, x, y, type) {
    this.type = type;
    this.motion = 0;
   
    if(this.type == "character") {
        this.image = [new Image(), new Image(), new Image()];
        this.image[0].src = src[0];
        this.image[1].src = src[1];
        this.image[2].src = src[2];
        this.image[2].width = 102;
        this.image[2].height = 118;
    }
    else if(this.type == "background" || this.type == "obstacle") {
        this.image = new Image();
        this.image.src = src;
        this.image.width = width;
        this.image.height = height;
    }

    this.width = width;
    this.height = height;
    this.speedX = 0;
    this.speedY = 0;
    this.x = x;
    this.y = y;

    this.update = function() {
        ctx = gameArea.context;
        if(this.type == "character")
        {
            if(moveDirection != Motion.Downward && this.motion == 0)
            {
                ctx.drawImage(this.image[0], this.x, this.y, this.width, this.height);
                this.motion = 1;
            }
            else if(moveDirection != Motion.Downward && this.motion == 1)
            {
                ctx.drawImage(this.image[1], this.x, this.y, this.width, this.height);
                this.motion = 0;
            }
            else
            {
                ctx.drawImage(this.image[2], this.x, this.y, this.image[2].width,this.image[2].height);
            }
        }
        else if(this.type == "background" || this.type == "obstacle") {
            ctx.drawImage(this.image, this.x, this.y, this.width, this.height);
           
            if(this.type == "background")
                ctx.drawImage(this.image, this.x+this.width, this.y, this.width, this.height)
        }
    }
    this.newPos = function() {
        this.x += this.speedX;
        

        if(this.type == "background")
            if(this.x == -(this.width)) {
                this.x = 0;
            }
        if(this.type == "character")
        {
            this.y += this.speedY;
            if(moveDirection == Motion.Upward && this.y < 50)
            {
                this.speedY = 2;
                moveDirection = Motion.Downward;
            }
            else if(moveDirection == Motion.Downward && this.y + this.height >=220)
            {
                this.speedY = 0;
                this.motion = 0;
                this.y = 220;
                moveDirection = Motion.Forward;
            }
        }
        if(this.type == "obstacle")
        {
            this.x += -5;
            if(this.x + this.width < 0)
                this.x = cwidth + 200;
        }
    }
    
}
let gameArea = {
    canvas : document.createElement("canvas"),
    start : function() {
        this.canvas.width = cwidth;
        this.canvas.height = cheight;
        this.context = this.canvas.getContext("2d");
        document.body.insertBefore(this.canvas, document.body.childNodes[0]);
        this.interval = setInterval(updateGameArea, 50);
        window.addEventListener('keydown', function(e) {
            gameArea.keys = (gameArea.keys || new Set());
            gameArea.keys.add(e.code);
        });
        window.addEventListener('keyup', function(e) {
            gameArea.keys.delete(e.code);
        })
    },
    clear : function() {
        this.context.clearRect(0, 0, this.canvas.width, this.canvas.height);
    },

    stop : function() {
        clearInterval(this.interval);
    }
}

function updateGameArea() {
    gameArea.clear();

    background.speedX = -5 ;
    gamePiece.speedX = 0;

    if(moveDirection == Motion.Forward && gameArea.keys && gameArea.keys.has("Space"))
    {
        gamePiece.speedY = -5;
        moveDirection = Motion.Upward;
    }

    gamePiece.newPos();
    background.newPos();
    background.update();
    for(let i = 0; i < 3; i++)
    {
        obstacle[i].update();
        obstacle[i].newPos();
    }
    gamePiece.update();
}