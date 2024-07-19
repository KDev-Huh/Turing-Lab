let discCount = 0;
let move = 0;
let moveLabel = undefined;

function dragStart(e) {
    e.dataTransfer.setData('text/plain', this.id);
    setTimeout(() => {
        this.style.display = 'none';
    }, 0);
}

function dragEnd(e){
    this.classList.remove("dragging");
    setTimeout(() => {
        this.style.display = 'block';
    }, 0);
}

function isSuccess(){
    let towerA = document.getElementById("towerA").childElementCount;
    let towerB = document.getElementById("towerB").childElementCount;

    if(towerA==0 &&  towerB==0)
        document.getElementById("msgSuccess").style.display = 'block';
}


document.addEventListener('DOMContentLoaded', (event) => {
    let towers = document.querySelectorAll('.tower');
    moveLabel = document.getElementById('moveCount');

    moveLabel.textContent = move.toString();
    towers.forEach((tower) => {
        tower.addEventListener('dragover', (e) => {
            e.preventDefault();
        });

        tower.addEventListener('drop', (e) => {
            e.preventDefault();
            const id = e.dataTransfer.getData('text');
            const disc = document.getElementById(id);

            if(tower.lastElementChild === null  || tower.lastElementChild.id < disc.id)
            {
                tower.appendChild(disc);
                disc.style.display = 'block';
                move++;
                moveLabel.textContent = move.toString();
                
                isSuccess();
            }
        });
    });
    
});


function addDisk(){

    if(discCount >= 13)
        return;
    let towerA = document.getElementById("towerA");
    
    const disc = document.createElement("div");
    disc.classList.add('disc');

    let width = 200 - (discCount * 10);
    disc.style.width = width.toString() + 'px';
    disc.id = 'disc' + discCount; //각 드스크당 id를 주는것

    discCount++;
    towerA.appendChild(disc);

    disc.ondragstart = dragStart;   //드레그가 시작되면 dragStart를 시작
    disc.ondragend = dragEnd;

    towerReset();
}

function refresh(){
    let towers = document.querySelectorAll('.tower');

    towers.forEach((tower) => {     //하나씩 tower로 들어감
        tower.innerHTML = "";
    });

    move = discCount = 0;

    let msgSuccess = document.getElementById('msgSuccess');
    msgSuccess.style.display = 'none';
}