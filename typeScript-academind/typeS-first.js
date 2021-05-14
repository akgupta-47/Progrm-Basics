var button = document.querySelector('button');
var input1 = document.getElementById('num1');
var input2 = document.getElementById('num2');
function add(num1, num2) {
    return num1 + num2;
}
// here typeScript automatically told us that as default javascript input is string no matter what, we need to first change it to number
/*
button.addEventListener("click", function(){
    console.log(add(input1,input2));
});
*/
button.addEventListener("click", function () {
    console.log(add(+input1, +input2));
});
