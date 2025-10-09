#include <iostream>
#include <string>
using namespace std;

int main()
{
        int n;
        cout << "Enter the number of Rows : ";
        cin >> n;
        int a;
        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= i; j++)
                {                             // Same Condition but in Another Way //
                        if ((i + j) % 2 != 0) //   if (i==j ||(i + j) % 2 == 0)
                        {                     //  {
                                cout << "0 "; //   cout<<"1 ";
                        }                     // }
                        else                  // else
                        {                     // {
                                cout << "1 "; //   cout<<"0 ";
                        }                     // }
                }
                cout << endl;
        }

        return 0;
}