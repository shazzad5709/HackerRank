#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
  int k;
  cin >> k;
  string s;
  cin >> s;

  int l = -1;
  int sum = 0;
  int n = s.length();

  for (char ch : s)
  {
    if (ch == '(')
      l++;
  }
}
