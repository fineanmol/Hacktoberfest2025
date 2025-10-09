#include <iostream>
#include <string>
using namespace std;

void pattern(int n)
{
        int m = 2 * n - 1;
        int nsp = n - 1;
        int nst = 1;
        int ml = n;
        for (int i = 1; i <= m; i++)
        {
                for (int j = 1; j <= nst; j++)
                {
                        cout << "* ";
                }
                for (int k = 1; k <= nsp; k++)
                {
                        cout << "  ";
                }
                if (i < ml)
                {
                        nsp--;
                        nst++;
                }
                else
                {
                        nsp++;
                        nst--;
                }
                cout << endl;
        }
}

int main()
{
        pattern(5);

        return 0;
}