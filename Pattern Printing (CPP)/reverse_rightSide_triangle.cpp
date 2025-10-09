#include <iostream>
#include <string>
using namespace std;

int main()
{
        int n;
        cout << "Enter the number of rows : ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= i - 1; j++)
                {
                        cout << "  ";
                }
                for (int k = 1; k <= n - i + 1; k++)
                {
                        cout << "* ";
                }
                cout << endl;
        }

        return 0;
}