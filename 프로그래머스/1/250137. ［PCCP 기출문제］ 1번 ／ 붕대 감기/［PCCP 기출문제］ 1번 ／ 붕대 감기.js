//[공격 시간,피해량]

//[몇 초 동안 기다려야 하는지? , 초당 회복 , 추가 회복]

// 캐릭터 체력 0이하 -> -1


function solution(bandage, health, attacks) {
    var answer = 0;
    //언제 공격이 들어오는 지 등록
    
    let h = health;
    let attack = new Map();
    
    for(let i = 0;i<attacks.length;i++){
        attack.set(attacks[i][0],attacks[i][1]);
    }
    console.log(attack);
    
    //이제 시간만큼 쭉 돌면서
    let maxTime = attacks[attacks.length-1][0];
    
    
    let 연속성공 = 0;
    for(let i = 0;i<=maxTime;i++){
        console.log(h,i);
        if(h <= 0){
            h = -1;
            break;
        }
        
        //만약 특정 초만큼 공격 성공 시 추가회복 후 연속 공격 초기화
        if(연속성공 === bandage[0]){
            연속성공 = 0;
            h = h + bandage[2];
            if(h >= health){
                h = health;
            }
        }
        
        //만약 몬스터의 공격이 있으면 연속 공격 초기화
        if(attack.has(i)){
            연속성공 = 0;
            let v = attack.get(i);
            h = h - v;
        }
        else{
            연속성공++;
            h = h + bandage[1];
            if(h >= health){
                h = health;
            }

        }
        
        
    }
    
    answer = h;
    if(answer <= 0){
        return -1;
    }
    return answer;
}