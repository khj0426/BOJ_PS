#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;



vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    //row세로 column 가로
    
    vector<vector<int>> matrix;
    int first = 1;
    for(int i = 0;i<rows;i++){
        vector<int> row;
        for(int j = 0;j<columns;j++){
            row.push_back(first);
            first++;
        }
        matrix.push_back(row);
    }
    
    
    
    for(int i = 0;i<queries.size();i++){
        int maxValue = 987654321;
        //n세로 m 가로
        // 2254 2,2 4,5
        //가로 4 세로 5
        
        //세로 가로
        
        //가로 5 세로 4
        int x2 = queries[i][3] - 1; //4
        int y2 = queries[i][2] - 1; //5
        int x1 = queries[i][1] - 1; //2
        int y1 = queries[i][0] - 1;// 2
        
        vector<int> topColumnChange;
        vector<int> topRightChange;
        vector<int> bottomRightChange;
        vector<int> bottomLeftChange;
        
        if(y1 + 1 >= 0 && y1 + 1 <= rows-1){
            topColumnChange.push_back(matrix[y1 + 1][x1]);
            
        }
        
        for(int i = x1;i<=x2-1;i++){
            topColumnChange.push_back(matrix[y1][i]);
            
        }
        
        if(x2 - 1 >= 0 && x2 - 1 <= columns){
            topRightChange.push_back(matrix[y1][x2-1]);
           
        }
        
        for(int i = y1;i<=y2-1;i++){
            topRightChange.push_back(matrix[i][x2]);
            
        }
        
        if(y2 - 1 >= 0 && y2 - 1 <= rows - 1){
            bottomRightChange.push_back(matrix[y2-1][x2]);
           
        }
        
        for(int i = x2;i>=x1 + 1;i--){
            bottomRightChange.push_back(matrix[y2][i]);
           
        }
        
        if(x1 + 1 >= 0 && x1 + 1 <= columns){
            bottomLeftChange.push_back(matrix[y2][x1+1]);
            
        }
        
        for(int i = y2;i>=y1+1;i--){
            bottomLeftChange.push_back(matrix[i][x1]);
            
        }
        
        int size_ = 0;
        for(int i = x1;i<=x2;i++){
            matrix[y1][i] = topColumnChange[size_];
            maxValue = min(maxValue,matrix[y1][i]);
            size_++;
        }
        
        size_ = 0;
        for(int i = y1;i<=y2;i++){
            matrix[i][x2] = topRightChange[size_];
            maxValue = min(maxValue,matrix[i][x2]);
            size_++;
        }
        
        size_ = 0;
        for(int i = x2;i>=x1;i--){
            matrix[y2][i] = bottomRightChange[size_];
            maxValue = min(maxValue,matrix[y2][i]);
            size_++;
        }
        
        size_ = 0;
        for(int i = y2;i>=y1;i--){
            matrix[i][x1] = bottomLeftChange[size_];
            maxValue = min(maxValue,matrix[i][x1]);
            size_++;
        }
        
        answer.push_back(maxValue);
        
        
        
       
        
        /*
        int size_ = 0;
        for(int i = x1;i<=x2;i++){
            //1489
            matrix[i][y1] = topColumnChange[size_];
            maxValue = min(maxValue,matrix[i][y1]);
        }
        
        size_ = 0;
        for(int i = y1;i<=y2;i++){
            matrix[x2][i] = topRightChange[size_];
            maxValue = min(maxValue,matrix[x2][i]);
        }
        
        size_ = 0;
        for(int i = x2;i>=x1;i--){
            matrix[i][y2] = bottomRightChange[size_];
            maxValue = min(maxValue,matrix[i][y2]);
        }
        size_ = 0;
        for(int i = y2;i>=y1;i--){
            matrix[x1][i] = bottomLeftChange[size_];
            maxValue = min(maxValue,matrix[x1][i]);
        }
        answer.push_back(maxValue);
        */
        
        
    }
    
    return answer;
}