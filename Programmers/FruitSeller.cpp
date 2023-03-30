/*
    과일 장수가 사과 상자를 포장하고 있습니다. 
    사과는 상태에 따라 1점부터 k점까지의 점수로 분류하며, k점이 최상품의 사과이고 1점이 최하품의 사과입니다. 
    사과 한 상자의 가격은 다음과 같이 결정됩니다.

    한 상자에 사과를 m개씩 담아 포장합니다.
    상자에 담긴 사과 중 가장 낮은 점수가 p (1 ≤ p ≤ k)점인 경우, 사과 한 상자의 가격은 p * m 입니다.
    과일 장수가 가능한 많은 사과를 팔았을 때, 얻을 수 있는 최대 이익을 계산하고자 합니다.
    (사과는 상자 단위로만 판매하며, 남는 사과는 버립니다)

    예를 들어, k = 3, m = 4, 사과 7개의 점수가 [1, 2, 3, 1, 2, 3, 1]이라면, 다음과 같이 [2, 3, 2, 3]으로 구성된 사과 상자 1개를 만들어 판매하여 최대 이익을 얻을 수 있습니다.

    (최저 사과 점수) x (한 상자에 담긴 사과 개수) x (상자의 개수) = 2 x 4 x 1 = 8
    사과의 최대 점수 k, 한 상자에 들어가는 사과의 수 m, 사과들의 점수 score가 주어졌을 때, 과일 장수가 얻을 수 있는 최대 이익을 return하는 solution 함수를 완성해주세요.

    제한사항
    3 ≤ k ≤ 9
    3 ≤ m ≤ 10
    7 ≤ score의 길이 ≤ 1,000,000
    1 ≤ score[i] ≤ k
    이익이 발생하지 않는 경우에는 0을 return 해주세요.

    입출력 예
    k	m	score	                                result
    3	4	[1, 2, 3, 1, 2, 3, 1]	                8
    4	3	[4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2]	33

*/


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    if (score.size() < m) return 0; // 총 사과의 개수가 한 상자에 채워야하는 개수보다 작을 경우 이익이 발생하지 않음

    vector<vector<int>> boxes;
    vector<int> tmp;

    sort(score.begin(), score.end(), greater<>()); // 상자 안에 가장 작은 점수를 가진 사과가 점수에 반영되기 때문에 가장 큰 점수의 사과부터 순차적으로 담기 위해 내림차순 Sorting

    for (int i = 0; i <= score.size() - m; i += m) { // tmp에 사과를 m개씩 분배해서 담기위한 반복문 선언 (이때 마지막 상자에 들어가는 개수가 m개 보다 작을 경우 조건에 의해 탈출)

        tmp.clear();

        for (int j = i; j < i + m; j++) { // tmp에 사과를 m개씩 분배
            tmp.push_back(score.at(j));
        }

        boxes.push_back(tmp);
    }

    for (auto i : boxes) { // Range based for 문을 사용하여 모든 상자의 가장 작은 점수에 개수를 answer에 더해줌
        answer += i.at(i.size() - 1) * m;
    }

    return answer;
}