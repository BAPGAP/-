#include <iostream>
#include <stdio.h>

using namespace std;

union Udoub {
    double d;
    unsigned char c[8];
};

int main() {
    Udoub u;
    u.d = 6.5;
    for (int i=7;i>=0;i--) printf("%02x\n",u.c[i]);
    printf("\n");
    return 0;
}
