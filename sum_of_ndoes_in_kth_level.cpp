#include <iostream>
using namespace std;

int main()
{
  int k;
  cin >> k;
  string s;
  cin >> s;
  int l = -1, n = s.length(), sum = 0;

  for (int i = 0; i < n; i++)
  {

    if (s[i] == '(')
      l++;

    else if (s[i] == ')')
      l--;

    else if (l == k)
    {
      string tmp = "";
      while (i < n && s[i] != '(' && s[i] != ')')
      {
        tmp = tmp + s[i++];
      }
      sum += stoi(tmp);
      i--;
    }
  }

  cout << sum;
}