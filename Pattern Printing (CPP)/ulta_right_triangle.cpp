#include <iostream>
#include <string>
using namespace std;

int main()
{
        int n;
        cout << "Enter the no. of rows : ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
                for (int j = n - i + 1; j >= 1; j--)
                {
                        cout << "* ";
                }
                cout << endl;
        }

        return 0;
}