#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    int nums[10];
    int index = 0;
    int num = 10;
    while(num--)
    {
        scanf("%d",&a);
        nums[index] = a;
        index++;
    }
    for(int i = 0;i < index;i++)
    {
        for(int j = i;j < index - 1;j++)
        {
            if(nums[j] > nums[j + 1])
            {
                int tmp = 0;
                tmp = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    for(int i = 0;i < index;i++)
    {
        printf("%d",nums[i]);
        printf(" ");
    }
    return 0;
}