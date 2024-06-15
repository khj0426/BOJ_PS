//AB는 1만큼 밀면 BC

//3만큼 밀면 DE

//B1C2D3

//Z는 1만큼 밀면 a가 된ㅁ다.

//s를 n만큼 민 암호문을 만드는 함수 


function solution(s, n) {
    var answer = [];
    const MAX_CHARCODE_Z = 'Z'.charCodeAt();
    const MAX_CHARCODE_z = 'z'.charCodeAt();
    
    const MIN_CHARCODE_A = 'A'.charCodeAt();
    const MIN_CHARCODE_a = 'a'.charCodeAt();
    
    
    [...s].forEach((eachS) => {
        if(eachS === ' '){
            answer.push(eachS);
        }
        else{
            var startCharCode = eachS.charCodeAt();
            for(i = 0;i<n;i++){
            
                if(startCharCode >= MIN_CHARCODE_A && startCharCode <= MAX_CHARCODE_Z){
                    if(startCharCode >= MAX_CHARCODE_Z){
                        startCharCode = MIN_CHARCODE_A;
                    }
                    else{
                        startCharCode++;
                    }
                }
                else if(startCharCode >= MIN_CHARCODE_a && startCharCode <= MAX_CHARCODE_z){
                    if(startCharCode >= MAX_CHARCODE_z){
                        startCharCode = MIN_CHARCODE_a;
                    }
                    else{
                        startCharCode++;
                    }
                }
                
            }
            console.log(String.fromCharCode(startCharCode));
            answer.push(String.fromCharCode(startCharCode));
        }
    })
    console.log(answer);
    return answer.toString().replaceAll(',','');
}