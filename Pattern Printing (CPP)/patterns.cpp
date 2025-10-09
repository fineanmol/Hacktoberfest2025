#include <iostream>
#include <string>
using namespace std;

void pattern01(int n)
{
        int toggle = 1;
        for (int i = 1; i <= n; i++)
        {
                i % 2 != 0 ? toggle = 1 : toggle = 0;
                for (int j = 1; j <= i; j++)
                {
                        cout << toggle << " ";
                        toggle == 0 ? toggle = 1 : toggle = 0;
                }

                cout << endl;
        }
}

void pattern02(int n)
{
        int count;
        int nsp = 2 * n - 2;
        for (int i = 1; i <= n; i++)
        {
                count = 0;
                for (int j = 1; j <= i; j++)
                {

                        cout << ++count << " ";
                }

                for (int k = 1; k <= nsp; k++)
                {
                        cout << "  ";
                }
                nsp -= 2;
                for (int j = 1; j <= i; j++)
                {
                        cout << count-- << " ";
                }
                cout << endl;
        }
}

void pattern03(int n)
{
        int count = 1;
        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= i; j++)
                {
                        cout << count++ << " ";
                }
                cout << "\n";
        }
}

void pattern04(int n)
{
        int a;
        for (int i = 1; i <= n; i++)
        {
                a = 1;
                for (int j = n - i + 1; j > 0; j--)
                {
                        char ch = a + 64;
                        cout << ch << " ";
                        a++;
                }
                cout << "\n";
        }
}

void pattern05(int n)
{
        int a = 1;
        for (int i = 1; i <= n; i++)
        {

                for (int j = 1; j <= i; j++)
                {
                        char ch = a + 64;
                        cout << ch << " ";
                }
                a++;
                cout << "\n";
        }
}

void pattern06(int n)
{
        int a;
        for (int i = 1; i <= n; i++)
        {
                for (int j = n - i; j > 0; j--)
                {
                        cout << "  ";
                }
                a = 1;
                for (int k = 1; k <= i; k++)
                {
                        char c = a + 64;
                        cout << c << " ";
                        a++;
                }
                a -= 2;
                for (int l = 1; l <= i - 1; l++)
                {
                        char c = a + 64;
                        cout << c << " ";
                        a--;
                }
                cout << endl;
        }
}

void pattern07(int n)
{
        int a;
        for (int i = 1; i <= n; i++)
        {
                a = n + 64;
                for (int j = 1; j <= i; j++)
                {
                        char c = a;
                        cout << c << " ";
                        a--;
                }
                cout << "\n";
        }
}

void pattern08(int n)
{
        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= n; j++)
                {
                        if (i == 1 || j == 1 || i == n || j == n)
                        {
                                cout << "* ";
                        }
                        else
                        {
                                cout << "  ";
                        }
                }
                cout << endl;
        }
}

int main()
{
        pattern08(5);

        return 0;
}