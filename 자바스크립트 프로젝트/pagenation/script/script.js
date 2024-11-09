import data from "../data.js"

let input_pages = document.getElementById("pagindated-list");
let beforeBtn = document.getElementById("prev-button");
let nextBtn = document.getElementById("next-button");
let pageBtns = document.getElementById("pagination-numbers");

let countPage = 0;
let pageNum = 0;
const MAX_DATA = Math.floor(data.length/10);


function setNumBtn() {
    pageBtns.innerHTML = '';
    for(let i = pageNum; i < pageNum + 5; i++) {
        if(i > MAX_DATA)
            break;
        let Btn = document.createElement("button");
        Btn.innerText = i + 1;
        Btn.addEventListener("click", () => {
            countPage = 10 * i;
            createWrite();
        })
        pageBtns.appendChild(Btn);
    }
}

function setBtn(beforeBtn, nextBtn) {
    if(pageNum < 5) {
        beforeBtn.disabled = true;
        nextBtn.disabled = false;
    } else if(pageNum+5 >= MAX_DATA) {
        beforeBtn.disabled = false;
        nextBtn.disabled = true;
    } else {
        beforeBtn.disabled = false;
        nextBtn.disabled = false;
    }
}

function createWrite() {
    input_pages.innerHTML = '';
    for(let i = countPage; i <= countPage+10; i++) {
        if(data[i] == undefined)
            break;
        let li = document.createElement("li");
        li.innerText = data[i];
        input_pages.appendChild(li);
    }
}

beforeBtn.addEventListener("click", ()=> {
    pageNum-=5;
    setNumBtn();
    setBtn(beforeBtn, nextBtn);
})

nextBtn.addEventListener("click", ()=> {
    pageNum+=5;
    setNumBtn();
    setBtn(beforeBtn, nextBtn);
});

setNumBtn();
setBtn(beforeBtn, nextBtn);
createWrite();