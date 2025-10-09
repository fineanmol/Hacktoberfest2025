#include <iostream>
#include <string>
using namespace std;

int main()
{
        int n, m;
        cout << "Enter the number : ";
        cin >> n;
        m = n / 2 + 1;
        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= n; j++)
                {
                        if (i == m || j == m)
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

        return 0;
}