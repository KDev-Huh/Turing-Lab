const puzzle = document.getElementById("puzzle");
const tiles = [];

for(let y = 0; y < 4 ; y++){
    for(let x = 0; x < 4; x++){
        tiles.push (`${x*-100}px ${y*-100}px`);
    }
}

let ran = [];

for(let i=0;i<16;i++){
    ran[i]=i;
}

for(let i=0;i<30;i++){
    let a = Math.floor(Math.random()*16);
    let b = Math.floor(Math.random()*16);

    while(b==a){
        b=Math.floor(Math.random()*16);
    }

    [ran[a], ran[b]] = [ran[b], ran[a]];
}

for(let i=0;i<16;i++){
    const tile = document.createElement("div");
    
    if(ran[i] !=15){
        tile.className = "tile";
        tile.style.backgroundPosition = tiles[ran[i]];
    }
    else
        tile.className = "empty";
    puzzle.appendChild(tile);
}