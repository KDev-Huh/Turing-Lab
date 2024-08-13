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

let word = document.getElementById('word');
let meaning = document.getElementById('meaning');
let addWord = document.getElementById('inputWord'); 
if(addWord.textContent=='')
    addWord.innerHTML = "아직 추가된 단어가 업습니다.";


document.getElementById('addBu').addEventListener('click', () => {
    if(word.value=='')
        alert("단어를 입력해주세요!");
    else if(meaning.value=='')
        alert("뜻을 입력해주세요!");
    else{
        if(addWord.textContent == "아직 추가된 단어가 업습니다.")
            addWord.innerHTML = "단어명 : " + word.value + " 뜻 : " + meaning.value + "<br>";
        else
            addWord.innerHTML += "단어명 : " + word.value + " 뜻 : " + meaning.value + "<br>";
    }
});
document.getElementById('canBu').addEventListener('click', () => {
    word.value = '';
    meaning.value = '';
});