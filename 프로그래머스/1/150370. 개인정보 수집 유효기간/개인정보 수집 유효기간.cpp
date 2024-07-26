#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <map>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> m;

    for (int i = 0; i < terms.size(); i++) {
        char keys = terms[i][0];
        string values = "";
        for(int j = 0;j<terms[i].size();j++){
            if(terms[i][j] >= '0' && terms[i][j] <= '9'){
                values += terms[i][j];
            }
        }
        int valueofterm = stoi(values);
        m[keys] = valueofterm;
    }

    int year = -1;
    int month = -1;
    int day = -1;
    string str = "";

    for (int i = 0; i < today.size(); i++) {
        if (today[i] == '.' && year == -1) {
            year = stoi(str);
            str = "";
        } else if (today[i] == '.' && year != -1 && month == -1) {
            month = stoi(str);
            str = "";
        }
        if (today[i] != '.') {
            str += today[i];
        }
    }
    day = stoi(str);
    if(month >= 12){
        year = year + (month / 12);
    }
    month = month % 12;
    int curValue = (year * 365 * 12) + (month * 28) + day;

    for (int i = 0; i < privacies.size(); i++) {
        int sizeofPrivacie = privacies[i].size();
        char lastEl = privacies[i][sizeofPrivacie - 1];
        int values = m[lastEl];

        year = -1;
        month = -1;
        day = -1;
        str = "";

        for (int j = 0; j < privacies[i].size() - 1; j++) {
            if (privacies[i][j] == '.' && year == -1) {
                year = stoi(str);
                str = "";
            } else if (privacies[i][j] == '.' && year != -1 && month == -1) {
                month = stoi(str);
                str = "";
            }
            if (privacies[i][j] != '.' && privacies[i][j] != ' ') {
                str += privacies[i][j];
            }
        }
        day = stoi(str);
        
        
        int currentPrivacieValue = ((year + (month + values)/12)  *  365) * 12 + (((month+values) % 12)* 28) + day;
        if (currentPrivacieValue <= curValue) {
            answer.push_back(i + 1);
        }
        //하.........................................................................
    }
   
    return answer;
}
