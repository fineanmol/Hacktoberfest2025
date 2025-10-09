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
                for (int j = 1; j <= i; j++)
                {
                        cout << j << " ";
                }
                cout << endl;
        }

        return 0;
}