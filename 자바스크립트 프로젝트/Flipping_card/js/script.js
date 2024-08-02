const cardBox = document.querySelector(".card-container");
let firstCard = null, secondCard = null;

let scorebox = document.getElementById("score");
let score = 0;
let timebox = document.getElementById("time");
let time = 0;
let stopBtn = document.getElementById("stop");
let stop=false;
let timer;

stopBtn.addEventListener('click', function() {
    stop = !stop;

    if(stop){
        clearInterval(timer);
        stopBtn.innerText = 'go';
    } 
    else{
        timer = setInterval(()=>{
            timebox.innerText=++time;
        }, 1000);
        stopBtn.innerText = 'stop';
    }
});


function show() {
    document.getElementById("win").style.display = "block";
    setTimeout(() => {
        document.getElementById("win").style.display = "none";
    }, 1500);
}


// 그 전에 들어간 친구가 있는지 확인하는 변수
let canGo = false;

function cardClick() {
    if(stop || canGo)
        return;
    this.classList.toggle('is-flipped');
    if(firstCard == null){
        firstCard = this;
    }
    else{
        if(this == firstCard){
            firstCard = null;
            return;
        }
        canGo = true;
        setTimeout(()=>{
            if(firstCard.dataset.value == this.dataset.value){
                firstCard.removeEventListener('click', cardClick);
                this.removeEventListener('click', cardClick);
                scorebox.innerText = ++score;
                show();
            }
            else{
                this.classList.toggle('is-flipped');
                firstCard.classList.toggle('is-flipped');
            }
            firstCard = null;
            canGo=false;
        }, 1000);
    }
    
}

let cards = [];
let cardType = ['c', 'd', 'h', 's']

// 리스트에 URL 주기
function cardIdx() {
    for(let i = 0; i < 25; i++ )
    {
        let cardT = Math.floor(Math.random()*4);
        let num = Math.floor(Math.random()*13) + 1;

        let src = cardType[cardT] + num + ".png";
        cards.push(src);
        cards.push(src);
    }
}

// 셔플
function shuffle() {
    for(let i = 0; i < 100 ; i++)
    {
        let num1 = Math.floor(Math.random()*50);
        let num2 = Math.floor(Math.random()*50);

        [cards[num1], cards[num2]] = [cards[num2], cards[num1]];
    }
}

function create() {
    cardIdx();
    shuffle();
    for(let i = 0; i < 50 ; i++)
        createCard(cards[i]);
}


function createCard(src)
{
    card = document.createElement("div");
    imgFront = document.createElement("img");
    imgBack = document.createElement("img");
    cardFront = document.createElement("div");
    cardBack = document.createElement("div");

    imgFront.src = "./img/MemoryGame/" + src;
    imgBack.src = "./img/MemoryGame/bb.png";

    card.classList.add("card");
    card.classList.add("is-flipped");
    card.addEventListener('click', cardClick);
    card.dataset.value = src;

    cardFront.classList.add("card-face");
    cardFront.classList.add("card-front");

    cardBack.classList.add("card-face");
    cardBack.classList.add("card-back");

    cardFront.appendChild(imgFront);
    cardBack.appendChild(imgBack);

    card.appendChild(cardFront);
    card.appendChild(cardBack);

    cardBox.appendChild(card);
}

let start = document.getElementById("start");

start.addEventListener("click", ()=>{
    cardBox.innerHTML = "";
    clearInterval(timer);
    time = 0;
    timebox.innerText=time;
    score = 0;
    create();
    timer = setInterval(()=>{
        timebox.innerText=++time;
    }, 1000);
});
