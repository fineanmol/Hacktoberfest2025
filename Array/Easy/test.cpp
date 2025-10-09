#include <bits/stdc++.h>
// #include <bits/stdc++.h>
using namespace std;

int main()
{
          int n;
          cout << "Enter no. of  element :  ";
          cin >> n;
          cout << "Enter the element of first array\n";
          vector<int> v;
          for (int i = 0; i < n; i++)
          {
                    int m;
                    cout << (i + 1) << " value : ";
                    cin >> m;
                    v.push_back(m);
          }
          cout << endl;
          cout << v.back();

          return 0;
}