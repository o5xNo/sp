#ifndef CALCULATE_H
#define CALCULATE_H

// 定義 token 的類型
typedef enum {
    TOKEN_INTEGER,//整數
    TOKEN_FLOAT,//浮點數
    TOKEN_PLUS,//'+'
    TOKEN_MINUS,//'-'
    TOKEN_MULTIPLY,//'*'
    TOKEN_DIVIDE,//'%'
    TOKEN_LPAREN,//'('
    TOKEN_RPAREN,//')'
    TOKEN_END,//結尾
    TOKEN_INVALID//無效
} TokenType;

// token 結構
typedef struct {
    TokenType type;
    double value; // 使用 double 類型存儲浮點數值
} Token;

// 全局變量，用於保存當前解析到的 token
extern Token current_token;

// 讀取下一個字符
char next_char();

// 讀取下一個 token
Token next_token();

// 驗證當前 token 的類型
void expect(TokenType expected_type);

// 解析表達式
double expression();

// 將浮點數輸出
void print_float(double n);

#endif 