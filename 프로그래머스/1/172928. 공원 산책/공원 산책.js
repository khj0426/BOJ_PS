//[방향거리,방향거리]

//E5 동쪽으로 5칸

// 공원을 벗어나는지 확인

// 장애물을 만나는지 확인

//

function solution(park, routes) {
    var answer = [];
    let visited = [];
    let start = [];
    let maxX = park.length;
    let maxY = park[0].length;
    for(let i = 0;i<park.length;i++){
        for(let j = 0;j<park[i].length;j++){
            if(park[i][j] === "S"){
                start.push([i,j]);
            }
        }
    }

   
    for(let i = 0;i<routes.length;i++){
        let d = routes[i][0][0];
        let nextStart = start[start.length-1][0];
        let nextEnd = start[start.length-1][1];
        let valid = false;
        if(d === 'N'){
            for(let j = nextStart;j>=start[start.length-1][0] - Number(routes[i][2]);j--){
                if(j >= maxX || j < 0){
                    break;
                }
                if(park[j][nextEnd] === 'X'){
                    valid = true;
                    break;
                }
            }
            if(!valid){
                nextStart = start[start.length-1][0] - Number(routes[i][2]);
            }
            
            
            if(nextStart >= maxX || nextStart < 0 || nextEnd >= maxY || nextEnd < 0){
                valid = true;
                continue;
            }
            
        }
        else if(d === 'S'){
             for(let j = nextStart;j<=start[start.length-1][0] + Number(routes[i][2]);j++){
                if(j >= maxX || j < 0){
                    break;
                }
                if(park[j][nextEnd] === 'X'){
                    valid = true;
                    break;
                }
            }
            if(!valid){
                nextStart = start[start.length-1][0] + Number(routes[i][2]);
            }
            
            if(nextStart >= maxX || nextStart < 0 || nextEnd >= maxY || nextEnd < 0){
                valid = true;
                continue;
            }
        }
        else if(d === 'E'){
             for(let j = nextEnd;j<=start[start.length-1][1] + Number(routes[i][2]);j++){
                if(j >= maxY || j < 0){
                    break;
                }
                 if(park[nextStart][j] === 'X'){
                     console.log(nextStart,j);
                    valid = true;
                    break;
                }
            }
            if(!valid){
                nextEnd = start[start.length-1][1] + Number(routes[i][2]);
            }
            
             if(nextStart >= maxX || nextStart < 0 || nextEnd >= maxY || nextEnd < 0){
                valid = true;
                continue;
            }
            
        }
        else if(d === 'W'){
             for(let j = nextEnd;j>=start[start.length-1][1] - Number(routes[i][2]);j--){
                if(j >= maxY || j < 0){
                    break;
                }
                 if(park[nextStart][j] === 'X'){
                    valid = true;
                    break;
                }
            }
            if(!valid){
                nextEnd = start[start.length-1][1] - Number(routes[i][2]);
            }
            
             if(nextStart >= maxX || nextStart < 0 || nextEnd >= maxY || nextEnd < 0){
                valid = true;
                continue;
            }
          
        }
        if(!valid){
            start.push([nextStart,nextEnd]);
        }
        
    }
    console.log(start);
    
    return start[start.length-1];
}