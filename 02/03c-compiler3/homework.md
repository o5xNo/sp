```c
void DOWHILE() {
  int whileBegin = nextLabel(); // 宣告一個變數用於迴圈的起始標籤
  int whileEnd = nextLabel(); // 宣告一個變數用於迴圈的結束標籤
  skip("do"); // 跳過 "do" 關鍵字
  emit("(L%d)\n", whileBegin); // 輸出迴圈的起始標籤
  STMT(); // 呼叫 STMT 函式處理迴圈內部的陳述式
  skip("while"); // 跳過 "while" 關鍵字
  skip("("); // 跳過左括號
  int e = E(); // 呼叫 E 函式處理迴圈的條件表達式
  emit("if T%d goto L%d\n", e, whileBegin); // 輸出條件判斷，若成立則跳轉至迴圈起始標籤
  skip(")"); // 跳過右括號
  skip(";"); // 跳過分號
}
```
```c
============ parse =============
t0 = 1
i = t0
(L0)
t1 = i
t2 = 1
t3 = t1 + t2
i = t3
t4 = i
t5 = 10
t6 = t4 < t5
if T6 goto L0
```