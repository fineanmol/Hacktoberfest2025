#include <iostream>
#include <string>
using namespace std;

int main()
{
        int n;
        cout << "Enter the number of rows : ";
        cin >> n;
        int nt = n / 2 + 1;
        int lower_nsp = 1;
        int lower_nst = n - 2;

        for (int i = 1; i <= n; i++)
        {
                if (i <= n / 2 + 1)
                {
                        for (int j = 1; j <= nt - i; j++)
                        {
                                cout << "  ";
                        }
                        for (int k = 1; k <= 2 * i - 1; k++)
                        {
                                cout << "* ";
                        }
                        cout << endl;
                }
                else
                {
                        for (int l = 1; l <= lower_nsp; l++)
                        {
                                cout << "  ";
                        }
                        lower_nsp++;
                        for (int m = 1; m <= lower_nst; m++)
                        {
                                cout << "* ";
                        }
                        lower_nst -= 2;
                        cout << endl;
                }
        }
        return 0;
}