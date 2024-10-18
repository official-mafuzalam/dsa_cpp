#include <iostream>
#include <string>
using namespace std;

int INDEX(const string &T, const string &P) {
    size_t pos = T.find(P);
    if (pos != string::npos) {
        return pos;
    } else {
        return -1;
    }
}

string DELETE(string T, int start, int length) {
    return T.erase(start, length);
}

int main() {
    string T = "This is a sample text with sample words.";
    string P = "sample";
    int K = INDEX(T, P);
    
    while (K != -1) {
        T = DELETE(T, K, P.length());
        K = INDEX(T, P);
    }
    
    cout << "Result: " << T << endl;
    return 0;
}
