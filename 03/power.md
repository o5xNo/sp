###機器碼###

```c
1: #include <stdio.h>
2:
3: int power(int a, int n) {
4:   if (n==1) return a;
    ENT  0
    LLA  2
    LI
    PSH
    IMM  1
    EQ
    BZ   0
    LLA  3
    LI
    LEV
5:   else return a*power(a,n-1);
    JMP  0
    LLA  3
    LI
    PSH
    LLA  3
    LI
    PSH
    LLA  2
    LI
    PSH
    IMM  1
    SUB
    PSH
    JSR  12714136
    ADJ  2
    MUL 
    LEV
6: }
    LEV
7:
8: int main() {
9:   printf("power(2,5)=%d\n", power(2,5));
    ENT  0
    IMM  12976288
    PSH
    IMM  2
    PSH
    IMM  5
    PSH
    JSR  12714136
    ADJ  2
    PSH
    PRTF
    ADJ  2
10: }
    LEV

```

###Output###
```c
1> ENT  0
2> IMM  4215121
3> PSH 
4> IMM  2
5> PSH 
6> IMM  5
7> PSH 
8> JSR  11927680
9> ENT  0
10> LLA  2
11> LI  
12> PSH
13> IMM  0
14> EQ
15> BZ   11927808
16> LLA  3
17> LI
18> PSH
19> LLA  3
20> LI
21> PSH
22> LLA  2
23> LI
24> PSH
25> IMM  1
26> SUB
27> PSH
28> JSR  11927680
29> ENT  0
30> LLA  2
31> LI
32> PSH
33> IMM  0
34> EQ
35> BZ   11927808
36> LLA  3
37> LI
38> PSH
39> LLA  3
40> LI
41> PSH
42> LLA  2
43> LI
44> PSH
45> IMM  1
46> SUB
47> PSH
48> JSR  11927680
49> ENT  0
50> LLA  2
51> LI
52> PSH
53> IMM  0
54> EQ
55> BZ   11927808
56> LLA  3
57> LI
58> PSH
59> LLA  3
60> LI
61> PSH
62> LLA  2
63> LI
64> PSH
65> IMM  1
66> SUB
67> PSH
68> JSR  11927680
69> ENT  0
70> LLA  2
71> LI
72> PSH
73> IMM  0
74> EQ
75> BZ   11927808
76> LLA  3
77> LI
78> PSH
79> LLA  3
80> LI
81> PSH
82> LLA  2
83> LI
84> PSH
85> IMM  1
86> SUB
87> PSH
88> JSR  11927680
89> ENT  0
90> LLA  2
91> LI
92> PSH
93> IMM  0
94> EQ
95> BZ   11927808
96> LLA  3
97> LI
98> PSH
99> LLA  3
100> LI
101> PSH
102> LLA  2
103> LI
104> PSH
105> IMM  1
106> SUB
107> PSH
108> JSR  11927680
109> ENT  0
110> LLA  2
111> LI
112> PSH
113> IMM  0
114> EQ
115> BZ   11927808
116> IMM  1
117> LEV
118> ADJ  2
119> MUL
120> LEV
121> ADJ  2
122> MUL
123> LEV
124> ADJ  2
125> MUL
126> LEV
127> ADJ  2
128> MUL
129> LEV
130> ADJ  2
131> MUL
132> LEV
133> ADJ  2
134> PSH
135> PRTF
 power(2,5)=32
136> ADJ  2
137> LEV
```