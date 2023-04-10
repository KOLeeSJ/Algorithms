/*
    ���� ����
    �񳻸��������� ���ĵ� ������ �־��� ��, ���� ������ �����ϴ� �κ� ������ ã������ �մϴ�.

    ���� �������� ������ �� �ε����� ���ҿ� �� ������ ���Ҹ� ��� �����ϴ� �κ� �����̾�� �մϴ�.
    �κ� ������ ���� k�Դϴ�.
    ���� k�� �κ� ������ ���� ���� ��� ���̰� ª�� ������ ã���ϴ�.
    ���̰� ª�� ������ ���� ���� ��� ����(���� �ε����� ����)�� ������ ������ ã���ϴ�.
    ������ ��Ÿ���� ���� �迭 sequence�� �κ� ������ ���� ��Ÿ���� ���� k�� �Ű������� �־��� ��, �� ������ �����ϴ� �κ� ������ ���� �ε����� ������ �ε����� �迭�� ��� return �ϴ� solution �Լ��� �ϼ����ּ���. �̶� ������ �ε����� 0���� �����մϴ�.

    ���ѻ���
    5 �� sequence�� ���� �� 1,000,000
    1 �� sequence�� ���� �� 1,000
    sequence�� �񳻸��������� ���ĵǾ� �ֽ��ϴ�.
    5 �� k �� 1,000,000,000
    k�� �׻� sequence�� �κ� ������ ���� �� �ִ� ���Դϴ�.

*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// vector���� pair ���� ���� ���� ������� �����ϱ� ���� ���Լ�

bool cmp(const pair<int, int>& a, const pair<int, int>& b) { 
    return a.second - a.first < b.second - b.first;
}

vector<int> solution(vector<int> sequence, int k) {

    int sum = sequence.at(0);

    vector<pair<int, int>> tmp; // �κ� ������ start point�� end point�� �����ϱ� ���� �ӽ� ���� 

    int leftidx = 0;
    int rightidx = 0;

    while (1) {

        if (sum == k) tmp.push_back({ leftidx,rightidx }); // sum k�� �κ� ������ �������� �������� �ӽ� ���Ϳ� ����

        if (rightidx == sequence.size() && leftidx == sequence.size()) break; // �κ� ������ ����Ű�� Index�� ��� sequence �Լ��� ������ �κ��� ����ų �� ����

        if (sum <= k && rightidx < sequence.size()) { // sum�� k���� ���� �� right idx�� �ϳ� �ø�  
            rightidx++;

            if (rightidx < sequence.size()) {
                sum += sequence.at(rightidx); //right idx�� �ø� ���� �κ� ������ ������
            }

        }

        else {

            if (leftidx < sequence.size()) {
                sum -= sequence.at(leftidx); // �̿��� ���� left idx�� ����Ű�� ���� ���� ���ְ� left idx�� ��ĭ ���� �÷��� ���� �κ� �������� ���
            }

            leftidx++;
        }
        // ���� �����͸� �̿��Ͽ� �ð����⵵ O(N)
    }

    stable_sort(tmp.begin(), tmp.end(), cmp); // �κ� ������ �������� ������ �� (�Ÿ�)�� ���� ���� pair�� ó������ �� �� �ֵ��� sorting,
    //�� �� �Ÿ��� ������ �� ���� �Է� ���� �κ��� pair�� �ڷ� ���ĵ��� �ʵ��� stable sorting

    return { tmp[0].first,tmp[0].second };
}


int main(void) {

    vector<int> answer;

    answer = solution({ 2,2,2,2,2 }, 6);

    for (auto i : answer) {
        cout << i << ' ';
    }
}