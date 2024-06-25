//s skip index

//s의 각 알파벳을 index만큼 뒤의 알파벳으로 바꿈

//index만큼 알파벳이 z를 넘어갈 경우 a로 돌아감

//skip에 있는 알파벳은 제외하고 건너뜀

//s = aukks
//skip = wbqd
//index = 5

//

function solution(s, skip, index) {
    var answer = '';
    let Z = 'z'.charCodeAt();
    let finalArr = [];
    let A = 'a'.charCodeAt();
    
    for(let i = 0;i<s.length;i++){
        finalArr = [];
        let c = s[i].charCodeAt();
        let arr = [];
        while(arr.length !== index){
            c++;
            if(c > Z){
                c = A;
            }
            arr.push(String.fromCharCode(c));
        }
        console.log(arr);
        
        
        for(let j = 0;j<arr.length;j++){
            if(!skip.includes(arr[j])){
                finalArr.push(arr[j]);
            }
        }
        if(finalArr[finalArr.length-1]?.charCodeAt()){
            
        c = finalArr[finalArr.length-1]?.charCodeAt();   
        }
       
        while(finalArr.length !== index){
               c++;
            if( c > Z){
                c = A;
            }
            if(skip.includes(String.fromCharCode(c))){
                continue;
            }
            finalArr.push(String.fromCharCode(c));
        }
        
        answer += finalArr[finalArr.length-1];
    }
    
        return answer;
    }
