#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long combination(int n, int r) {
    // r이 더 크면 보완 (C(n, r) == C(n, n-r))
    r = min(r, n - r);

    long long result = 1;
    for (int i = 1; i <= r; i++) {
        result *= n - r + i;
        result /= i;
    }
    return result;
}

int solution(int balls, int share) {
    return (int)combination(balls, share);
}