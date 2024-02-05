function solution(cards1, cards2, goal) {
   
    
    let card1 = [];
    let card2 = [];
    let answer = [];
    
    goal.map((eachgol,index) => {
        let findCard1 = cards1.indexOf(eachgol);
        let findCard2 = cards2.indexOf(eachgol);
        console.log(card1,card2);
        if(findCard1 !== -1 && Math.max(...card1) < findCard1){
            answer.push(eachgol);
            cards1[findCard1] = '';
            card1.push(findCard1);
            return;
        }
        else if(findCard2 !== -1 && Math.max(...card2) < findCard2){
            console.log(findCard2,eachgol);
            answer.push(eachgol);
            cards2[findCard2] = '';
            card2.push(findCard2);
            return;
        }
        else{
            return;
        }
    })
    
    let a = (answer.length === goal.length ? 'Yes' : 'No')
    
    for(let i = 0;i<cards1.length;i++){
        if(i !== 0 && i !== cards1.length && cards1[i]!== '' && cards1[i-1] === '' && cards1[i+1] === ''){
            a = 'No';
        }
    }
    
    
    for(let i = 0;i<cards2.length;i++){
        if(i !== 0 && i !== cards2.length && cards2[i] !== '' && cards2[i-1] === '' && cards2[i+1] === ''){
            a = 'No';
        }
    }
    
    console.log(answer,card1,card2,cards1,cards2)
    
    return a;
}
