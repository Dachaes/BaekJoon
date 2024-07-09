#include <iostream>
#include <vector>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int n = 0;
  cin >> n;
  cin.ignore();
  vector<int> stack;

  for(int i = 0; i < n; i++)
  {
    string command;
    getline(cin, command);

    // push 연산
    if (command.find("push") != string::npos)
    {
      int num = stoi(command.substr(5));
      stack.push_back(num);
    }
    // pop 연산
    else if (command == "pop")
    {
      if (stack.empty())
        cout << -1 << endl;
      else
      {
        cout << stack.back() << endl;
        stack.pop_back();
      }
    }
    // size 연산
    else if (command == "size")
      cout << stack.size() << endl;
    // empty 연산
    else if (command == "empty")
    {
      if (stack.empty())
        cout << 1 << endl;
      else
        cout << 0 << endl;
    }
    // top 연산
    else if (command == "top")
    {
      if (stack.empty())
        cout << -1 << endl;
      else
        cout << stack.back() << endl;
    }
  }
  
  return 0;
}