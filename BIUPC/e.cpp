#include <iostream>
#include <cmath>
using namespace std;

long long total_damage(long long t, long long b, long long c) {
    long long specials = t / c;
    long long normal = t - specials;
    return specials * b * 2 + normal * b;
}

string winner(long long h1, long long b1, long long c1, long long h2, long long b2, long long c2) {
    long long left = 0, right = 1e9;

    while (left < right) {
        long long mid = (left + right) / 2;
        long long damage_to_jake = total_damage(mid, b1, c1);
        long long damage_to_mike = total_damage(mid, b2, c2);

        if (damage_to_jake >= h2 && damage_to_mike >= h1) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    long long final_time = left;
    long long final_damage_to_jake = total_damage(final_time, b1, c1);
    long long final_damage_to_mike = total_damage(final_time, b2, c2);

    if (final_damage_to_jake >= h2 && final_damage_to_mike >= h1)
        return "DRAW";
    else if (final_damage_to_jake >= h2)
        return "MIKE TYSON";
    else
        return "JAKE PAUL";
}

int main() {
    long long h1, b1, c1, h2, b2, c2;
    cin >> h1 >> b1 >> c1 >> h2 >> b2 >> c2;
    cout << winner(h1, b1, c1, h2, b2, c2) << endl;
    return 0;
}
