function solution(s) {
    var answer = '';
    
    answer = [...s].sort((a,b) => {
     
        return b.charCodeAt()-a.charCodeAt();
    })
    return answer.toString().replaceAll(",","");
}