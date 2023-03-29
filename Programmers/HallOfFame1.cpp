/*

	"명예의 전당"이라는 TV 프로그램에서는 매일 1명의 가수가 노래를 부르고, 시청자들의 문자 투표수로 가수에게 점수를 부여합니다. 
	매일 출연한 가수의 점수가 지금까지 출연 가수들의 점수 중 상위 k번째 이내이면 해당 가수의 점수를 명예의 전당이라는 목록에 올려 기념합니다. 
	즉 프로그램 시작 이후 초기에 k일까지는 모든 출연 가수의 점수가 명예의 전당에 오르게 됩니다. 
	k일 다음부터는 출연 가수의 점수가 기존의 명예의 전당 목록의 k번째 순위의 가수 점수보다 더 높으면, 
	출연 가수의 점수가 명예의 전당에 오르게 되고 기존의 k번째 순위의 점수는 명예의 전당에서 내려오게 됩니다.

	이 프로그램에서는 매일 "명예의 전당"의 최하위 점수를 발표합니다. 
	예를 들어, k = 3이고, 7일 동안 진행된 가수의 점수가 [10, 100, 20, 150, 1, 100, 200]이라면, 
	명예의 전당에서 발표된 점수는 아래의 그림과 같이 [10, 10, 10, 20, 20, 100, 100]입니다.

*/


#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(int k, vector<int> score) {
	vector<int> answer;
	priority_queue<int, vector<int>, greater<int>> pq; // 매번 값이 추가 될 때마다 Sort 작업을 제외하여 가장 큰 수가 마지막에 배치 될 수 있도록 Priority Queue를 이용
	int i = 0; // 반복문의 횟 수를 세기 위한 임시 변수

	while (1) {

		if (i == score.size()) break; // i가 score.size()가 되었다는 의미는 score를 모두 탐색 하여 비교 하였다는 의미이기 때문에 반복문을 탈출

		pq.push(score.at(i)); // score의 값들을 pq에 삽입

		if (pq.size() > k) { // k번째 순위는 명예의 전당에서 제외되기 때문에 pq의 size가 k가 되는 경우 가장 작은 값을 pop
			pq.pop();
		}

		i++; // score의 다음 인자에 접근 하기위해 1을 더함

		answer.push_back(pq.top()); // 명예의 전당에서 가장 작은 값 (pq의 가장 첫 값)을 answer에 삽입.

	}

	return answer;
}