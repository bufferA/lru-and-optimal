# lru-and-optimal
操作說明：
在visual studio中屬性欄位中的命令引數輸入
若要執行LRU則輸入:0 sample3.in out.text
0為LRU選項
sample3.in為輸入檔名
out.text為輸出檔
若要執行OPT則輸入:1 sample3.in out.text

1為OPT選項
sample3.in為輸入檔名
out.text為輸出檔

輸出檔即為排程完成之輸出
設定完指令無需input任何文字

演算法:
LRU(Least recent use):
最近未使用優先pop out
OPT(optimal algorithm):
將來長期不被使用的優先pop out

example input file:
12 3
1 2 3 4 1 2 5 1 2 3 4 5
12代表共有12個數字
3代表有三個page
1 2 3 4 1 2 5 1 2 3 4 5為輸入的數字

example LRU output file:(-1代表尚為空格)
10
1 -1 -1 
2 1 -1 
3 2 1 
4 3 2 
4 3 1 
4 2 1 
5 2 1 
5 2 1 
5 2 1 
3 2 1 
4 3 2 
5 4 3 
example OPT output file:(-1代表尚為空格)
7
1 -1 -1 
2 1 -1 
3 2 1 
4 2 1 
4 2 1 
4 2 1 
5 2 1 
5 2 1 
5 2 1 
5 3 2 
5 4 3 
5 4 3 

