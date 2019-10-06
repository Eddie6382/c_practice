#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s("Hello world");
    for (auto &c : s)
        c = toupper(c);
    cout << s << endl;
    string line;
    while (getline(cin, line))
        if (!line.empty())
            cout << line << endl;
    return 0;
} // namespace std
