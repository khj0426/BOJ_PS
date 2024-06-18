function solution(s) {
    var answer = 0;
    let START = "";
    
    let mapx = new Map();
    let mapnotx = new Map();
    
    for(let i = 0;i<s.length;i++){
        console.log(mapx);
        if(mapx.size === 0){
            START = s[i];
            mapx.set('x',1);
            mapnotx.delete('notx');
        }
        else{
            if(s[i] === START){
                console.log(START);
                let count = mapx.get('x');
                console.log(Number(count+1));
                mapx.set('x',Number(count+1));
            }
            else{
                if(mapnotx.size === 0){
                    mapnotx.set('notx',1);
                }
                else{
                    let count = mapnotx.get('notx');
                    mapnotx.set('notx',Number(count+1));
                    
                    
                }
                if(mapnotx.get('notx') === mapx.get('x')){
                        answer = answer + 1;
                        mapx.delete('x');
                    }
            }
        }
    }
    
    if(mapx.size !== 0){
        answer++;
    }
    
    
    return answer;
}