��Ŀ����
//�������m��һ���еĵ�n�죬�����n���Ǽ��¼��š�
//��������:
//���������������y(1<=y<=3000)��n(1<=n<=366)��
//�������:
//�����ж���������ݣ�����ÿ�����ݣ�
//�� yyyy-mm-dd�ĸ�ʽ�������ж�Ӧ�����ڴ�ӡ������
//ʾ��1
//����
//����
//2000 3
//2000 31
//2000 40
//2000 60
//2000 61
//2001 60
//���
//����
//2000-01-03
//2000-01-31
//2000-02-09
//2000-02-29
//2000-03-01
//2001-03-01

#include<iostream>
using namespace std;

class Date
{
public:
    //��ȡ��ǰ�·ݵ��������
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
    
    void slove(int year,int day)
    {
        int month = 1;
        int maxMonthDay = GetMonthDay(year,month);
        while(day > maxMonthDay)
        {
            day -= maxMonthDay;
            month++;
            if(month == 13)
            {
                month = 1;
                year++;
            }
            maxMonthDay = GetMonthDay(year,month);
        }
        _year = year;
        _month = month;
        _day = day;
    }

    void Print()
    {
        cout<<_year<<'-';
        if(_month < 10)
            cout<<'0';
        cout<<_month<<'-';
        if(_day < 10)
            cout<<'0';
        cout<<_day<<endl;
    }
private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    int year,day;
    while(cin>>year>>day)
    {
        Date d;
        d.slove(year,day);
        d.Print();
    }
    
    return 0;
}
