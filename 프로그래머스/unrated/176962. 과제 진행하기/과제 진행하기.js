function total(plan){
    const hour = plan[1].substr(0, 2);
    const minute = plan[1].substr(3, plan[1].length);
    return parseInt(hour) * 60 + parseInt(minute);
}

function solution(plans) {
    var answer = [];
    let newplans = [];
    let st = [];
    
    plans.forEach((plan, index) => {
        newplans.push(plan);
        newplans[newplans.length-1][1] = total(plan);
     
    });
    
    newplans.sort((a, b) => {
        return a[1] - b[1];
    });
    
    
    for(let i = 0;i<newplans.length;i++){
        if(i == newplans.length-1){
            answer.push(newplans[i][0]);
            break;
        }

        //과제가 끝나는 경우 남은 과제 수행 //
        
        if(newplans[i][1] * 1 + newplans[i][2] * 1 <= newplans[i+1][1] * 1){
            answer.push(newplans[i][0]);
            let timeDiff = (newplans[i+1][1] * 1) - (newplans[i][1] * 1 + newplans[i][2] * 1);
            
            while(st.length > 0 && timeDiff > 0){
                const prevDiff = st[st.length-1][2];
                if(timeDiff >= prevDiff){
                    answer.push(st[st.length-1][0]);
                     
                    st.pop();
                }
                else{
                    st[st.length-1][2] = Math.abs(prevDiff - timeDiff);
                   
                }
                timeDiff -= prevDiff;  
            }
           
            
        }
        else{
            let timeDiff = Math.abs((newplans[i+1][1] * 1) - (newplans[i][1] * 1));
            newplans[i][2] -= timeDiff;
            st.push(newplans[i]);
        }
    }
    
    
    
    for(let i = st.length-1;i>=0;i--){
        answer.push(st[i][0]);
    }
    
    
    
    return answer;
}