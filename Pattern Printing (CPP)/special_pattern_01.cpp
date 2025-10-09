#include <iostream>
#include <string>
using namespace std;

int Special_pattern(int n)
{
        int m, nt;
        m = n - 1;
        nt = 2 * n - 1;
        int nsp = 1;
        for (int i = 1; i <= nt; i++)
        {
                cout << "* ";
        }
        cout << endl;
        int lm, jm;
        lm = m;
        jm = m;
        for (int i = 1; i <= m; i++)
        {

                for (int j = jm; j > 0; j--)
                {
                        cout << "* ";
                }
                jm--;
                for (int k = 1; k <= nsp; k++)
                {
                        cout << "  ";
                }
                nsp += 2;
                for (int l = lm; l > 0; l--)
                {
                        cout << "* ";
                }
                lm--;
                cout << endl;
        }
}

int main()
{
        int n;
        cout << "Enter the number of lines : ";
        cin >> n;
        Special_pattern(n);

        return 0;
}