function solution(number) {
    var answer = 0;
    let m = new Map();
    for(let i = 0;i<number.length;i++){
        for(let j = 0;j<number.length;j++){
            for(let z = 0;z<number.length;z++){
                if(i !== j && j !== z && z !== i){
                    if(number[i] + number[j] + number[z] === 0){
                        answer++;
                        let arr = [i,j,z].sort((a,b) => a-b).toString();
                        if(!m.has(arr)){
                            m.set(arr,arr);
                        }
                    }
                }
            }
        }
    }
    return m.size;
    return answer;
}