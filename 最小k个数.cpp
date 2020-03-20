//������������ arr ���ҳ�������С�� k ���������磬����4��5��1��6��2��7��3��8��8�����֣�����С��4��������1��2��3��4��

// 

//ʾ�� 1��

//���룺arr = [3,2,1], k = 2
//�����[1,2] ���� [2,1]
//ʾ�� 2��

//���룺arr = [0,1,2,1], k = 1
//�����[0]

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int* arr,int left,int right)
{
    int tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;
}

void sort(int* arr, int arrSize, int k,int left,int right)
{
    //���Ľ���������
    if(left >= right || left >= k)
        return ;
    
    int num = arr[left];
    int l = left;
    int r = right;
    while(l < r)
    {
        //����������
        while(l < r && arr[r] >= num)
            r--;
        arr[l] = arr[r];

        //����������
        while(l < r && arr[l] <= num)
            l++;
        arr[r] = arr[l];
    }
    arr[l] = num;
    //ֻ��Ҫ�ұ�k���к�С��
    if(l < k)
        sort(arr,arrSize,k,l+1,right);
    else if(l > k)
        sort(arr,arrSize,k,left,l-1);
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    sort(arr,arrSize,k,0,arrSize-1);
    *returnSize = k;
    return arr;
}
