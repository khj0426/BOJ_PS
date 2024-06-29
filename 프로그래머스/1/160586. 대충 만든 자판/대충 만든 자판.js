function solution(keymap, targets) {
    var answer = [];
    //ABCD
    
    //
    
    
    let m = new Map();
    
    for(let i = 0;i<keymap.length;i++){
        for(let j = 0;j<keymap[i].length;j++){
            let target = keymap[i][j];
            if(m.has(target)){
                let g = m.get(target);
                if(g > j){
                    m.set(target,j+1);
                }
            }
            else{
                m.set(target,j+1);
            }
        }
    }
    
    for(let i = 0;i<targets.length;i++){
        let count = 0;
        for(let j = 0;j<targets[i].length;j++){
            if(!m.has(targets[i][j])){
                count = -1;
                break;
            }
            else{
                count += m.get(targets[i][j]);
            }
        }
        answer.push(count);
    }
    return answer;
}