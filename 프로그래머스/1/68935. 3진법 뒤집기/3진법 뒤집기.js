function solution(n) {
    var answer = 0;
    let str = [...n.toString(3)].reverse().join('');
    
    for(let i = str.length-1;i>=0;i--){
        let pow = 1;
        for(let j = 0;j<(str.length-i-1);j++){
            pow = pow * 3;
        }
        answer = answer + (pow * str[i]);
    }
    return answer;
}