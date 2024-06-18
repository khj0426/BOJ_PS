function solution(s) {
    var answer = [];
    let m = new Map();
    
    for(let i = 0;i<s.length;i++){
        if(!m.has(s[i])){
            m.set(s[i],i);
            answer.push(-1);
        }
        else{
            console.log(i,s[i]);
            let getI = m.get(s[i]);
            console.log(i - getI);
            answer.push(i - getI);
            m.set(s[i],i);
        }
    }
    return answer;
}