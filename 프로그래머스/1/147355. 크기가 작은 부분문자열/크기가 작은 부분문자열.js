//t에서 p와 길이가 같은 부분문자열
//부분문자열을 나타내는 수가 p가 나타내는 수보다 작거나 같은 것

//t = 3141592

//p = 271

//
function solution(t, p) {
    var answer = 0;
    
    let lengthof = p.length;
    let arr = [];
    for(let i = 0;i<t.length-lengthof+1;i++){
        arr.push(Number(t.substring(i,lengthof + i)));
    }
    for(let i = 0;i<arr.length;i++){
        console.log(arr[i]);
        if(Number(p) >= arr[i]){
            answer++;
        }
    }
    return answer;
}