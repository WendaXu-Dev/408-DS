#include <iostream>
using namespace std;

void PrintArr (int R[], int n)
{
    // 合法性检查
    if (R == NULL || n <= 0)
    {
        return;
    }

    int i = 0;

    for (i = 0; i < n; i++)
    {
        cout << R[i] << ' ';
    }
    cout << endl;
}

void Reverse (int R[], int left, int right)
{
    if (R == NULL || left > right)
    {
        return;
    }

    int temp = 0;

    while (left < right)
    {
        temp = R[left];
        R[left] = R[right];
        R[right] = temp;
        
        left++;
        right--;
    }
}

void LeftRotate (int R[], int n, int p)
{
    // 思想：两次翻转， i.e.线代中的(AB)^T = B^TA^T, 在这里的应用是:(A^TB^T)^T = BA，从而实现元素左移操作

    //合法性检查
    if (p <= 0 || R == NULL)
    {
        // p 过小，非法
        return;
    }
    if (p > n)
    {
        // p 过大，但不非法
        p %= n;

        if (p == 0)
        {
            // 取余后 p 为 0，无法翻转，直接退出
            return;
        }
    }

    Reverse (R, 0, p - 1); // 翻转前段
    Reverse (R, p, n - 1); // 翻转后段 
    Reverse (R, 0, n - 1); // 翻转全局

    PrintArr(R, n);
}

void Test ()
{
    //随便写一个数组
    const int n = 10;
    int R[n] = {0};
    int i = 0;
    int p = 0;

    for (i = 0; i < n; i++)
    {
        R[i] = i;
    }

    while(true)
    {
        cout << "请输入 p, 若输入 '0' 则退出测试: " << endl;
        cin >> p;

        if (p == 0)
        {
            return;
        }

        // 开始测试
        LeftRotate (R, n, p);
    }
}

int main()
{
    Test ();

    return 0;
}