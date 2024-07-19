const sliderBox = document.querySelector('.slider-box');
const slider = sliderBox.querySelector('.slider');

let slideIndex = 0;
let flag = 0;

const file = sliderBox.querySelectorAll('.file');
const files = sliderBox.querySelector('.files');

const total = file.length;

const sliderWidth = slider.clientWidth;  /* slider의 가로길이를 가져온다 */

const btnNext = sliderBox.querySelector('.btn-next');
const btnPrev = sliderBox.querySelector('.btn-prev');

btnNext.addEventListener('click', (e) => {      /* e는 이벤트 리스너에 의해 전달되는 이벤트 객체(좌표, 클릭되었는지등의 정보) */
    slideIndex += 1;
    if(slideIndex>5)
        slideIndex = 0;
    files.style.left = -sliderWidth * slideIndex + "px";
});
btnPrev.addEventListener('click', (e) => {
    slideIndex -= 1;
    if(slideIndex < 0)
        slideIndex = 5;
    files.style.left = -sliderWidth * slideIndex + "px";
});

const btnAuto = document.getElementById("autoplay");
const imgs = document.getElementsByClassName("file");

function next(){
    console.log(slideIndex);

    btnAuto.addEventListener('click', () => {
        clearInterval(next);
    });

    slideIndex += 1;
    if(slideIndex>5)
        slideIndex = 0;
    files.style.left = -sliderWidth * slideIndex + "px";
}

btnAuto.addEventListener('click', () =>{
    flag=!flag;
    let set = setInterval(() => {
        if(!flag){
            clearInterval(set);
            return;
        }
        for (let i = 0; i < imgs.length; i++) {
            imgs[i].addEventListener("click", function() {
                clearInterval(set);
                return;
            });
        }

        console.log(slideIndex);

        slideIndex += 1;
        if(slideIndex>5)
            slideIndex = 0;
        files.style.left = -sliderWidth * slideIndex + "px";
    },2000);
});

// function plusSlides(n){
//     showSlides(slideIndex += n);
// }

// function currentSlides(n){
//     showSlides(slideIndex = n);
// }