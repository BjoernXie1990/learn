#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

const string  fileName	=	"text.cpp";
vector<string> keyBuf	= { "int", "if", "else", "while", "do", "return","for" ,"include"};
vector<string> operBuf	= {"#" ,"<", ">", "!=", ">=", "<=", "==", ",", ";", "(", ")", "{", "}", "+", "-", "*", "/", "=" ,"++"};
vector<string> numBuf	= { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

int		idx;							// �ʷ����
string	buf;							// Դ����
int							operand;	// ������
int							tag;		// ��ʶ��
unordered_map<string, int>	keyWord;	// �ؼ���
unordered_map<string, int>	oper;		// ������

void init();			// ��ʼ��
void analyse();			// �ʷ�����
bool isSpace(char ch);	// �Ƿ�Ϊ�ո�tab���س�
void show(string first, int index);	// չʾ

int main() {
	ifstream fp(fileName);
	string rbuf;

	init();
	while (getline(fp, rbuf)) {
		buf += rbuf + "\n";
	}
	cout << "�ʷ�����������Դ�ļ�: \n\n";
	cout << "==================================================" << endl;
	cout << buf << endl;

	analyse();		// ����

	fp.close();
	return 0;
}

// ��ʼ��
void init() {
	for (auto& e : keyBuf) keyWord[e] = ++idx;
	for (auto& e : operBuf)	oper[e] = ++idx;
	operand = ++idx;
	tag = ++idx;
}

void show(string first, int index) {
	printf("[ %s -> ( %d , %s )] \n", first.c_str(), index, first.c_str());
}

// �Ƿ�Ϊ�ո�tab���س�
bool isSpace(char ch) {
	return ch == ' ' || ch == '\n' || ch == '\t';
}

// �Ƿ�Ϊ������
bool isOper(char ch) {
	string s(1,ch);
	//if (oper.find(s) != oper.end()) cout << "no find " << s << endl;
	return oper.find(s) != oper.end();
}

// �Ƿ�������
bool isNum(string& str) {
	for (auto& ch : str) if (ch < '0' || ch > '9') return false;
	return true;
}

// ��ʶ��,���� ����
void check(string& str) {
	if (str == "") return;

	// �Ƿ�Ϊ����
	bool ret = isNum(str);
	if (ret) {
		// number
		show(str, operand);
	}else {
		if (keyWord.find(str) == keyWord.end()) {
			// ��ʶ��
			show(str, tag);
			return;
		}
		show(str, keyWord[str]);
	}
}

// ����������
void checkOper(int& index) {
	int p = index;
	string t;
	for (; p < buf.size(); p++) {
		if (oper.find(t + buf[p]) == oper.end()) break;
		t += buf[p];
	}
	show(t, oper[t]);
	index = p - 1;
}

// �ʷ�����
void analyse() {
	string str;
	int n = buf.size();

	for (int i = 0; i < n; i++) {
		if (isSpace(buf[i])) {
			check(str);
			str = "";
		}else if (isOper(buf[i])) {
			check(str);
			checkOper(i);
			str = "";
		}else {
			str += buf[i];
		}

		//cout << str << endl;
	}
}