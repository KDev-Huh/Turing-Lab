let board = document.getElementById("board");

const boards = [[1, 0, 0, 0], 
                [1, 1, 0, 1],
                [1, 1, 0, 0], 
                [0, 1, 1, 1]]

const N = 4;

const moves = [[1, 0], [0, -1], [0, 1], [-1, 0]];
let tile = new Array(N);

const cStreet = "cell street";
const cBlock = "cell wall"
const dest = "cell dest";
const rat = "cell rat";
const destRat = "cell destRat";

let map = [[1, 0, 0, 0], 
            [1, 1, 0, 1],
            [1, 1, 0, 0], 
            [0, 1, 1, 1]]

const direction = ['D', 'L', 'R', 'B']
let result = [];
let path = '';

let row = 0;
let col = 0;

function isVaildPath(row, col)
{
    return row >= 0 && col >= 0 && row < N && col < N && map[row][col];
}

function print() {

}

let beforeX;
let beforeY;
function launch() {
    let x = row;
    let y = col;
    map[x][y] = 0;
    if(x==3 && y==3)
    {
        map[row][col] = 1;
        result.push(path);
        beforeX = x;
        beforeY = y;
        return;
    }
    for(let i = 0; i < N; i++) {
        let nextX = x + moves[i][0];
        let nextY = y + moves[i][1];
        if(isVaildPath(nextX, nextY)) {
            row = nextX;
            col = nextY;
            console.log(row, col);
            path += direction[i];
            break;
        }
    }
    
    launch();

    // 다른길 찾기
    map[x][y] = 1;

    for(let i = 0; i < N; i++)
    {
        let nextX = x + moves[i][0];
        let nextY = y + moves[i][1];
        
        if(nextX == beforeX && nextY == beforeY)
            continue;
        console.log(x, y, beforeX, beforeY);
        console.log(moves[i]);
        if(isVaildPath(nextX, nextY)) {
            row = nextX;
            col = nextY;
            console.log('back ', row, col);
            launch();
        }
    }
    
    return;
}


function createBoard() {

    for(let i = 0; i < N; i++) {
        tile[i] = new Array(N);
    }

    for(let i = 0; i < 4; i++) {
        let tileBox = document.createElement('div');
        tileBox.className = "tileBox";
        for(let j = 0; j < 4; j++) {
            let block = document.createElement('div');
            tile[i][j] = block;
            if(boards[i][j]) {
                block.className = cStreet;
            }
            else {
                block.className = cBlock;
            }
            tileBox.appendChild(block);
        }
        board.appendChild(tileBox);
    }
    tile[0][0].className = rat;
    tile[3][3].className = dest;
}

createBoard();