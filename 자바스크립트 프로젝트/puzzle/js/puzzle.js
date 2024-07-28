const puzzle = document.getElementById("puzzle");
const tiles = [];
let emp = 15;
let emptyTile = 0;
let emptyIdx;

for(let y = 0; y < 4 ; y++){
    for(let x = 0; x < 4; x++){
        tiles.push (`${x*-100}px ${y*-100}px`);
    }
}

let ran = [];

for(let i=0;i<16;i++){
    ran[i]=i;
}

// 무조건 풀수있는 랜덤
function shuffle(){
    let loop=10;
    let sw = 0;
    while(loop)
    {
        let ok=false;
        let dom = Math.floor(Math.random()*4);
        if(dom==0){
            if(emp>=4){
                sw=emp-4;
                ok=true;
            }
        }
        else if(dom==1){
            if(emp<=11){
                sw=emp+4;
                ok=true;
            }
        }
        else if(dom==2){
            if(emp%4!=0){
                sw=emp-1;
                ok=true;
            }
        } 
        else{
            if((emp+1)%4!=0){
                sw=emp+1;
                ok=true;
            }
        }
        if(ok){
            [ran[sw], ran[emp]] = [ran[emp], ran[sw]];
            emp = sw;
            loop--;
        }
    }
}

// 그냥 무작위 랜덤
// for(let i=0;i<30;i++){
//     let a = Math.floor(Math.random()*16);
//     let b = Math.floor(Math.random()*16);

//     while(b==a){
//         b=Math.floor(Math.random()*16);
//     }

//     [ran[a], ran[b]] = [ran[b], ran[a]];
// }

function move(tile){
    const background = emptyTile.style.background;
    emptyTile.classList.remove("empty");
    emptyTile.style.backgroundImage = tile.style.backgroundImage;
    emptyTile.style.backgroundPosition = tile.style.backgroundPosition;

    tile.style.background = background;
    tile.classList.add("empty");
    emptyTile = tile;
}

shuffle();
for(let i=0;i<16;i++){
    const tile = document.createElement("div");
    tile.className = "tile";
    tile.style.backgroundPosition = tiles[ran[i]];
    tile.addEventListener("click", (e)=>{
        if(i-4==emp && i>=4){
            move(tile);
            emp=i;
            [ran[emptyIdx], ran[i]] = [ran[i], ran[emptyIdx]];
            emptyIdx = i;
        }
        else if(i+4==emp && i<=11){
            move(tile);
            emp=i;
            [ran[emptyIdx], ran[i]] = [ran[i], ran[emptyIdx]];
            emptyIdx = i;
        }
        else if(i-1==emp && i%4!=0){
            move(tile);
            emp=i;
            [ran[emptyIdx], ran[i]] = [ran[i], ran[emptyIdx]];  
            emptyIdx = i;
        }
        else if(i+1==emp && (i+1)%4!=0){
            move(tile);
            emp=i;
            [ran[emptyIdx], ran[i]] = [ran[i], ran[emptyIdx]];
            emptyIdx = i;
        }
        setTimeout(complete, 1);
    });
    if(ran[i] ==15){
        tile.className = "empty";
        tile.classList.add("tile");
        emptyTile = tile;
        emptyIdx = i;
    }
    puzzle.appendChild(tile);
}

function complete(){
    let ok=true;
    for(let i=0;i<16;i++){
        if(ran[i]!=i){
            ok=false;
            break;
        }
    }
    if(ok){
        alert("와 이걸 맞추노 너는 천재다!!!!");
    }
}