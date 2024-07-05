//1번 - R,T
//2번 - C,F
//3번 - J,M
//4번 - A,N

//RFMN... 16가지

//N개의 질문과 7개의 선택지

//매우동의 - 매우 비동의 ->3점
//동의 - 비동의 -> 2점
//약간 동의 - 약간 비동의 -> 1점
//모르겠음 -> 점수 X

//점수가 같으면 사전 순으로 빠른 순
//RT -> 비동의 시 R, 동의 시 T
//TR -> 비동의 시 T, 동의 시 R

//AN -> 비동의 시 A, 동의 시 N

/*
    1-매우 비동의
    2-비동의
    3-약간 비동의
    4-모르겠음
    5-약간 동의
    6-동의
    7-매우 동의
*/

/*
    매우동의나 매우 비동의 선택 시 3점
    동의나 비동의 선택 시 2점
    약간 동의나 약간 비동의를 선택 시 1점
    모르겠음 선택 시 X
*/
//항목 당 점수 매핑
const mappingChoiceToScore = new Map([
    ["1",3],
    ["7",3],
    ["2",2],
    ["6",2],
    ["3",1],
    ["5",1],
    ["4",0]
]);

function solution(survey, choices) {
    var answer = '';
    const score = {
        "R":0,
        "T":0,
        "C":0,
        "F":0,
        "J":0,
        "M":0,
        "A":0,
        "N":0
    };
    
    for(let i = 0;i<survey.length;i++){
        //비동의 묶음
        if(choices[i] === 1 || choices[i] === 3 || choices[i] === 2){
            let getScore = mappingChoiceToScore.get(choices[i] + "");
            let selected = survey[i][0];
            score[selected] = score[selected] + Number(getScore);
        }
        else if(choices[i] === 5 || choices[i] === 6 || choices[i] === 7){
            let getScore = mappingChoiceToScore.get(choices[i] + "");
            let selected = survey[i][1];
            score[selected] = score[selected] + Number(getScore);
        }
    }
    
    console.log(score);
    
    let arr = Object.entries(score)
    for(let i = 0;i<arr.length;i=i+2){
        if(arr[i][1] < arr[i+1][1]){
            answer += arr[i+1][0];
        }
        else if(arr[i][1] > arr[i+1][1]){
            answer += arr[i][0];
        }
        else if(arr[i][1] === arr[i+1][1]){
            answer += arr[i][0];
        }
    }
    return answer;
}