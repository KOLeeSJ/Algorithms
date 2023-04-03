/*
    �������� ���� �߾￡ ���� �ִ� ��� �������� �߾� ������ �ű���� �մϴ�. 
    ���� �ӿ� ������ �ι��� �׸��� ������ ��� �ջ��� ���� �ش� ������ �߾� ������ �˴ϴ�. 
    ���� ��� ���� �� �ι��� �̸��� ["may", "kein", "kain"]�̰� �� �ι��� �׸��� ������ [5��, 10��, 1��]�� �� �ش� ������ �߾� ������ 16(5 + 10 + 1)���� �˴ϴ�. 
    �ٸ� ���� �� �ι��� �̸��� ["kali", "mari", "don", "tony"]�̰� ["kali", "mari", "don"]�� �׸��� ������ ���� [11��, 1��, 55��]]�̰�, "tony"�� �׸��� ������ ���� ��, 
    �� ������ �߾� ������ 3���� �׸��� ������ ���� 67(11 + 1 + 55)���Դϴ�.

    �׸����ϴ� ����� �̸��� ���� ���ڿ� �迭 name,
    �� ����� �׸��� ������ ���� ���� �迭 yearning, �� ������ ���� �ι��� �̸��� ���� ������ ���ڿ� �迭 photo�� �Ű������� �־��� ��, 
    �������� �߾� ������ photo�� �־��� ������� �迭�� ��� return�ϴ� solution �Լ��� �ϼ����ּ���.

    ���ѻ���
    3 �� name�� ���� = yearning�� ���̡� 100
    3 �� name�� ������ ���� �� 7
    name�� ���ҵ��� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
    name���� �ߺ��� ���� ���� �ʽ��ϴ�.
    1 �� yearning[i] �� 100
    yearning[i]�� i��° ����� �׸��� �����Դϴ�.
    3 �� photo�� ���� �� 100
    1 �� photo[i]�� ���� �� 100
    3 �� photo[i]�� ����(���ڿ�)�� ���� �� 7
    photo[i]�� ���ҵ��� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.
    photo[i]�� ���ҵ��� �ߺ��� ���� ���� �ʽ��ϴ�.
*/


// ���ѻ����� ���� name <= 100, photo <=100, photo[i] <= 7, �ߺ��� X 
// 3�� for���� ������� �� �ִ� ���귮�� 70000 �� ������ ���귮�� ����.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer; // ������ ��ȯ���ֱ� ���� vector ����

    for (int i = 0; i < photo.size(); i++) { // photo�� ��� �࿡ �����ϱ� ���� �ݺ��� ���� 

        int tmp = 0;

        for (int j = 0; j < name.size(); j++) { // name vector�� ��� ���ڿ� ����

            for (int k = 0; k < photo.at(i).size(); k++) {// name vector�� ���ڿ� photo�� ��� ���� ���ϱ� ���� �ݺ��� ����

                if (name.at(j) == photo.at(i).at(k)) { // ��ġ�� ��� �߾� ������ ����
                    tmp += yearning.at(j);
                }

            }

        }

        answer.push_back(tmp); // answer vector�� �����Ͽ� ����

    }

    return answer;
}

int main() {

    vector<int> answer = solution({ "may", "kein", "kain", "radi" }, { 5, 10, 1, 3 }, { {"may", "kein", "kain", "radi"}, { "may", "kein", "brin", "deny"}, { "kon", "kain", "may", "coni"} });

    for (auto i : answer) {
        cout << i << ' ';
    }

}