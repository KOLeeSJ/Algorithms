/*
	문제 설명
	
	얀에서는 매년 달리기 경주가 열립니다. 해설진들은 선수들이 자기 바로 앞의 선수를 추월할 때 추월한 선수의 이름을 부릅니다. 
	예를 들어 1등부터 3등까지 "mumu", "soe", "poe" 선수들이 순서대로 달리고 있을 때, 해설진이 "soe"선수를 불렀다면 2등인 "soe" 선수가 1등인 "mumu" 선수를 추월했다는 것입니다. 즉 "soe" 선수가 1등, "mumu" 선수가 2등으로 바뀝니다.

	선수들의 이름이 1등부터 현재 등수 순서대로 담긴 문자열 배열 players와 해설진이 부른 이름을 담은 문자열 배열 callings가 매개변수로 주어질 때, 경주가 끝났을 때 선수들의 이름을 1등부터 등수 순서대로 배열에 담아 return 하는 solution 함수를 완성해주세요.

	제한사항
	
	5 ≤ players의 길이 ≤ 50,000
	players[i]는 i번째 선수의 이름을 의미합니다.
	players의 원소들은 알파벳 소문자로만 이루어져 있습니다.
	players에는 중복된 값이 들어가 있지 않습니다.
	3 ≤ players[i]의 길이 ≤ 10
	2 ≤ callings의 길이 ≤ 1,000,000
	callings는 players의 원소들로만 이루어져 있습니다.
	경주 진행중 1등인 선수의 이름은 불리지 않습니다.
	
	입출력 예
	
	players									callings						result
	["mumu", "soe", "poe", "kai", "mine"]	["kai", "kai", "mine", "mine"]	["mumu", "kai", "mine", "soe", "poe"]
*/

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const pair<string,int>& a, const pair<string,int>& b) {
    return a.second < b.second;
}

vector<string> solution(vector<string> players, vector<string> callings) {

	vector<string> answer; // 정답을 반환하는 vector 선언
	
	map<string, int> ranks; // players : ranking map 자료구조로 저장하기 위해 선언
	map<int, string> rranks; // ranking : players map 자료구조로 저장하기 위해 선언
	int rank = 1; 
	
	for (auto i : players) { // ranks map에 players : ranking 구조로 저장, rranks map에 ranking : players 구조로 저장 하기위한 반복문
		ranks[i] = rank;
		rranks[rank] = i;
		rank++;
	}
	
	for (auto i : callings) { // callings에 의해 불린 player의 등수와 한등수 앞의 player를 임시 변수에 저장하고 rank, rrank map을 순위에 맞춰 재정의하는 반복문
	
		int tmp = ranks[i] - 1;
		string strtmp = rranks[tmp];
		
		ranks[i] --;
		ranks[strtmp] ++;
        rranks[tmp] = i;
        rranks[tmp+1] = strtmp;
	
	}
    
    vector<pair<string,int>> vec(ranks.begin(), ranks.end()); // customized sort 함수를 사용하기 위해 map을 vector구조로 변환
    
    sort(vec.begin(), vec.end(), cmp); // vec.second에는 rank가 저장되어있고 1등 부터 마지막 순서 까지 정렬, 이 때 동일 값이 없기 떄문에 unstable sorting
   
    for (auto i : vec) { // ranking 순서대로 player의 이름을 정답 반환 벡터에 삽입
		answer.push_back(i.first); 
	}
    
    return answer;
}
