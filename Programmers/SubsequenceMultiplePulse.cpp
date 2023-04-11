/*
	문제 설명
	어떤 수열의 연속 부분 수열에 같은 길이의 펄스 수열을 각 원소끼리 곱하여 연속 펄스 부분 수열을 만들려 합니다. 펄스 수열이란 [1, -1, 1, -1 …] 또는 [-1, 1, -1, 1 …] 과 같이 1 또는 -1로 시작하면서 1과 -1이 번갈아 나오는 수열입니다.
	예를 들어 수열 [2, 3, -6, 1, 3, -1, 2, 4]의 연속 부분 수열 [3, -6, 1]에 펄스 수열 [1, -1, 1]을 곱하면 연속 펄스 부분수열은 [3, 6, 1]이 됩니다. 
	또 다른 예시로 연속 부분 수열 [3, -1, 2, 4]에 펄스 수열 [-1, 1, -1, 1]을 곱하면 연속 펄스 부분수열은 [-3, -1, -2, 4]이 됩니다.
	정수 수열 sequence가 매개변수로 주어질 때, 연속 펄스 부분 수열의 합 중 가장 큰 것을 return 하도록 solution 함수를 완성해주세요.

	제한 사항
	1 ≤ sequence의 길이 ≤ 500,000
	-100,000 ≤ sequence의 원소 ≤ 100,000
	sequence의 원소는 정수입니다.

*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm> // *max_element, *min_element 를 사용하기 위한 헤더파일 선언

using namespace std;

long long solution(vector<int> sequence) {

    vector<long long> presum1 = {0}; // sequence벡터에 -1부터 시작하는 펄스 수열이 곱해진 누적합 벡터를 구하기 위해 선언
    vector<long long> presum2 = {0}; // sequence벡터에 1부터 시작하는 펄스 수열이 곱해진 누적합 벡터를 구하기 위해 선언
    
    int pulse = -1;
    long long tmp = 0;
	  
    for (auto i : sequence) { // 반복문을 통해 sequence벡터에 -1부터 시작하는 펄스 수열이 곱해진 누적합 Vector 생성 
        tmp += i * pulse;
        presum1.push_back(tmp);
		pulse *= -1;
    }
	
	pulse = 1;
	tmp = 0;
	
	for (auto i : sequence) { // 반복문을 통해 sequence벡터에 1부터 시작하는 펄스 수열이 곱해진 누적합 Vector 생성 
        tmp += i * pulse;
        presum2.push_back(tmp);
		pulse *= -1;
    }
	
    long long max_val1 = *max_element(presum1.begin(), presum1.end());
    auto idx1 = max_element(presum1.begin(), presum1.end());
    long long min_val1 = *min_element(presum1.begin(), idx1);
	
	long long max_val2 = *max_element(presum2.begin(), presum2.end());
    auto idx2 = max_element(presum2.begin(), presum2.end());
    long long min_val2 = *min_element(presum2.begin(), idx2);
	
	// 누적합이 element와 해당 element가 위치한 index 이전의 값 중 가장 작은 최솟 값을 구하여 max_val, min_val에 저장
	
    return max(max_val1 - min_val1, max_val2 - min_val2); // 두 종류의 presum 벡터에서 더 큰 값을 반환
}
