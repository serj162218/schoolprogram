#include <stdio.h>
union {
    short s;
    char c[2];
} un;
union {
    char c[4];
    int s;
} wow;
main(){
    // un.s = 0x0102;
    wow.s = 0x01020304;
    if(wow.c[0]==1 && wow.c[1]==2&&wow.c[2]==3&&wow.c[3]==4){
        printf("Big-Endian\n");
    }else if(wow.c[0]==4&&wow.c[1]==3&&wow.c[2]==2&&wow.c[3]==1)
        printf("Little-Endian\n");
}