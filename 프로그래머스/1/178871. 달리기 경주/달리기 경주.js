//mumu soe poe
//soe


function solution(players, callings) {
    var answer = [];
    //player-rank
    let map_players_ = new Map();
    //rank-player
    let map_rank_ = new Map();
    
    for(let i = 0;i<players.length;i++){
        map_players_.set(players[i],i);
        map_rank_.set(i,players[i]);
    }
    
    for(let i = 0;i<callings.length;i++){
        //2
        let ranking = map_players_.get(callings[i]);
        // soe
        let prev = map_rank_.get(ranking-1);
        
        // soe -> 2
        //kai -> 1
        
        map_players_.set(prev,ranking);
        map_rank_.set(ranking,prev);
        
        map_players_.set(callings[i],ranking-1);
        map_rank_.set(ranking-1,callings[i]);
    }
    
    answer = [...map_rank_].sort((a,b) => a[1] - b[1]).map((v) => v[1]);
    
    
    return answer;
}