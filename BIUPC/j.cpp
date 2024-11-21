// #include <iostream>
// #include <string>
// #include <unordered_set>
// using namespace std;

// int main() {
//     string msg;
//     cin >> msg;

//     unordered_set<char> con_char = {'a', 'e', 'i', 'o', 'u'};
//     string encrypted;

//     for (char c : msg) {
//         if (con_char.count(c)) {
//             char shifted = (c == 'z') ? 'a' : c + 1;
//             encrypted += shifted;
//         } else {
//             char shifted = (c >= 'y') ? (c - 24) : c + 2; 
//             encrypted += shifted;
//         }
//     }
//     cout << encrypted << endl;

//     return 0;
// }

#include <iostream>
#include <string>

using namespace std;

int main() {
    string msg;
    cin >> msg;

    string encrypted;

    for (int i = 0; i < msg.length(); i++) {
        char c = msg[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            char shifted = (c == 'z') ? 'a' : c + 1;
            encrypted += shifted;
        } else {
            char shifted = (c >= 'y') ? (c - 24) : c + 2;
            encrypted += shifted;
        }
    }

    cout << encrypted << endl;

    return 0;
}