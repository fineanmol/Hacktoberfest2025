#include <iostream>
#include <string>
using namespace std;

int main()
{
        int m, n;
        cout << "Enter the no. of rows : ";
        cin >> n;
        cout << "Enter the no. of columns : ";
        cin >> m;
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < m; j++)
                {
                        cout << "* ";
                }
                cout << endl;
        }

        return 0;
}