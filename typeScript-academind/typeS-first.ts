const button = document.querySelector('button');
const input1 = document.getElementById('num1')! as HTMLInputElement;
const input2 = document.getElementById('num2')! as HTMLInputElement;

function add(num1: number, num2: number){
    return num1 + num2;
}

// here typeScript automatically told us that as default javascript input is string no matter what, we need to first change it to number
/*
button.addEventListener("click", function(){
    console.log(add(input1,input2));
});
*/
button.addEventListener("click", function(){
    console.log(add(+input1 , +input2));
});