#include "solve.h"

int divider(int n, int m) {
    if (m > n) {
        int x = n;
        n = m;
        m = x;
    }
    if (m == 0) {
        return 0;
    } else {
        return (n - 1) + n * (m - 1);
    }
}
