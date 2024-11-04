#ifndef SIGN_H
#define SIGN_H

#include <iostream>

int sign(int val) {
    if (val < 0) return -1;
    if (val > 0) return 1;
    return 0;
}

#endif
