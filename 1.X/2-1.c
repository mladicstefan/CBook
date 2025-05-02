#include <stdint.h>
#include <stdio.h>

void compute_usigned_max(){
    uint8_t u8 = 0;
    while(++u8 != 0);
    printf("uint8_t max: %u\n", u8 -1);

    uint32_t u32 = 0;
    while (++u32 != 0);
    printf("uint32_t max: %u\n", ~u32);

}

void compute_signed_limits() {
    int8_t i8 = 0, i8_prev = 0;
    while (++i8 > 0) i8_prev = i8;
    printf("int8_t min: %d, max: %d\n", i8, i8_prev);

    int32_t i32 = 0, i32_prev = 0;
    while (++i32 > 0) i32_prev = i32;
    printf("int32_t min: %d, max: %d\n", i32, i32_prev);
}

int main(void){
    printf("Manual Computation of Ranges:\n");
    compute_usigned_max();
    compute_signed_limits();

}