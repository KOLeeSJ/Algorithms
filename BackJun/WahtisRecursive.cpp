#include <iostream>
#include <string>

using namespace std;

void underbar(int num) {
	
	for (int i = 0; i < num; i++) {
		cout << "____";
	}
	return;
}

void solution(int depth, int num) {
	
	if (depth == 0) {

		underbar(num);
		cout << "\"����Լ��� ������?\"\n";
		underbar(num);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		underbar(num);
		cout << "��� �亯�Ͽ���.";
		return;
	}
	underbar(num);
	cout << "\"����Լ��� ������?\"\n";
	underbar(num);
	cout << "\"�� ����.�������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	underbar(num);
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	underbar(num);
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	solution(depth - 1, num + 1);
	cout << endl;
	underbar(num);
	cout << "��� �亯�Ͽ���.";
}

int main() {

	int depth;
	cin >> depth;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";

	solution(depth, 0);

	return 0;
}