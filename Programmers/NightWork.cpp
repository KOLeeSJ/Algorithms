/*
    ���� ����
    ȸ��� Demi�� ������ �߱��� �ϴµ���, �߱��� �ϸ� �߱� �Ƿε��� ���Դϴ�. 
    �߱� �Ƿε��� �߱��� ������ �������� ���� ���� �۾����� �����Ͽ� ���� ���Դϴ�. 
    Demi�� N�ð� ���� �߱� �Ƿε��� �ּ�ȭ�ϵ��� ���� �̴ϴ�.Demi�� 1�ð� ���� �۾��� 1��ŭ�� ó���� �� �ִٰ� �� ��, 
    ��ٱ��� ���� N �ð��� �� �Ͽ� ���� �۾��� works�� ���� �߱� �Ƿε��� �ּ�ȭ�� ���� �����ϴ� �Լ� solution�� �ϼ����ּ���.

    ���� ����
    works�� ���� 1 �̻�, 20,000 ������ �迭�Դϴ�.
    works�� ���Ҵ� 50000 ������ �ڿ����Դϴ�.
    n�� 1,000,000 ������ �ڿ����Դϴ�.

    ����� ��
    works	n	result
    [4, 3, 3]	4	12
    [2, 1, 2]	1	6
    [1,1]	3	0
*/


#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) { // �ش� ������ ���;��� ������ ���� ������ �������� ��� ���� ����.
    long long answer = 0;
    priority_queue<long long> pq(works.begin(),works.end()); // �켱���� ť�� �̿��Ͽ� ������ �ذ��ϱ� ���� ����
    
    long long tmp = 0;

    while (n > 0) { // ������������ ���ĵ� �켱���� ť�� top ���� -1 �� ���ҽ�Ű�� ť ���� ������ ���� ����.
        tmp = pq.top();
        pq.pop();

        tmp -= 1;
        pq.push(tmp);
        
        n -= 1;
    }

    while(!pq.empty()) { // ť ���� ������ �����Ͽ� ����� ��ȯ
        tmp = pq.top();
        answer = tmp * tmp;
        pq.pop();
    }

    return answer;
}

int main() {

    solution(4, { 4,3,3 });

    return 0;
}