Gilbert Grundy CS250

Bit of a strange project, where we created a program which would
print out a given logic table, and tell the user if a argument
was consistent.

To test the code the lecturer would hard code different tables
into our code.

Not the most useful program, but it is what it is!

Program has a premise function, and a conclusion function. There are three
logical variables - P, Q & R - simply change the logic equations returned 
by the premise and conclusion functions and a different table is printed.


Sample Program Run:

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

The argument is invalid in row 5
The argument is invalid in row 7
Row     P       Q       R       Prem    Concl
0       T       T       T       F       T
1       T       T       F       F       T
2       T       F       T       F       T
3       T       F       F       F       T
4       F       T       T       T       T
5       F       T       F       T       F
6       F       F       T       T       T
7       F       F       F       T       F

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
