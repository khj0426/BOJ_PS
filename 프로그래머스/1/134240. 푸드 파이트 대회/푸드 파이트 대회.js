//왼 -> 오

//오 -> 왼

//중앙에 물 -> 물을 먼저 먹는 선수 승리

//두 선수가 먹는 음식의 종류, 양이 같아야 한다

//음식의 순서도 같아야 함

//칼로리가 낮은 음식 먼저 배치

//3가지 음식, 칼로리가 적은 순서대로 1번 -> 3개 2번 ->4개 3번 ->6개 물 -> 0

//  arr1 1 2 2 3 3 3 0

// arr2 1 2 2 3 3 3

function solution(food) {
    var answer = '';
    
    let arr1 = [];
    let arr2 = [];
    let all = [];
    let m = new Map();
    
    for(let i = 1;i<food.length;i++){
        //i번음식이 몇개인지?
        m.set(i,food[i]);
    }
    //111 2222 333333
    for(let i = 1;i<food.length;i++){
        let count = food[i];
        if(food[i] % 2 !== 0){
            count = count - 1;
        }
        
        for(let j = 0;j<count;j++){
            if(j % 2 === 0){
                arr1.push(i);
            }
            else{
                arr2.push(i);
            }
        }
    } 
    
    let newArr = [...arr1,0,...arr2.reverse()].toString().replaceAll(",","");
    console.log(newArr);
    
    
    
    
    return newArr;
}