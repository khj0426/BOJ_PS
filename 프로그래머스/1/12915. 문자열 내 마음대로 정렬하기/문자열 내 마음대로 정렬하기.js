function solution(strings, n) {
    var answer = [];
    
    answer = strings.sort();
    console.log(answer);
    
    answer.sort((a,b) => {
        if(a[n].charCodeAt()!==b[n].charCodeAt()){
            return a[n].charCodeAt() - b[n].charCodeAt();
        }
    })
    return answer;
}