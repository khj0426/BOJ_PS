function solution(babbling) {
    var answer = 0;
    
    
    for(let i = 0;i<babbling.length;i++){
        babbling[i] = babbling[i].replaceAll("aya","#");
        babbling[i] = babbling[i].replaceAll("ye","!");
        babbling[i] = babbling[i].replaceAll("woo","@");
        babbling[i] = babbling[i].replaceAll("ma","$");
        console.log(babbling[i]);
    }
    
    for(let i = 0;i<babbling.length;i++){
        if(babbling[i] === "#" || babbling[i] == "!" || babbling[i] === "@" || babbling[i] === "$"){
            answer++;
            console.log(babbling[i],i);
        }
        else{
            let hasAlpha = [...babbling[i]].some((s) => s >= 'a' && s <= 'z');
            console.log(hasAlpha);
            if(!hasAlpha){
                let same = false;
                //같은 것이 연속
                for(let j = 0;j<babbling[i].length-1;j++){
                    if(babbling[i][j] === babbling[i][j+1]){
                        same = true;
                        break;
                    }
                }
                if(same === false){
                    answer++;
                }
            }
        }
    } 
    
    return answer;
}