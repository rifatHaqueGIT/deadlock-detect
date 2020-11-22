# deadlock detection - skeleton for Assignment 4

To compile all code, type:
```
$ make
```

To run the resulting code on file test1.txt:
```
$ ./deadlock < test1.txt
```

To run some built-in mini tests:
```
$ ./deadlock test
```

## IMPORTANT

Only modify and submit the `deadlock_detector.cpp` file. Your TAs will
supply their own versions of the other files (such as main.cpp) to
compile and test your code.

## correct outputs

| test file | :correct line_no: | correct cycle | minimum<br> timings | good<br> timings |
| :-------- | :-------------: | :-----------: | :-----------------: | :--------------: |
| `test1.txt` | `-1` | `[]` | `0.0000s` | `0.0000s` |
| `test2.txt` | `5` |`[5,7]` | `0.0000s` | `0.0000s` |
| `test3.txt` | `3`  | `[p7,p3]`| `0.0000s` | `0.0000s` |
| `test4.txt` | `3`| `[12,7]` | `0.0000s` | `0.0000s` |
| `test5.txt` | `6` | `[2,77]` | `0.0000s` | `0.0000s` |
| `test6.txt` | `9903` | `[ab,cd,ef]` |`8.9431s` |`0.8771s` |


