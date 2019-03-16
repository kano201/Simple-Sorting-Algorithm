#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<math.h>
using namespace std;

class SA{
private:


public:
    int test[6] = {12,6,68,2,16,47};
    void BubbleSort()      //冒泡排序
    {
        int temp;
        for(int k=0;k<6;k++)
        {
            cout << test[k] <<" ";
        }
        cout << endl;


        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6-i;j++)
            {
                if(test[j]>test[j+1])
                {
                    temp = test[j+1];
                    test[j+1] = test[j];
                    test[j] = temp;
                }
            }
        }

        for(int k=0;k<6;k++)
        {
            cout << test[k] << " ";
        }
        cout << endl;
    }

    void InsertionSort()     //插入排序
    {
        int preIndex, current;
        for(int k=0;k<6;k++)
        {
            cout << test[k] << " ";
        }
        cout << endl;
        for (int i = 1; i < 6; i++)
        {
            preIndex = i - 1;
            current = test[i];
            while (preIndex >= 0 && test[preIndex] > current)
            {
                test[preIndex + 1] = test[preIndex];
                preIndex--;
            }
            test[preIndex + 1] = current;
        }
        for(int k=0;k<6;k++)
        {
            cout << test[k] << " ";
        }
        cout << endl;
    }

    void ShellSort()      //希尔排序
    {
        for(int k=0;k<6;k++)
        {
            cout << test[k] << " ";
        }
        cout << endl;
        for (int gap = floor(6/2); gap > 0; gap = floor(gap/2))
        {
            for (int i = gap; i < 6; i++)
            {
                int j = i;
                int current = test[i];
                while (j - gap >= 0 && current < test[j - gap])
                {
                    test[j] = test[j - gap];
                    j = j - gap;
                }
                test[j] = current;
            }
        }
        for(int k=0;k<6;k++)
        {
            cout << test[k] << " ";
        }
        cout << endl;
    }

    void selectionSort()        //选择排序
    {
        for(int k=0;k<6;k++)
        {
            cout << test[k] << " ";
        }
        cout << endl;
        int minIndex, temp;
        for (int i = 0; i < 6; i++)
        {
            minIndex = i;
            for (int j = i + 1; j < 6; j++)
            {
                if (test[j] < test[minIndex])
                {                                  // 寻找最小的数
                    minIndex = j;                 // 将最小数的索引保存
                }
            }
            temp = test[i];
            test[i] = test[minIndex];
            test[minIndex] = temp;
        }
        for(int k=0;k<6;k++)
        {
            cout << test[k] << " ";
        }
        cout << endl;
    }

    int Partition(int a[], int low, int high)
    {
        int x = a[high];//将输入数组的最后一个数作为主元，用它来对数组进行划分
        int i = low - 1;//i是最后一个小于主元的数的下标
        for (int j = low; j < high; j++)//遍历下标由low到high-1的数
        {
            if (a[j] < x)//如果数小于主元的话就将i向前挪动一个位置，并且交换j和i所分别指向的数
            {
                int temp;
                i++;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        //经历上面的循环之后下标为从low到i（包括i）的数就均为小于x的数了，现在将主元和i+1位置上面的数进行交换
        a[high] = a[i + 1];
        a[i + 1] = x;
        return i + 1;
    }

    void QuickSort(int a[], int low, int high)              //快速排序
    {
        for(int k=0;k<6;k++)
        {
            cout << test[k] << " ";
        }
        cout << endl;
        if (low < high)
        {
            int q = Partition(a, low, high);
            QuickSort(a, low, q - 1);
            QuickSort(a, q + 1, high);
        }
    }

    void adjust(int arr[], int len, int index)
    {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int maxIdx = index;
        if(left<len && arr[left] > arr[maxIdx]) maxIdx = left;
        if(right<len && arr[right] > arr[maxIdx]) maxIdx = right;  // maxIdx是3个数中最大数的下标
        if(maxIdx != index)                 // 如果maxIdx的值有更新
        {
            swap(arr[maxIdx], arr[index]);
            adjust(arr, len, maxIdx);       // 递归调整其他不满足堆性质的部分
        }

    }

    void heapSort(int arr[], int size)                  //堆排序
    {
        for(int i=size/2 - 1; i >= 0; i--)  // 对每一个非叶结点进行堆调整(从最后一个非叶结点开始)
        {
            adjust(arr, size, i);
        }
        for(int i = size - 1; i >= 1; i--)
        {
            swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
            adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
        }
    }

};

int main()
{
    SA sa = SA();
    for(int k=0;k<6;k++)
        {
            cout << sa.test[k] << " ";
        }
        cout << endl;
    sa.heapSort(sa.test,6);
    for(int k=0;k<6;k++)
    {
        cout << sa.test[k] << " ";
    }
    cout << endl;
}
