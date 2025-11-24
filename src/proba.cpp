#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string aux = "kitten";
    string a = "s" + aux.substr(1);
    string s = a.substr(0, 4) + "in";
    string res = s + "g";
    cout << res << endl;
    return 0;
}
