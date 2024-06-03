//N/2마리
//[3,1,2,3]
//3번 포켓몬 2마리, 1번 포켓만 1마리, 2번 포켓몬 1마리
//set로 바꾸면

//123

//234
//23

function solution(nums) {
    var answer = 0;
    const lengthHalf = nums.length/2;
    
    const arrayToSet = new Set(nums)
    if(arrayToSet.size < lengthHalf){
        answer = arrayToSet.size;
    }
    else{
        answer = lengthHalf;
    }
    return answer;
}