import data from "../data.js"

let input_pages = document.getElementById("pagindated-list");
let beforeBtn = document.getElementById("prev-button");
let nextBtn = document.getElementById("next-button");
let pageBtns = document.getElementById("pagination-numbers");

let countPage = 0;
let pageNum = 1;

//  작성중....
// function setNumBtn() {
//     for(let i = pageNum; )
//     let Btn = document.createElement("button");
//     Btn.value = 
// }

function setBtn(beforeBtn, nextBtn) {
    if(countPage < 10) {
        beforeBtn.disabled = true;
        nextBtn.disabled = false;
    } else if(countPage + 10 > data.length) {
        beforeBtn.disabled = false;
        nextBtn.disabled = true;
    } else {
        beforeBtn.disabled = false;
        nextBtn.disabled = false;
    }
}

function createWrite() {
    setBtn(beforeBtn, nextBtn);

    for(let i = countPage; i <= countPage+10; i++) {
        let li = document.createElement("li");
        li.innerText = data[i];
        input_pages.appendChild(li);
    }
}

beforeBtn.addEventListener("click", ()=> {
    countPage-=10;
    input_pages.innerHTML = '';
    createWrite();
})

nextBtn.addEventListener("click", ()=> {
    countPage+=10;
    input_pages.innerHTML = '';
    createWrite();
})

createWrite();