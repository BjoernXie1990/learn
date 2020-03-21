//��Ŀ����
//���һ�������ܼ���һ�����ڼ������������ʲô���ڡ�
//��������:
//�����һ�б�ʾ��������m��������m��ÿ���ĸ������ֱ��ʾ�����պ��ۼӵ�������
//�������:
//���m�У�ÿ�а�yyyy-mm-dd�ĸ��������
//ʾ��1
//����
//����
//1
//2008 2 3 100
//���
//����
//2008-05-13

#include<iostream>
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
    
    Date& operator+=(int day)
    {
        int maxMonthDay = GetMonthDay(_year,_month);
        _day += day;
        while(_day > maxMonthDay)
        {
            _day -= maxMonthDay;
            _month++;
            if(_month == 13)
            {
                _month = 1;
                _year++;
            }
            maxMonthDay = GetMonthDay(_year,_month);
        }
        return *this;
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
    int m;
    cin>>m;
    int year,month,day,num;
    while(m--)
    {
        cin>>year>>month>>day>>num;
        Date d(year,month,day);
        d += num;
        d.Print();
    }
    
    return 0;
}
