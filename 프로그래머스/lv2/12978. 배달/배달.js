function solution(N, road, K) {
    var answer = 0;
    var arr = new Array(N);
    for(var i = 0;i<arr.length;i++){
        arr[i] = new Array(N);
    }
    
    for(var i = 0;i<N;i++){
        for(var j = 0;j<N;j++){      
                if(i == j){
                    arr[i][j] = 0;
                    continue;
                }
                
                arr[i][j] = Number.MAX_SAFE_INTEGER;       
        }
    }
    
    var size = road.length;
    
    for(var i = 0;i<size;i++){
        var a = road[i][0];
        var b = road[i][1];
        var c = road[i][2];
       
        arr[a-1][b-1] = Math.min(arr[a-1][b-1],c);
        arr[b-1][a-1] = Math.min(arr[b-1][a-1],c);
        
    }
    
    

    for(var k = 0;k<N;k++){
        for(var i = 0;i<N;i++){
            for(var j = 0;j<N;j++){
                arr[i][j] = Math.min(arr[i][j],arr[i][k] + arr[k][j]);
            }
        }
    }
   
    for(var i = 0;i<N;i++){
        if(arr[0][i] <= K){
            answer++;
        }
    }
    

    return answer;
}