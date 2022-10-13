//프로그래머스 비밀지도
//toString(x) ->x진수로 바꾸기

function solution(n, arr1, arr2) {
    var answer = [];
    for(var i = 0;i<n;i++){
       arr1[i] = arr1[i].toString(2); //toString(진수) toString(2)->2진수
        if(arr1[i].length < n){
            var temp = '';
           for(var j = 0;j<n-arr1[i].length;j++){ //앞에서부터 0으로 채우는 과정
               temp = temp + '0';
           }
            arr1[i] = temp + arr1[i]
        }
        answer[i] = arr1[i]; //answer에 arr1저장
    }
    for(var i = 0;i<n;i++){
        arr2[i] = arr2[i].toString(2); //arr2도 2진수로 바꾸고
        if(arr2[i].length < n){
            var temp = '';
            for(var j = 0;j<n-arr2[i].length;j++){ //앞에서부터 0으로 채우기
                temp = temp + '0';
            }
            arr2[i] = temp + arr2[i]; 
        }
    }
    
   for(var i = 0;i<n;i++){ //answer와 arr2 합치는 과정
       var temp = '';
       for(var j = 0;j<answer[i].length;j++){ 
           if(answer[i][j] == '1' || arr2[i][j] == '1'){
               temp = temp + '#';
           }
           else if(answer[i][j] == '0' && arr2[i][j] == '0'){
               temp = temp + ' ';
           }
       }
       answer[i] = temp;
       console.log(answer[i]);
   }
    
   
    return answer;
}