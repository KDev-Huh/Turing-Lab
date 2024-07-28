const add = document.getElementById("add");
const addBox = document.getElementById("addWord");

add.addEventListener("click", () => {
    document.getElementById("addWord").style.display = "block";
});

function deleteadd(){
    document.getElementById("addWord").style.display = "none";
}


addBox.addEventListener("mousedown", (e) => {

    let shiftY = e.clientY - addBox.getBoundingClientRect().top;
    let shiftX = e.clientX - addBox.getBoundingClientRect().left;
    
    moveAt(e.pageX, e.pageY);

    function moveAt(pageX, pageY){
        addBox.style.left = pageX - shiftX + 'px';
        addBox.style.top = pageY - shiftY + 'px'; 
    }

    function onMouseMove(event) {
        moveAt(event.pageX, event.pageY);
    }

    document.addEventListener('mousemove',onMouseMove);

    addBox.addEventListener("mouseup", function() {
        document.removeEventListener("mousemove",onMouseMove);
        addBox.onmouseup = null;
    })
});

addBox.ondragstart = function() {
    return false;
}