#include <iostream>
#include <string>
using namespace std;

int main()
{
        int n, a;
        cout << "Enter the number of rows : ";
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
                a = 1;
                for (int j = 1; j <= n; j++)
                {
                        if (i + j >= n + 1)
                        {
                                char c = a + 64;
                                cout << c << " ";
                                a++;
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