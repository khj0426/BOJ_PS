function solution(numbers) {
    var answer = [];
    let exist = [];
    for(let i = 0;i<numbers.length;i++){
        exist.push(false);
    }
    let s = new Set();
    
    function permutate(arr,n){
        if(arr.length === 2){
            s.add(arr[0] + arr[1]);
            return;
        }
        
        for(let i = 0;i<exist.length;i++){
            if(exist[i]){
                continue;
            }
            arr.push(numbers[i]);
            exist[i] = true;
            permutate(arr,n+1);
            exist[i] = false;
            arr.pop();
        }
        
    }
    
    permutate([],0);
    answer = [...s].sort((a,b) => a-b);
    return answer;
}