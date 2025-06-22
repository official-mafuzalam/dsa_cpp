#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_tower, char to_tower, char aux_tower) {
    if (n == 1) {
        cout << "Move disk 1 from tower " << from_tower << " to tower " << to_tower << endl;
        return;
    }
    towerOfHanoi(n - 1, from_tower, aux_tower, to_tower);
    
    cout << "Move disk " << n << " from tower " << from_tower << " to tower " << to_tower << endl;
    
    towerOfHanoi(n - 1, aux_tower, to_tower, from_tower);
}

int main() {
    int num_disks;
    cout << "Enter the number of disks: ";
    cin >> num_disks;

    cout << "Steps to solve the Tower of Hanoi with " << num_disks << " disks:\n";
    towerOfHanoi(num_disks, 'A', 'C', 'B'); // A, B, and C are names of towers

    return 0;
}
