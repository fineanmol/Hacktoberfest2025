#include <iostream>
#include <string>
using namespace std;

int main()
{
        int n;
        cout << "Enter the number of Rows : ";
        cin >> n;
        int a = 1;
        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= i; j++)
                {
                        cout << a << " ";
                        a += 2;
                }
                cout << endl;
        }

        return 0;
}