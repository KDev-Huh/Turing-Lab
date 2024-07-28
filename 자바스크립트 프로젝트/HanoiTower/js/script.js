// The variable discCount holds the number of disk.
let discCount = 0;
// The variable move holds the number of transferred disk.
let move = 0;
let moveLabel = undefined;
let complete = false;
let isDraggable = true;

function discEnter()
{
    if (this.id !== this.parentNode.lastElementChild.id)
    {
        isDraggable = false;                        
    }
    else
    {
        isDraggable = true;
        this.classList.add("dragging");
    }
}

function discLeave()
{
    this.classList.remove("dragging");
}

function dragStart (e) {
    if (!isDraggable)
        return;

    e.dataTransfer.setData('text/plain', this.id);
    this.classList.add("dragging");
    console.log(this.classList);
    setTimeout(() => {
        this.style.display = 'none';
    }, 0);
}

function dragEnd (e) {
    if (!isDraggable)
        return;

    this.classList.remove("dragging");
    setTimeout(() => {
        this.style.display = 'block';
    }, 0);    
}

function towerReset()
{   
    const towers = document.querySelectorAll('.tower');
  
    towers.forEach((tower) => {
        tower.childNodes.forEach((disc) => {
            disc.setAttribute('draggable', 'false');
        });

        /*
            If the tower.lastElementChild is null, the attribute setAttribute is not existed.
        */

        if(tower.lastElementChild !== null && !complete)
            tower.lastElementChild.setAttribute('draggable', 'true');
    });
}

/*
    The inserted disc must be smaller than the top disc.
*/
function addDisk()
{
    if (discCount >= 13)
        return;
    
    let tower = document.getElementById("towerA");

    const disc = document.createElement("div")
    disc.classList.add('disc');

    let width = 200 - (discCount * 10);
    disc.style.width = width.toString() + 'px';
    disc.id = 'disc' + discCount;
    
    discCount++;
    tower.appendChild(disc);
        
    disc.ondragstart = dragStart;    
    disc.ondragend = dragEnd;    
    disc.onmouseenter = discEnter;
    disc.onmouseleave = discLeave;

    towerReset();    
}

function isSuccess()
{
    const countDiskOfTowerA = document.getElementById("towerA").childElementCount;
    const countDiskOfTowerB = document.getElementById("towerB").childElementCount;
        
    if ((countDiskOfTowerA + countDiskOfTowerB) === 0)
    {
        let msgSuccess = document.getElementById('msgSuccess');
        msgSuccess.style.display = 'block';
        
        document.getElementById("towerC").childNodes.forEach( (elem) => {
            elem.setAttribute('draggable', 'false')
        });

        complete = true;
    }
}

function refresh()
{
    const towers = document.querySelectorAll('.tower');

    towers.forEach((tower) => {
        tower.innerHTML = "";
    });

    move = discCount = 0;

    let msgSuccess = document.getElementById('msgSuccess');
    msgSuccess.style.display = 'none';
    complete = false;
}

function hanoi(n, src, dest, aux)
{
    if (n == 0)
        return;

    hanoi(n - 1, src, aux, dest);
    console.log('Move disk ' + n + ' from ' + src + ' to ' + target);
    hanoi(n - 1, aux, dest, src);
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
            if (!isDraggable)
                return;

            e.preventDefault();
            const id = e.dataTransfer.getData('text');
            const disc = document.getElementById(id);

            // It cannot put a smaller disc onto a larger one.
            if (tower.lastElementChild === null || tower.lastElementChild.id < disc.id)
            {
                tower.appendChild(disc);
                disc.style.display = 'block';
                move++;
                moveLabel.textContent = move.toString();
            }

            towerReset();           
            isSuccess(); 
        });
    });    
});