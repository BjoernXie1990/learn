#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n,a,b;
string s,res;
string id;
int nums[256];

void slove() {
    res = "";
    vector<int> arr;
    for(int i = s.size() - 1; i >= 0; i--) arr.push_back(nums[s[i]]);
    while(arr.size()) {
        int t = 0; // ��λ
        for(int i = s.size() - 1; i >= 0; i--) {
            arr[i] += t * a;
            t = arr[i] % b;
            arr[i] /= b;
        }
        res.push_back(id[t]);
        while(arr.size() && arr.back() == 0) arr.pop_back();
    }
    reverse(res.begin(),res.end());
}

int main() {
    cin >> n;
    for(char i = '0'; i <= '9'; i++) {
        id += i;
        nums[i] = i - '0';
    }
    for(char i = 'A'; i <= 'Z'; i++)  {
        id += i;
        nums[i] = i - 'A' + 10;
    }
    for(char i = 'a'; i <= 'z'; i++)  {
        id += i;
        nums[i] = i - 'a' + 36;
    }
    while(n --) {
        cin >> a >> b >> s;
        slove();
        cout << a << " " << s << endl;
        cout << b << " " << res << endl;
        puts("");
    }
}

��дһ�����򣬿���ʵ�ֽ�һ��������һ������ת��Ϊ��һ�����ơ�

������62����ͬ��λ{0-9,A-Z,a-z}��

�����ʽ
��һ������һ�������������������������

������ÿһ�ж������������֣�������������ƣ�ʮ���Ʊ�ʾ����Ȼ����������ƣ�ʮ���Ʊ�ʾ�����������������Ʊ�ʾ���������֣�����֮���ÿո������

������ƺ�������ƶ���2��62�ķ�Χ֮�ڡ�

����ʮ�����£�A = 10��B = 11������Z = 35��a = 36��b = 37������z = 61 (0-9��Ȼ��ʾ0-9)��

�����ʽ
����ÿһ�����ת�������������������й��ɡ�

��һ�а����������֣�������������ƣ�ʮ���Ʊ�ʾ����Ȼ������������Ʊ�ʾ���������֡�

�ڶ��а����������֣�������������ƣ�ʮ���Ʊ�ʾ����Ȼ������������Ʊ�ʾ���������֡�

������Ϊ�հ��С�

ͬһ���������ÿո������

����������
8
62 2 abcdefghiz
10 16 1234567890123456789012345678901234567890
16 35 3A0C92075C0DBF3B8ACBC5F96CE3F0AD2
35 23 333YMHOUE8JPLT7OX6K9FYCQ8A
23 49 946B9AA02MI37E3D3MMJ4G7BL2F05
49 61 1VbDkSIMJL3JjRgAdlUfcaWj
61 5 dl9MDSWqwHjDnToKcsWE1S
5 10 42104444441001414401221302402201233340311104212022133030
���������
62 abcdefghiz
2 11011100000100010111110010010110011111001001100011010010001

10 1234567890123456789012345678901234567890
16 3A0C92075C0DBF3B8ACBC5F96CE3F0AD2

16 3A0C92075C0DBF3B8ACBC5F96CE3F0AD2
35 333YMHOUE8JPLT7OX6K9FYCQ8A

35 333YMHOUE8JPLT7OX6K9FYCQ8A
23 946B9AA02MI37E3D3MMJ4G7BL2F05

23 946B9AA02MI37E3D3MMJ4G7BL2F05
49 1VbDkSIMJL3JjRgAdlUfcaWj

49 1VbDkSIMJL3JjRgAdlUfcaWj
61 dl9MDSWqwHjDnToKcsWE1S

61 dl9MDSWqwHjDnToKcsWE1S
5 42104444441001414401221302402201233340311104212022133030

5 42104444441001414401221302402201233340311104212022133030
10 1234567890123456789012345678901234567890
�Ѷȣ���
ʱ/�����ƣ�1s / 64MB
��ͨ������688
�ܳ�������1270
��Դ�����㷨��������ָ�ϡ�
�㷨��ǩ
