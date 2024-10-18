#include <iostream>
#include <string>
using namespace std;

int INDEX(const string &T, const string &substring)
{
    size_t pos = T.find(substring);
    if (pos != string::npos)
    {
        return pos;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string T = "HIS FATHER IS THE PROFESSOR";
    cout << "INDEX(T, 'THE'): " << INDEX(T, "THE") << endl;
    cout << "INDEX(T, 'THEN'): " << INDEX(T, "THEN") << endl;
    cout << "INDEX(T, ' PROFESSOR'): " << INDEX(T, " PROFESSOR") << endl;
    return 0;
}
