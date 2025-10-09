#include <iostream>
#include <string>
using namespace std;

int main()
{
        int n;
        cout << "Enter the number of row : ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= n - i; j++)
                {
                        cout << "  ";
                }
                for (int k = 1; k <= i; k++)
                {
                        cout << k << " ";
                }
                for (int l = i - 1; l > 0; l--)
                {
                        cout << l << " ";
                }
                cout << endl;
        }
        return 0;
}