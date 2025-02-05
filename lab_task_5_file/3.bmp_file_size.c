#include <stdio.h>
#include <stdint.h>

int main() {
    uint16_t bfType;
    uint32_t bfSize;

    FILE *file = fopen("sample.bmp", "rb");
    if (!file) {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    fread(&bfType, sizeof(uint16_t), 1, file);
    fread(&bfSize, sizeof(uint32_t), 1, file);

    fclose(file);

    if (bfType == 0x4D42) {
        printf("Given file is a valid BMP file.\n");
        printf("FILE SIZE: %u bytes or %f kbs\n", bfSize, bfSize/1000.0);
    } else {
        printf("Given file is NOT a valid BMP file.\n");
    }

    return 0;
}
