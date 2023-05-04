function CalcuateTimeDiff(In,Out){
    const inTime = In.split(":");
    const outTime = Out.split(":");
    const diff = outTime[0] * 60 + outTime[1] * 1;
    const newDiff = inTime[0] * 60 + inTime[1] * 1;
    return diff - newDiff;
}

function getPay(fees,time){
    
    if(time <= fees[0]){
        return fees[1];
    }
    return fees[1] + Math.ceil((time-fees[0]) / fees[2]) * fees[3]
}

function solution(fees, records) {
    var answer = [];
    let sum = new Map();
    let inrecord = new Map();
    let sumofTime = new Map();

    records = records.map(v => v.split(' ')).sort((a,b) => a[1]-b[1]);

    
    records.forEach((record) => {
    
        if(record[2] === "IN"){
            inrecord.set(record[1],record[0]);
        } 
        else{
            const getrecord = inrecord.get(record[1]);
            const prevpay = sum.get(record[1]);

            if(typeof prevpay === 'undefined'){
                const diff = CalcuateTimeDiff(getrecord,record[0]);
                sum.set(record[1],getPay(fees,diff));
                sumofTime.set(record[1],diff);
            }
            
            else{
                //2259
                //2300
                //1
                let prevtime = sumofTime.get(record[1]);
                let newdiff = CalcuateTimeDiff(getrecord,record[0]);
                
                newdiff += prevtime;
                const newpay = getPay(fees,newdiff);
                sum.set(record[1],newpay);
                sumofTime.set(record[1],newdiff);
            }
            inrecord.delete(record[1]);
            
        }
        
    });
    
    Array.from(inrecord).forEach((record) => {
        const prevpay = sum.get(record[0]);
        console.log(record[0],record[1]);
        if(typeof prevpay === 'undefined'){
            const diff = CalcuateTimeDiff(record[1],"23:59");
            sum.set(record[0],getPay(fees,diff));
        }
        else{
            let prev = sumofTime.get(record[0]);
            let newdiff = CalcuateTimeDiff(record[1],"23:59");
            newdiff += prev;

            let diff = getPay(fees,newdiff);
            sum.set(record[0],diff);
            
        }
        inrecord.delete(record[0]);
    });

   const newSumarr = [...sum];
   newSumarr.sort((a,b)=>{
    return parseInt(a[0]) - parseInt(b[0]);
   })


   newSumarr.forEach((arr) => {
    answer.push(arr[1]);
   })


    return answer;
}
    
