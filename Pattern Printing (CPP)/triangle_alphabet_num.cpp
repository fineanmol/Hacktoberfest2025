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
                if (i % 2 == 0)
                {
                        a = 1;
                        for (int j = 1; j <= i; j++)
                        {
                                char c = a + 64;
                                cout << c << " ";
                                a++;
                        }
                }
                else
                {
                        for (int j = 1; j <= i; j++)
                        {
                                cout << j << " ";
                        }
                }

                cout << endl;
        }

        return 0;
}