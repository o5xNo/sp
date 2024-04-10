## 我有4000塊錢分別從ATM1跟ATM2取出1元，並重複操作250次，共計取出500元

###### have race

```c
round1:
money=3500 ::c=1
money=3500 ::c=2
......
money=3500 ::c=693
money=3500 ::c=694
money=3535 ::c=695
An error occurred in round 695

round2:
money=3500 ::c=1
money=3500 ::c=2
......
money=3500 ::c=3620
money=3500 ::c=3621
money=3750 ::c=3622
An error occurred in round 3622
```


###### no race

```c
money=3500 ::c=1
money=3500 ::c=2
money=3500 ::c=3
......
money=3500 ::c=99998
money=3500 ::c=99999
money=3500 ::c=100000
No errors occurred in a total of 100000 rounds of testing
```