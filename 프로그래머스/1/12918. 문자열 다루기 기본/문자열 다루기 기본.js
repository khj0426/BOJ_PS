
function solution(s) {
    var answer = false;
    const nums = [0,1,2,3,4,5,6,7,8,9];
    if(s.length === 4){
        answer = [...s].every((eachS) => nums.includes(Number(eachS)));
    }
    else if(s.length === 6){
        answer = [...s].every((eachS) => nums.includes(Number(eachS)));
    }
    return answer;
    
}