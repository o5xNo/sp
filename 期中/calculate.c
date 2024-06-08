#include "calculate.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// 全局變量，用於保存當前解析到的 token
Token current_token;

// 讀取下一個字符
char next_char() {
    return getchar();
}

// 讀取下一個 token
Token next_token() {
    char c;
    // 跳過空白字符
    while (isspace(c = next_char())) {}

    Token token;
    switch (c) {
        case '+':
            token.type = TOKEN_PLUS;
            break;
        case '-':
            token.type = TOKEN_MINUS;
            break;
        case '*':
            token.type = TOKEN_MULTIPLY;
            break;
        case '/':
            token.type = TOKEN_DIVIDE;
            break;
        case '(':
            token.type = TOKEN_LPAREN;
            break;
        case ')':
            token.type = TOKEN_RPAREN;
            break;
        case '\n':
        case EOF:
            token.type = TOKEN_END;
            break;
        default:
            if (isdigit(c) || c == '.') {
                ungetc(c, stdin); // 放回字符流
                scanf("%lf", &token.value); // 讀取浮點數
                token.type = TOKEN_FLOAT; // 使用 TOKEN_FLOAT
            } else {
                token.type = TOKEN_INVALID; // 非法字符
            }
    }

    return token;
}

// 驗證當前 token 的類型
void expect(TokenType expected_type) {
    if (current_token.type != expected_type) {
        printf("錯誤輸入\n");
        exit(EXIT_FAILURE);
    }
    current_token = next_token();
}

// 解析因子
double factor() {
    double result;

    if (current_token.type == TOKEN_INTEGER || current_token.type == TOKEN_FLOAT) {
        result = current_token.value;
        expect(current_token.type); // 使用 current_token.type 驗證
    } else if (current_token.type == TOKEN_LPAREN) {
        expect(TOKEN_LPAREN);
        result = expression();
        expect(TOKEN_RPAREN);
    } else {
        printf("錯誤輸入\n");
        exit(EXIT_FAILURE);
    }

    return result;
}

// 解析乘除表達式
double term() {
    double result = factor();
    while (current_token.type == TOKEN_MULTIPLY || current_token.type == TOKEN_DIVIDE) {
        if (current_token.type == TOKEN_MULTIPLY) {
            expect(TOKEN_MULTIPLY);
            result *= factor();
        } else if (current_token.type == TOKEN_DIVIDE) {
            expect(TOKEN_DIVIDE);
            double divisor = factor(); // 使用 double
            if (divisor == 0) {
                printf("不可除零\n");
                exit(EXIT_FAILURE);
            }
            result /= divisor;
        }
    }
    return result;
}

// 解析加減表達式
double expression() {
    double result = term();
    while (current_token.type == TOKEN_PLUS || current_token.type == TOKEN_MINUS) {
        if (current_token.type == TOKEN_PLUS) {
            expect(TOKEN_PLUS);
            result += term();
        } else if (current_token.type == TOKEN_MINUS) {
            expect(TOKEN_MINUS);
            result -= term();
        }
    }
    return result;
}

// 將浮點數輸出
void print_float(double n) {
    printf("%.4f", n);
}

