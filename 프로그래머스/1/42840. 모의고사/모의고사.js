function solution(answers) {
    var answer = [];
    let FIRST = "12345";
    let SECOND = "21232425";
    let THIRD = "3311224455";
    
    let f = "12345";
    let s = "21232425";
    let t = "3311224455";
    
    let af = 0;
    let sf = 0;
    let tf = 0;
    
    
    for(let i = 0;i<answers.length;i++){
        
        if(i >= f.length){
            f += FIRST;
        }
         if(i >= s.length){
            s += SECOND;
        }
         if(i => t.length){
            t += THIRD;
        }
        if(answers[i]== f[i]){
            af = af + 1;
        }
         if(answers[i]== s[i]){
            sf = sf + 1;
        }
         if(answers[i]== t[i]){
            tf = tf + 1;
        }
        
        
    }
    
    if(af > sf && af > tf){
        return [1];
    }
    else if(sf > af && sf > tf){
        return [2];
    }
    else if(tf > af && tf > sf){
        return [3];
    }
    
    else if(af === sf && af === tf){
        return [1,2,3];
    }
    else if(af === sf){
        return [1,2];
    }
    else if(af === tf){
        return [1,3];
    }
    else if(sf === tf){
        return [2,3];
    }
    return answer;
}