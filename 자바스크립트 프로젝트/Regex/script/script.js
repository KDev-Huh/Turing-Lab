const inputs = document.querySelectorAll("input");

const control = {
    id: 0,
    pwd: 1,
    cp: 2,
    email: 3,
    send: 4,
    cancel: 5,
};

inputs.forEach((input, idx)=>{
    input.addEventListener('keydown', (e)=>{
        if(e.key == "Enter") {
                inputs[(idx+1)%6].focus();
        }
    });
});

function vaildID() {
    const idRegex = /(^[a-zA-Z]|\d){8,}$/;
    const id = inputs[control.id].value.trimStart().trimEnd();
    if(idRegex.test(id)) {
        alert("성공");
        return true;
    }
    else {
        alert("아이디가 형식에 맞지 않습니다.");
        inputs[control.id].focus();
        return false;
    }
}

function validPWD() {
    const pwdRegex = /^(?=.*[A-Z])(?=.*[a-z])(?=.*[!@#$%^&*])[A-Za-z\d!@#$%^&*]{8,}$/;
    const pwd = inputs[control.pwd].value.trimStart().trimEnd();

    if(pwdRegex.test(pwd)) {
        alert("성공")
        return true;
    }
    else {
        alert("비밀번호 형식에 맞지 않습니다.");
        inputs[control.pwd].focus();
        return false;
    }
}

function validCP() {
    const cellphoneRegex = /^\+?(\d{1,3})?[-.\s]?(\(?\d{1,4}\)?)?[-.\s]?\d{1,4}[-.\s]?\d{1,4}[-.\s]?\d{1,9}$/;
    const cellNumber = inputs[control.cp].value.trimStart().trimEnd();

    if(cellphoneRegex.test(cellNumber)) {
        alert("성공")
        return true;
    }
    else {
        alert("비밀번호 형식에 맞지 않습니다.");
        inputs[control.cp].focus();
        return false;
    }
}

const btnEnrol = document.getElementById("btnEnrol");

btnEnrol.addEventListener('click', ()=>{
    vaildID();
    validPWD();
})


const regex = /hello/i;
const str = "Hello world";
console.log(regex.test(str));