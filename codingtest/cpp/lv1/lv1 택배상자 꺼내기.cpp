#include <string>
#include <vector>

using namespace std;
void chg(int& lay, int& loc, int mok, int na, int w) {
    if (na == 0) {
        if (mok % 2 == 0) {
            lay = mok;
            loc = 1;
        }
        else {
            lay = mok;
            loc = w;
        }
    }
    else {
        if (mok % 2 == 0) {
            lay = mok + 1;
            loc = na;
        }
        else {
            lay = mok + 1;
            loc = w - (na - 1);
        }
    }
}
int solution(int n, int w, int num) {
    int answer = 0;
    int al, ar, ml, mr;
    int orgmok = n / w;
    int orgna = n % w;
    int mymok = num / w;
    int myna = num % w;
    chg(al, ar, orgmok, orgna, w);
    chg(ml, mr, mymok, myna, w);
    if (al % 2 == 0) {//Â¦¼öÃþÀº ¿À¸¥ÂÊºÎÅÍ ½ÃÀÛ
        if (ar > mr) {
            answer = al - ml;
        }
        else {
            answer = al - ml + 1;
        }
    }
    else {//¸ÇÀ§ È¦¼öÃþ
        if (ar >= mr) {
            answer = al - ml + 1;
        }
        else {
            answer = al - ml;
        }
    }
    return answer;
}