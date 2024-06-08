#include "calculate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    const char *welcome_msg = "�ۻs�p���\n��J�⦡:\n";
    printf("%s", welcome_msg);

    current_token = next_token(); // ��l�ƲĤ@�� token

    double result = expression(); // �ѪR��F���A�ϥ� double ���O

    if (current_token.type != TOKEN_END) {
        printf("���~��J\n");
        return EXIT_FAILURE;
    }
    else if(result!=0){
        printf("���׬�: ");
        print_float(result); // �ϥ� print_float �禡��X�B�I��
        printf("\n");
    }
    else{
        printf("���׬�: ");
        print_float(result); // �ϥ� print_float �禡��X�B�I��
        printf("\n");
    }
    return EXIT_SUCCESS;
}