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
    void BubbleSort()      //ð������
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

    void InsertionSort()     //��������
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

    void ShellSort()      //ϣ������
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

    void selectionSort()        //ѡ������
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
                {                                  // Ѱ����С����
                    minIndex = j;                 // ����С������������
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
        int x = a[high];//��������������һ������Ϊ��Ԫ����������������л���
        int i = low - 1;//i�����һ��С����Ԫ�������±�
        for (int j = low; j < high; j++)//�����±���low��high-1����
        {
            if (a[j] < x)//�����С����Ԫ�Ļ��ͽ�i��ǰŲ��һ��λ�ã����ҽ���j��i���ֱ�ָ�����
            {
                int temp;
                i++;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        //���������ѭ��֮���±�Ϊ��low��i������i�������;�ΪС��x�����ˣ����ڽ���Ԫ��i+1λ������������н���
        a[high] = a[i + 1];
        a[i + 1] = x;
        return i + 1;
    }

    void QuickSort(int a[], int low, int high)              //��������
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
        if(right<len && arr[right] > arr[maxIdx]) maxIdx = right;  // maxIdx��3��������������±�
        if(maxIdx != index)                 // ���maxIdx��ֵ�и���
        {
            swap(arr[maxIdx], arr[index]);
            adjust(arr, len, maxIdx);       // �ݹ������������������ʵĲ���
        }

    }

    void heapSort(int arr[], int size)                  //������
    {
        for(int i=size/2 - 1; i >= 0; i--)  // ��ÿһ����Ҷ�����жѵ���(�����һ����Ҷ��㿪ʼ)
        {
            adjust(arr, size, i);
        }
        for(int i = size - 1; i >= 1; i--)
        {
            swap(arr[0], arr[i]);           // ����ǰ���ķ��õ�����ĩβ
            adjust(arr, i, 0);              // ��δ�������Ĳ��ּ������ж�����
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
