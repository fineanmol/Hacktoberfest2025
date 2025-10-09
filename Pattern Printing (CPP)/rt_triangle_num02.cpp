#include <iostream>
#include <string>
using namespace std;

int main()
{
        int n, a;
        cout << "Enter the no. of rows : ";
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
                a = 1;
                for (int j = 1; j <= n; j++)
                {
                        // int d = a + 64;
                        // char ch = (char)d;
                        char c = a + 64;
                        cout << c << " ";
                        a++;
                }
                cout << endl;
        }

        return 0;
}