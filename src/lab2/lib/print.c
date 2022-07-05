#include "print.h"
#include "sbi.h"

void puts(char *s) {
    // unimplemented
    char *ps = s;
    while(*ps != '\0'){
        sbi_ecall(0x01, 0x0, (int)(*ps), 0, 0, 0, 0, 0);
        ps++;
    }

    return;
}

void puti(int x) {
    // unimplemented
    int tmp = x;
    if(tmp < 0){
        sbi_ecall(0x01, 0x00, 45, 0, 0, 0, 0, 0);
        tmp = -tmp;
    }
    if(tmp > 9){
        puti(tmp/10);
	    sbi_ecall(0x01,0x00,0x30+tmp%10,0,0,0,0,0);
    }
    if(tmp <= 9){
        sbi_ecall(0x01,0x00,0x30+tmp,0,0,0,0,0);
        return;
    }

    return;
}
