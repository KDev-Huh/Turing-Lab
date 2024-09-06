// printBox = document.getElementById('numbers');

// function reverse(start, end) {
//     if(start > end) {
//         printBox.innerHTML += "<br>";
//         return;
//     }
    
//     printBox.innerText += start;
    
//     reverse(start+1, end);

//     printBox.innerText += start;
// }

// reverse(1, 10);

const GoKnigh = document.getElementById('GoKnigh');
const board = document.getElementById('board');
const N = 8;
let dboard = new Array(N);

darkTile = 'cell darkTile';
brightTile = "cell brightTile";
darkTileK = 'cell darkTileK';
brightTileK = 'cell brightTileK';

let sol = [
    [0, -1, -1, -1, -1, -1, -1, -1], [-1, -1, -1, -1, -1, -1, -1, -1],
    [-1, -1, -1, -1, -1, -1, -1, -1], [-1, -1, -1, -1, -1, -1, -1, -1],
    [-1, -1, -1, -1, -1, -1, -1, -1], [-1, -1, -1, -1, -1, -1, -1, -1],
    [-1, -1, -1, -1, -1, -1, -1, -1], [-1, -1, -1, -1, -1, -1, -1, -1]
]

const moves = [[2, 1], [1, 2], [-1, 2], [-2, 1], [-2, -1], [-1, -2], [1, -2], [2, -1]];


GoKnigh.addEventListener('click', ()=>{
    interval = setInterval(showTour, 500);
});


function drawBoard()
{
    for(let i = 0; i < N; i++)
    {
        dboard[i] = new Array(N);
    }

    for(let i = 0; i < N; i++)
    {
        tileBox = document.createElement('div');
        tileBox.className = "cellBox"
        for(let j = 0; j < N; j++)
        {
            tile = document.createElement('div');
            dboard[i][j] = tile;
            if((i+j)%2)
                tile.className = darkTile;
            else
                tile.className = brightTile;
            tileBox.appendChild(tile);
        }
        board.appendChild(tileBox);
    }
    dboard[0][0].className = brightTileK;
}

function canGo(y, x)
{
    //console.log(y,x);
    return x >= 0 && y >= 0 && x < N && y < N && sol[y][x] == -1;
}

let move = 0;
let lastX = 0;
let lastY = 0;
function showTour()
{

    if(move == 64) {
        clearInterval(interval);
        return;
    }

    if((lastX + lastY)%2)
        dboard[lastY][lastX].className = darkTile;
    else
        dboard[lastY][lastX].className = brightTile;

    dboard[lastY][lastX].innerText = move++;

    for(let r = 0; r < N; r++)
    {
        for(let c = 0; c < N; c++)
        {
            if(sol[r][c] == move)
            {
                lastY = r;
                lastX = c;
                if(((r+c)%2))
                    dboard[r][c].className = darkTileK;
                else
                    dboard[r][c].className = brightTileK;
            }
        }
    }
}

function KnightTour(x, y, moveCount)
{
    if(moveCount == 64){
        console.log(sol);
        return 1;
    }

    for(let i = 0; i < N; i++)
    {
        let NX = x + moves[i][1];
        let NY = y + moves[i][0];

        if(canGo(NY, NX)){
            sol[NY][NX] = moveCount;

            if(KnightTour(NX, NY, moveCount + 1) == 1)
                return 1;
            else
                sol[NY][NX] = -1;
        }
    }

    return 0;
}


drawBoard();
KnightTour(0, 0, 1);