function solution(s) {
    var answer = '';
    //모든 단어의 첫 문자가 대문자
    //그 외의 알파벳은 소문자
    
    //첫문자가 알파벳이 아닐 떄, 이어지는 알파벳은 소문자
    
    //3people unFollowed me
    
    //3people Unfollowed Me
    //
    
    const a = 'a'.charCodeAt();
    const z = 'z'.charCodeAt();
    const res = s.split(" ").map((s) => {
        return [...s].map((eachS,index) => {
            if(index === 0 ){
                return eachS.toUpperCase();
            }
            else{
                return eachS.toLowerCase();
            }
        }).toString().replaceAll(",","");
    }).toString().replaceAll(","," ");
    
    return res;
    return answer;
}