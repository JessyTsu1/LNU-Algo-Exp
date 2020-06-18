#include<iostream>
using namespace std;
void Swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

bool IsSwap(char* pszStr, int nBegin, int nEnd)
{
    for (int i = nBegin; i < nEnd; i++)
        if (pszStr[i] == pszStr[nEnd])
            return false;
    return true;
}

//k表示当前选取到第几个数,m表示共有多少数.  
void AllRange(char* pszStr, int k, int m)
{
    if (k == m)
    {
        static int s_i = 1;
        printf("第%d个排列是%s\n", s_i++, pszStr);
    }
    else
    {
        for (int i = k; i <= m; i++)
        {
            if (IsSwap(pszStr, k, i))
            {
                Swap(pszStr + i, pszStr + k);
                AllRange(pszStr, k + 1, m);
                Swap(pszStr + i, pszStr + k);
            }
        }
    }
}

void Foo(char* pszStr)
{
    AllRange(pszStr, 0, strlen(pszStr) - 1);
}

int main()
{
    printf("全排列的递归实现:\n");
    char szTextStr[] = "1233";
    printf("%s的全排列如下:\n", szTextStr);
    Foo(szTextStr);
    system("pause");
    return 0;
}