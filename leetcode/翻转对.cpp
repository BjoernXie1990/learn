����һ������?nums?�����?i < j?��?nums[i] > 2*nums[j]?���Ǿͽ�?(i, j)?����һ����Ҫ��ת�ԡ�

����Ҫ���ظ��������е���Ҫ��ת�Ե�������

ʾ�� 1:

����: [1,3,2,3,1]
���: 2
ʾ�� 2:

����: [2,4,3,5,1]
���: 3
ע��:

��������ĳ��Ȳ��ᳬ��50000��
���������е��������ֶ���32λ�����ı�ʾ��Χ�ڡ�


class Solution {
public:
    vector<int> tmp;
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        tmp.resize(n);
        return merge_sort(nums,0,n-1);
    }

    int merge_sort(vector<int>& nums,int le,int ri)
    {
        if(le >= ri)    return 0;
        int mid = (le + ri) / 2;
        int res = merge_sort(nums,le,mid) + merge_sort(nums,mid+1,ri);
 
        int l = le;
        int r = mid+1;
        for(int i = l ; i <= mid; i++)
        {
            while(r <= ri && nums[i] / 2.0 <= (double)nums[r]) r++;
            res += ri - r + 1; 
        }
        r = mid+1;
        for(int i = le; i <= ri; i++)
        {
            if(l == mid + 1)
            {
                tmp[i] = nums[r];
                r++;
            }
            else if(r == ri + 1)
            {
                tmp[i] = nums[l];
                l++;
            }
            else if(nums[l] > nums[r])
            {
                tmp[i] = nums[l];
                l++;
            }
            else
            {
                tmp[i] = nums[r];
                r++;
            }
        }
        
        for(int i = le; i <= ri; i++)
            nums[i] = tmp[i];
        return res;
    }
};
