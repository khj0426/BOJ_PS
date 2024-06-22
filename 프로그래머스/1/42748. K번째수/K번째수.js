function solution(array, commands) {
    var answer = [];
    for(let i = 0;i<commands.length;i++){
        if(commands[i][0] === commands[i][1]){
            answer.push(array[commands[i][0]-1]);
        }
        else{
           let a = [...array].splice(commands[i][0]-1,commands[i][1] - commands[i][0] + 1).sort((a,b) => Number(a)-Number(b));
            console.log(a,array);
             answer.push(a[commands[i][2]-1]);
        }
    }
    return answer;
}