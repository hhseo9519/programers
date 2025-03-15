#include<iostream>
#include<vector>
#include<string>
using namespace std;// 이름공간을 사용해야 string을 그냥 사용할 수 있다?

string solution(const string video_len, const string pos, const string op_start,
	const string op_end, vector<string>commands, size_t commands_len) {
	string answer;
	/*string의 형태로 분과 초를 주기 때문에 모두 초단위로 바꿔서 사용할 수 밖에 없다*/
	int Pos = stoi(pos.substr(0, 2)) * 60 + stoi(pos.substr(3, 2));
	int Op_start = stoi(video_len.substr(0, 2)) * 60 + stoi(video_len.substr(3, 2));
	int Op_end = stoi(op_end.substr(0, 2)) * 60 + stoi(op_end.substr(3, 2));
	int Video_len = stoi(video_len.substr(0, 2)) * 60 + stoi(video_len.substr(3, 2));

	if (Op_start <= Pos && Pos <= Op_end) {
		Pos = Op_end;
	}
	
	for (string com : commands) {
		if (com.compare("prev") == 0) {
			if (Pos - 10 > 0) {
				Pos -= 10;
			}
			else {
				Pos = 0;
			}
		}
		else if (com.compare("next") == 0) {
			if (Pos + 10 < Video_len) {
				Pos += 10;
			}
			else {
				Pos = Video_len;
			}
		}
		if (Op_start <= Pos && Pos <= Op_end) {
			Pos = Op_end;
		}

	}
	answer = (Pos / 60 < 10 ? "0" + to_string(Pos / 60) : to_string(Pos / 60))
		+ ":" + (Pos % 60 < 10 ? "0" + to_string(Pos % 60) : to_string(Pos % 60));




	return answer;
}