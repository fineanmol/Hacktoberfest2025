#include <iostream>
#include <string>
using namespace std;
// Incomplete
int main()
{
        int n, m;
        cout << "Enter the number of Rows : ";
        cin >> n;
        cout << "Enter the number of Rows : ";
        cin >> m;

        for (int i = 1; i <= n; i++)
        {
                if (i == 1 || i == n)
                {
                        for (int j = 1; j <= m; j++)
                        {
                                cout << "* ";
                        }
                }
                else
                {
                        for (int j = 0; j <= n; j++)
                        {
                                if (j == 1 || j == m)
                                {
                                        cout << "* ";
                                }
                                else
                                {
                                        cout << "  ";
                                }
                        }
                }
                cout << endl;
        }

        return 0;
}