//��Ŀ����
//���������ڣ�����������֮�������������������������������ǹ涨����֮�������Ϊ����
//��������:
//�ж������ݣ�ÿ�����������У��ֱ��ʾ�������ڣ���ʽΪYYYYMMDD
//�������:
//ÿ���������һ�У������ڲ�ֵ
//ʾ��1
//����
//����
//20110412
//20110422
//���
//����
//11

#include<iostream>
using namespace std;

class Date
{
public:
    Date(char* str)
    {
        _year = StrToNum(str,0,4);
        _month = StrToNum(str,4,6);
        _day = StrToNum(str,6,8);
    }
    //�ַ���ת��Ϊ����
    int StrToNum(char* str,int left,int right)
    {
        int num = 0;
        while(left < right)
            num = num * 10 + str[left++] - '0';
        return num;
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
    //����+1����
    Date& operator+=(int day)
	{
		_day += day;
		int maxDay = GetMonthDay(_year, _month);//��ȡ��ǰ�µ��������
		while (maxDay < _day)
		{
			_day -= maxDay;//������ǰ�µ�����
			_month++;//��+1
			//����³��ˣ���+1���±��1��
			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
			maxDay = GetMonthDay(_year, _month);
		}
		return *this;
	}
    
    // >��������� //�ж����ڴ�С
	bool operator>(const Date& d)
	{
		////������ֱ�ӱ�
		//if (_year > d._year)
		//	return true;
		////����ȱ���
		//if (_year == d._year && _month > d._month)
		//	return true;
		////������ȱ���
		//if (_year == d._year && _month == d._month && _day > d._day)
		//	return true;
		if ((_year > d._year) || \
			(_year == d._year && _month > d._month) || \
			(_year == d._year && _month == d._month && _day > d._day))
			return true;
		return false;

	}
    // ==���������
	bool operator!=(const Date& d)
	{
		return _day != d._day ||\
			_month != d._month ||\
			_year != d._year;
	}
    //�������
    int operator-(const Date& d)
	{
		Date small = *this;
		Date big = d;
		if (*this > d)
		{
			big = *this;
			small = d;
		}
		//�ۼӷ�
		int numDay = 0;
		while (small!=big)
		{
			small+=1;
			numDay++;
		}
		return numDay + 1;
	}
private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    char str1[10] = {'\0'};
    char str2[10] = {'\0'};
    cin>>str1>>str2;
    Date d1(str1);
    Date d2(str2);
    
    cout<<d1-d2<<endl;
    return 0;
}
