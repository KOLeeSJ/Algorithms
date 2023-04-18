/*

	문제 설명
	트럭 여러 대가 강을 가로지르는 일차선 다리를 정해진 순으로 건너려 합니다. 
	모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 알아내야 합니다. 
	다리에는 트럭이 최대 bridge_length대 올라갈 수 있으며, 다리는 weight 이하까지의 무게를 견딜 수 있습니다. 
	단, 다리에 완전히 오르지 않은 트럭의 무게는 무시합니다.

	예를 들어, 트럭 2대가 올라갈 수 있고 무게를 10kg까지 견디는 다리가 있습니다. 
	무게가 [7, 4, 5, 6]kg인 트럭이 순서대로 최단 시간 안에 다리를 건너려면 다음과 같이 건너야 합니다.

	경과 시간	다리를 지난 트럭	다리를 건너는 트럭	대기 트럭
	0	[]	[]	[7,4,5,6]
	1~2	[]	[7]	[4,5,6]
	3	[7]	[4]	[5,6]
	4	[7]	[4,5]	[6]
	5	[7,4]	[5]	[6]
	6~7	[7,4,5]	[6]	[]
	8	[7,4,5,6]	[]	[]
	따라서, 모든 트럭이 다리를 지나려면 최소 8초가 걸립니다.

	solution 함수의 매개변수로 다리에 올라갈 수 있는 트럭 수 bridge_length, 다리가 견딜 수 있는 무게 weight, 트럭 별 무게 truck_weights가 주어집니다. 
	이때 모든 트럭이 다리를 건너려면 최소 몇 초가 걸리는지 return 하도록 solution 함수를 완성하세요.

*/

#include <string>
#include <vector>
#include <queue> // 큐 자료구조를 이용하여 문제를 해결하기 위해 헤더파일을 선언

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) { 
    int answer = 0;
    int total_weight = 0; // 다리 위의 총 무게를 저장하기 위한 변수
    int tmp = 0; // 무한 반복문을 종료시키기 위해 임시 변수의 값을 선언
    queue<int> bridge;

    while (1) {

        if (tmp == truck_weights.size()) { // 임시 변수의 값이 truck_weights 벡터의 크기와 같을 경우 == 모든 트럭이 다리 위에 올라온 경우이므로 종료
            break;
        }

        if (bridge.size() == bridge_length) { // 큐의 크기가 bridge_length와 같다는 것은 가장 처음으로 들어왔던 트럭이 다리를 건넌 경우이므로 큐에서 제거 
            total_weight -= bridge.front(); // 큐에서 제거 되므로 총 무게에서 제외
            bridge.pop();
        }

        if (total_weight + truck_weights.at(tmp) <= weight) { // 다리 위의 무게와 다음 차례에 올라올 트럭의 크기가 다리가 견딜 수 있는 총 무게보다 작을 경우 큐에 트럭을 올림
            total_weight += truck_weights.at(tmp);
            bridge.push(truck_weights.at(tmp));
            tmp++;
        }
        else {
            bridge.push(0); // 다리에 트럭이 못 올라갈 경우에는 0을 push함으로 총량을 일정하게 유지
        }

        answer++; // 반복문이 한번 수행될 때마다 한칸씩 전진

    }

    return answer + bridge_length; // 마지막 트럭이 올라 왔을 때 종료되므로 answer에 다리의 길이를 더한 값을 반환
}