#include <string>
#include <vector>
#include<map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    int tyear = 0;
    int tmonth = 0;
    int tday = 0;
    int tym = 0;
    tyear=stoi(today.substr(0, 4));
    tmonth = stoi(today.substr(5, 2));
    tym = tyear * 12 + tmonth;
    tday = stoi(today.substr(8, 2));
    string mt;
    map<string, int> maps;
    for (int i = 0; i < terms.size(); i++) {
        string myterm = terms[i];
        //위 부분은 범위기반 for문으로 바꾸는게 낫겠다.
        //for (string temm : terms){...}
        
        
        int mm = 0;
        mt = myterm.substr(0, 1);
        mm = stoi(myterm.substr(2));
        maps.insert(make_pair(mt, mm));
        
    }//terms 를 모두 적어놓음
    //기한 월하고 달로 확인하고 그 다음에 같으면 일 로 확인
    vector<int> privacy;
    vector<string>privacyterm;
    string pt;
    for (int i = 0; i < privacies.size(); i++) {
        int k = 0;
        
        k += stoi(privacies[i].substr(0, 4)) * 12;
        k += stoi(privacies[i].substr(5, 2));
        pt = privacies[i].substr(11, 1);
        privacy.push_back(k);
        privacyterm.push_back(pt);

    }//모두 달 수로 해서 바꿔 놓음
    //비교문을 작성하면 됌
    map<string, int>::iterator iter;
    for (int i = 0; i < privacy.size(); i++) {
        
        if (privacy[i] > tym + maps[privacyterm[i]]) {
            answer.push_back(i+1);
        }
        else if (privacy[i] == tym + maps[privacyterm[i]]) {
            if (stoi(privacies[i].substr(8, 2)) > tday) {
                answer.push_back(i+1);
            }
        }
        else {

        }
    }



    return answer;
}

////
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    int tyear = stoi(today.substr(0, 4));
    int tmonth = stoi(today.substr(5, 2));
    int tday = stoi(today.substr(8, 2));
    int tym = tyear * 12 + tmonth;

    map<string, int> maps;
    for (const string& term : terms) {
        int space_idx = term.find(' ');
        string term_key = term.substr(0, space_idx);
        int term_value = stoi(term.substr(space_idx + 1));
        maps[term_key] = term_value;
    }

    for (int i = 0; i < privacies.size(); i++) {
        int pyear = stoi(privacies[i].substr(0, 4));
        int pmonth = stoi(privacies[i].substr(5, 2));
        int pday = stoi(privacies[i].substr(8, 2));
        string term_key = privacies[i].substr(11, 1);

        int expiry_month = pyear * 12 + pmonth + maps[term_key];

        if (expiry_month < tym || (expiry_month == tym && pday <= tday)) {
            answer.push_back(i + 1); // 1-based index로 반환
        }
    }

    return answer;
}
