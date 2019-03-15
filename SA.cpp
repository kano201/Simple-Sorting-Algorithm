#include<iostream>
#include<math.h>
using namespace std;

class SA{
private:
    int test[6] = {12,6,68,2,16,47};

public:
    void BubbleSort()
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

    void InsertionSort()
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

    void ShellSort()
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

    void selectionSort()
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
};

int main()
{
    SA sa = SA();
    sa.selectionSort();
}
