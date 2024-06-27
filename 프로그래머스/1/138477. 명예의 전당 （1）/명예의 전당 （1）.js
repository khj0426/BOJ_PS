function solution(k, score) {
    var answer = [];

    let arr = [];
    
    //매번 정렬을 해야하나??
    
    for(let i = 0;i<score.length;i++){
        arr.push(score[i]);
        let a = arr.sort((a,b) => b-a).slice(0,k);
        answer.push(a.pop());
    }
    return answer;
}