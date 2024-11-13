#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // Base case: If only one disk, move it directly
    if (n == 1) {
        cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
        return;
    }
    // Move n-1 disks from 'from_rod' to 'aux_rod' using 'to_rod' as auxiliary
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    
    // Move the nth disk from 'from_rod' to 'to_rod'
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    
    // Move the n-1 disks from 'aux_rod' to 'to_rod' using 'from_rod' as auxiliary
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int num_disks;
    cout << "Enter the number of disks: ";
    cin >> num_disks;

    cout << "Steps to solve the Tower of Hanoi with " << num_disks << " disks:\n";
    towerOfHanoi(num_disks, 'A', 'C', 'B'); // A, B, and C are names of rods

    return 0;
}