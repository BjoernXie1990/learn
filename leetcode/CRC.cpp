#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string data("");
string divisor("");
void init();	//��ʼ������������������ʽ�ĳ����뱻����
bool check();	//�������Ķ����������Ƿ�Ϸ�
string slove();	//�õ�����

int main() {
	while (1) {
		init();

		bool ret = check();//�������ݸ�ʽ
		if (ret == false) {
			cout << "input error" << endl;
			continue;
		}

		// data + (n-1) 0
		int n = divisor.size();
		for (int i = 0; i < n - 1; i++) data += '0';

		string remainder = slove();
		cout << "remainder is " << remainder << endl;
		int p = data.size() - 1;
		for (int i = remainder.size() - 1; i >= 0; i--) data[p--] = remainder[i];
		cout << "code " << data << endl <<endl;
	}

	return 0;
}

void init() {
	data.clear();
	divisor.clear();
	cout << "Binary data ��";
	cin >> data;
	cout << "divisor : ";
	cin >> divisor;
}

bool check() {
	if (data.size() < divisor.size()) return false;
	if (data.front() == '0' || divisor.front() == '0') return false;
	for (auto& ch : data) if (ch != '0' && ch != '1') return false;
	for (auto& ch : divisor) if (ch != '0' && ch != '1') return false;
	return true;
}

void XOR(string& str) {
	string ans("");
	for (int i = 0; i < (int)divisor.size(); i++) ans += to_string(((str[i] - '0') ^ (divisor[i] - '0')));
	
	//�����ߵ� 0
	str.clear();
	int p = 0;
	while (p < (int)ans.size() && ans[p] != '1') p++;
	for (int i = p; i < (int)ans.size(); i++) str += ans[i];
}

string slove() {
	int n = data.size();
	int len = divisor.size();
	string tmp = data.substr(0, len - 1);

	for (int i = len - 1; i < n; i++) {
		tmp += data[i];
		if (tmp.size() != len) continue;
		XOR(tmp);	//���
	}
	
	return tmp.size() == 0 ? "0" : tmp;
}
