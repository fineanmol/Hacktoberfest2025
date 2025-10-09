#include <iostream>
#include <string>
using namespace std;

int main()
{
        int n, a;
        cout << "Enter the number of lines : ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= n - i; j++)
                {
                        cout << "  ";
                }
                a = 1;
                for (int k = 1; k <= 2 * i - 1; k++)
                {
                        char c = a + 64;
                        cout << c << " ";
                        a++;
                }
                cout << "\n";
        }

        return 0;
}