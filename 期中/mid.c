#include "calculate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    const char *welcome_msg = "自製計算機\n輸入算式(結尾輸入=):\n";
    printf("%s", welcome_msg);

    current_token = next_token(); // 初始化第一個 token

    double result = expression(); // 解析表達式，使用 double 型別

    if (current_token.type != TOKEN_END) {
        printf("錯誤輸入\n");
        return EXIT_FAILURE;
    }
    else{
        printf("答案為: ");
        print_float(result);
        printf("\n");
        return EXIT_SUCCESS;
    }
}