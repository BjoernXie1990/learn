#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string	str;				// ������ʽ
int		start = 0;			// ����ȡ���ʽλ��
int		idx = 0;			// ���
vector<string> st;			// ����ջ

void E();
void E1();
void F();
void T();
void T1();

void input() {
	cout << "������ʽ -> ";
	getline(cin, str);
	//str = "i*(i+i)";
	cout << endl;
}

void print() {
	cout << "\t " << idx << "\t ";
	string t("");
	for (auto& e : st) t += e;
	printf("%-10s\t", t.c_str());
	cout << str.substr(start) << "\t\t ";
}


void check() {
	printf("\t ���\t ����ջ \t �������ַ��� \t ���ʽ \n");
	
	st.push_back("#");
	st.push_back("E");
	print();
	idx++;
	cout << endl;

	E();

	if (st.back() != "#") cout << "���岻�Ϸ�" << endl;
	else cout << "����Ϸ� " << endl;
}

void E() {
	print();					//��ӡ��ǰ������Ϣ
	printf("E->TE'\n");			
	st.pop_back();
	st.push_back("E`");
	st.push_back("T");
	idx++;					
	T();
	E1();
}

void E1() {
	if (str[start] == '+') {
		print();
		printf("E'->+TE'\n");			//������ʽ
		st.pop_back();			
		st.push_back("E`");				
		st.push_back("T");		
		idx++;							
		start++;						
		T();
		E1();
	}
	else {
		print();						
		printf("E'->��\n");				
		st.pop_back();
		idx++;
	}
}

void F() {
	if (str[start] == 'i'){				//���������ַ�ƥ�䡮i��
		print();						
		printf("F->i\n");				
		st.pop_back();
		idx++;							
		start++;						
	}
	else if (str[start] == '('){		//���������ַ�ƥ�䡮(��
		print();						
		printf("F->(E)\n");				
		st.pop_back();
		st.push_back("E");
		idx++;							
		start++;						
		E();
		if (str[start] == ')'){			//���������ַ�ƥ�䡮)��
			start++;					
		}
		else{
			printf("û��')'ƥ�䣡\n");
			return;
		}
	}
	else{
		printf("error\n");
		return;
	}
}

void T() {
	print();					//��ӡ��ǰ������Ϣ
	printf("T->FT'\n");			//������ʽ
	st.pop_back();
	st.push_back("T`");
	st.push_back("F");
	idx++;						//��������+1
	F();
	T1();
}

void T1(){
	if (str[start] == '*'){		//���������ַ�ƥ�䡮*��
		print();						
		printf("T'->*FT'\n");			
		st.pop_back();
		st.push_back("T`");
		st.push_back("F");
		idx++;							
		start++;						
		F();
		T1();
	}
	else{
		print();						
		printf("T'->��\n");				
		st.pop_back();
		idx++;							
	}
}





