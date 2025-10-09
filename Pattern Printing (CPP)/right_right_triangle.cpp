#include <iostream>
#include <string>
using namespace std;

int main()
{
        int n;
        cout << "Enter the number of Rows : ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= n; j++)
                {
                        if (j + i >= n + 1)
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