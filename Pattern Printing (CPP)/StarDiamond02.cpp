#include <iostream>
#include <string>
using namespace std;
// Much more simpler than first method          // made by pw teacher
int main()
{
        int n, m;
        cout << "Enter the number of rows : ";
        cin >> n;
        m = n / 2 + 1;
        int nst = 1;     //-> starting value of nst     // nst-> no. of star in a line
        int nsp = n / 2; //-> starting value of nsp     // nst-> no. of space in a line
        for (int i = 1; i <= n; i++)
        {
                for (int j = 1; j <= nsp; j++)
                {
                        cout << "  ";
                }
                for (int k = 1; k <= nst; k++)
                {
                        cout << "* ";
                }

                if (i < (n / 2 + 1))
                {
                        nsp--;
                        nst += 2;
                }
                else
                {
                        nsp++;
                        nst -= 2;
                }
                cout << endl;
        }
        return 0;
}