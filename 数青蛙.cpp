#include <iostream>
#include <vector>
#include <string>
using namespace std; 
//ac 
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> gua(255,0);
        gua['c'] = gua['r'] = gua['o'] = gua['a'] = gua['k'] = 1;
        string g = "croak";
        vector<int> arr(5,0);
        arr[0] = 1;
        int num = 1;//��������
        int len = croakOfFrogs.size();
        
        int i = 0;
        while(i < len){
            if(gua[croakOfFrogs[i]] == 0)
                return -1;
            
            for(int j = 0; j < 5; j++){
                if(g[j] == croakOfFrogs[i]){
                    if(arr[j]){
                        arr[j]--;
                        arr[(j+1)%5]++;
                    }
                    else if(croakOfFrogs[i] == 'c'){
                        arr[1]++;
                        num++;//����һֻ����
                    }
                    else{
                        return -1;
                    }
                }
            }
            i++;
        }
        
        for(int j = 1; j < 5; j++){
            if(arr[j])
                return -1;
        }
        return num;
    }
};

//��ʱд�� 
class Solution {
public:
	int minNumberOfFrogs(string croakOfFrogs) {
        string gua = "croak";
        vector<int> nums;
        nums.push_back(0);//��һֻ���ܣ���һ��Ӧ�� ��c��
        int len = croakOfFrogs.size();
        
        for(int i = 0; i < len; i++){
            int size = nums.size();//��ǰ��������
            int flag = 1;
            for(int j = 0; j < size; j++){
                if(croakOfFrogs[i] == gua[nums[j]]){
                    nums[j] = (nums[j]+1) % 5;
                    flag = 0;
                    break;
                }
            }
            
            if(flag)//ô��gua����ƥ��
            {
                //����һֱgua
                if(croakOfFrogs[i] == 'c')
                    nums.push_back(1);
                else
                    return -1;
            }
        }
        
        return nums.size();
    }
};


