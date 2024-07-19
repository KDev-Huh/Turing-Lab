const sliderBox = document.querySelector('.slider-box'); /* 슬라이드 박스라는 클래스의 문서를 가져옴 */
const slider = sliderBox.querySelector('.slider');

let slideIndex = 0;     /* 사진의 이동 번호 */
let flag = 0;       /* auto버튼이 켜져있는지 꺼져있는지 확인하는 변수 */

const file = sliderBox.querySelectorAll('.file');
const files = sliderBox.querySelector('.files');

const total = file.length;  /* 파일의 갯수를 가져옴 */

const sliderWidth = slider.clientWidth;  /* slider의 가로길이를 가져온다 */

const btnNext = sliderBox.querySelector('.btn-next');
const btnPrev = sliderBox.querySelector('.btn-prev');

btnNext.addEventListener('click', (e) => {      /* e는 이벤트 리스너에 의해 전달되는 이벤트 객체(좌표, 클릭되었는지등의 정보) */
    slideIndex += 1;
    if(slideIndex>total-1)        /* 사진번호가 마지막 사진보다 크다면 0으로 (-1을 하는이유는 인덱스 번호가 0부터 시작하기 때문이다)*/
        slideIndex = 0;
    files.style.left = -sliderWidth * slideIndex + "px";    /* 사진의 번호 * slider의 길이 = 파일스의 위치를 달라진 위치로 이동시킨다.*/
});
btnPrev.addEventListener('click', (e) => {
    slideIndex -= 1;
    if(slideIndex < 0)      /* 사진번호가 첫번째보다 작다면 total-1로 */
        slideIndex = total-1;
    files.style.left = -sliderWidth * slideIndex + "px";        /* -하는 이유는 margin-left와 같이 왼쪽으로 이동해야하기 때문에 */
});

const btnAuto = document.getElementById("autoplay");
const imgs = document.getElementsByClassName("file");

btnAuto.addEventListener('click', () =>{    /* auto버튼을 눌렀을때 */
    flag=!flag;
    let set = setInterval(() => {       /* 밑에 초마다 함수를 호출 */
        if(!flag){      /* 만약 auto가 돌아가다가 눌렀다면 */
            clearInterval(set);     /* interval 객체를 삭제 */
            return;
        }
        slideIndex += 1;
        if(slideIndex>5)
            slideIndex = 0;

        imgs[slideIndex].addEventListener("click", function() {     /* 현재 사진을 누르면 auto중지 */
            clearInterval(set);
            return;
        });
        console.log(slideIndex);

        files.style.left = -sliderWidth * slideIndex + "px";    /* 사진 왼쪽으로 이동 */
    },2000);
});

// function plusSlides(n){
//     showSlides(slideIndex += n);
// }

// function currentSlides(n){
//     showSlides(slideIndex = n);
// }