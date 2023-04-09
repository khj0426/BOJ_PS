class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int> m;
        map<int,int> ::iterator iter;
        
        priority_queue<pair<int,int>> q;
        for(int i = 0;i<roads.size();i++){
            int second = roads[i][1];
            iter = m.find(second);
            if(iter == m.end()){
                m[second] = 1;
            }
            else if(iter != m.end()){
                m[second]++;
            }

            iter = m.find(roads[i][0]);
            if(iter == m.end()){
                m[roads[i][0]] = 1; 
            }
            else{
                m[roads[i][0]]++;
            }
        }
      
        map<int,int> val;
        for(iter = m.begin();iter != m.end();iter++){
           int first = iter->first; //번호
           int second = iter->second; //가중치
           q.push({second,first});
        }

        while(!q.empty()){
            int second = q.top().second;
            int first = q.top().first;
            val[second] = n;
            n--;
          
            q.pop();
        }

        long long sum = 0;
        for(int i = 0;i<roads.size();i++){
            long long tempSum = val[roads[i][0]] + val[roads[i][1]];
            sum += tempSum;
        }
        return sum;
    }
};