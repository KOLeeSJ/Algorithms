/*
    ���� n, left, right�� �־����ϴ�. ���� ������ ���ļ� 1���� �迭�� ������� �մϴ�.

    n�� n�� ũ���� ����ִ� 2���� �迭�� ����ϴ�.
    i = 1, 2, 3, ..., n�� ���ؼ�, ���� ������ �ݺ��մϴ�.
    1�� 1������ i�� i�������� ���� ���� ��� �� ĭ�� ���� i�� ä��ϴ�.
    1��, 2��, ..., n���� �߶󳻾� ��� �̾���� ���ο� 1���� �迭�� ����ϴ�.
    ���ο� 1���� �迭�� arr�̶� �� ��, arr[left], arr[left+1], ..., arr[right]�� ����� �������� ����ϴ�.
    ���� n, left, right�� �Ű������� �־����ϴ�. �־��� ������� ������� 1���� �迭�� return �ϵ��� solution �Լ��� �ϼ����ּ���.


*/


#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 1 2 3 4 5 2 2 3 4 5 3 3 3 4 5 4 4 4 4 5 5 5 5 5 5
// n^2�� ���� �迭�� 1���� �����ϸ� ���� ����
// ��Ģ�� ���� ���ۺ��� �� ���ڿ� �ش��ϴ� ������ ��� ���� ���ڷ� ����
// ���� ���� ���ǿ� ���ؼ� �˰����� ����

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    long long tmp = left;

    while (1) {

        if (answer.size() == right - left + 1) break; // �迭�� ũ�Ⱑ Right - Left�̸� �ݺ����� ����

        if (tmp % n + 1 < tmp / n + 1) {
            answer.push_back(tmp / n + 1); 
        }

        else {
            answer.push_back(tmp % n + 1);
        }

        tmp++;

    }

    return answer;
}