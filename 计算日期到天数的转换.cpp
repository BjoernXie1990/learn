//��Ŀ����
//������������ڣ���������һ��ĵڼ��졣��

//��ϸ������

//����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿��

// 
//��������:
//�������У��ֱ����꣬�£���

//�������:
//�ɹ�:����outDay��������ĵڼ���;
//                                           ʧ��:����-1

//ʾ��1
//����
//����
//2012
//12
//31
//���
//����
//366

#include <iostream>
using namespace std;

class Date
{
public:
    Date(int year,int month,int day)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    
    int GetMonthDay(int year,int month)
    {
        static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];//�õ���ǰ�³���2.29���������

		//�������2��29��
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}

		return day;
    }
    
    int slove()
    {
        //�жϵ�ǰ�����Ƿ�Ϸ�
        if(GetMonthDay(_year,_month) < _day)
            return -1;
        int ans = _day;
        int i = 1;
        while(i < _month)
        {
            ans += GetMonthDay(_year,i);
            i++;
        }
        return ans;
    }
private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    int year,month,day;
    while(cin>>year>>month>>day)
    {
        Date d(year,month,day);
        cout<<d.slove()<<endl;
    }
    return 0;
}
