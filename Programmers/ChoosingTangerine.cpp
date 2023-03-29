/*
    경화는 과수원에서 귤을 수확했습니다. 
    경화는 수확한 귤 중 'k'개를 골라 상자 하나에 담아 판매하려고 합니다. 
    그런데 수확한 귤의 크기가 일정하지 않아 보기에 좋지 않다고 생각한 경화는 귤을 크기별로 분류했을 때 서로 다른 종류의 수를 최소화하고 싶습니다.

    예를 들어, 경화가 수확한 귤 8개의 크기가 [1, 3, 2, 5, 4, 5, 2, 3] 이라고 합시다. 
    경화가 귤 6개를 판매하고 싶다면, 크기가 1, 4인 귤을 제외한 여섯 개의 귤을 상자에 담으면, 
    귤의 크기의 종류가 2, 3, 5로 총 3가지가 되며 이때가 서로 다른 종류가 최소일 때입니다.

    경화가 한 상자에 담으려는 귤의 개수 k와 귤의 크기를 담은 배열 tangerine이 매개변수로 주어집니다. 
    경화가 귤 k개를 고를 때 크기가 서로 다른 종류의 수의 최솟값을 return 하도록 solution 함수를 작성해주세요.
*/


#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) //vec에 저장되어 있는 값의 형태는 <크기, 개수> 이므로 개수가 많은 순으로 정렬하기 위한 비교함수   
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {

    int answer = 0;

    map<int, int> nums; // 크기 별로 귤이 몇개가 있는지를 저장하기 위해 map 구조를 활용

    for (auto i : tangerine) { // nums[i == 귤의 크기] = 개수 형태로 저장
        nums[i] += 1;
    }

    vector<pair<int, int>> vec(nums.begin(), nums.end()); // sort 함수를 활용하기 위해 vec 형태로 변환 

    sort(vec.begin(), vec.end(), cmp); // 개수가 많은 순으로 vector를 정렬

    for (auto i : vec) { // Range based for 문을 활용하여 총 갯수 k에서 vector의 second 값 ( 해당 귤의 크기의 개수 )를 차감하기 위한 반복문

        k -= i.second;
        answer++; // 반복문이 한번 돌 때마다 한 종류의 귤이 초과됨

        if (k <= 0) break; // k의 개수 (귤의 개수)가 모두 소진되면 반복문을 종료

    }

    return answer;
}