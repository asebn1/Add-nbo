#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char*argv[]) {
    uint32_t num1, num2, sum;
    FILE *file1 = fopen(argv[1], "rb");
    FILE *file2 = fopen(argv[2], "rb");

    if(argc != 3) {
        printf("fail. plz check [%s <filename1> <filename2>]\n", argv[0]);
        return 0;
    }

    fread(&num1, sizeof(num1), 1, file1);
    sum = ((num1 & 0xff000000)>> 24) | ((num1 & 0x00ff0000) >> 8) | ((num1& 0x0000ff00) << 8) | ((num1& 0x000000ff) <<24);
    num1 = sum;
    printf("num1=0x%04x\n", num1);

    fread(&num2, sizeof(num2), 1, file2);
    sum = ((num2 & 0xff000000)>> 24) | ((num2 & 0x00ff0000) >> 8) | ((num2& 0x0000ff00) << 8) | ((num2& 0x000000ff) <<24);
    num2 = sum;
    printf("num2=0x%04x\n", num2);

    sum = num1 + num2;
    printf("%d(0x%04x) + %d(0x%04x) = %d(0x%04x)\n",num1, num1, num2, num2, sum, sum);

    return 0;
}
