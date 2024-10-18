#include <iostream>
using namespace std;

void SWITCH(int &AAA, int &BBB) {
    int TEMP = AAA;
    AAA = BBB;
    BBB = TEMP;
}

int main() {
    int BEG = 5;
    int AUX = 10;
    cout << "Before SWITCH: BEG = " << BEG << ", AUX = " << AUX << endl;
    SWITCH(BEG, AUX);
    cout << "After SWITCH: BEG = " << BEG << ", AUX = " << AUX << endl;
    return 0;
}
