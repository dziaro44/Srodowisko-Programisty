# Fork Tree Task Description

The goal of the program is to create a process tree of a given size that represents a **nearly full binary tree**, meaning:
- The leaves are on the last level, and possibly the second-last level (only if the last level is not completely filled).
- The leaves on the last level are arranged contiguously from left to right.

To create such a tree, the program should fork processes multiple times. At the end, the PID of the root process (i.e., the PID of the process in which the program was called) should be printed.

### Execution Flow:
1. In the main process, fork the necessary number of child processes.
2. Without waiting for the child processes to finish, invoke `sleep(1)` in the main process.
3. In the child processes, after forking, invoke `sleep(10)` (or `sleep(1000000)` as an alternative).
4. After the `sleep(1)` in the main process ends (once the tree is created), print the PID of the main process.
5. Invoke `sleep(5)` in the main process, during which a checker verifies whether the tree was created correctly.
6. Finish the main process, which will cause all the child processes to terminate.

### Example:

#### Input:
```
10
```

#### Output:
```
42640
```

#### Expected Tree Structure:
```
prog(42640)─┬─prog(42641)─┬─prog(42643)─┬─prog(42647)
            │             │             └─prog(42648)
            │             └─prog(42645)───prog(42649)
            └─prog(42642)─┬─prog(42644)
                          └─prog(42646)
```

#### Input:
```
40
```

#### Output:
```
46057
```

#### Expected Tree Structure:
```
prog(46057)─┬─prog(46058)─┬─prog(46060)─┬─prog(46063)─┬─prog(46080)─┬─prog(46089)
            │             │             │             │             └─prog(46093)
            │             │             │             └─prog(46082)─┬─prog(46095)
            │             │             │                           └─prog(46096)
            │             │             └─prog(46066)─┬─prog(46072)─┬─prog(46092)
            │             │                           │             └─prog(46094)
            │             │                           └─prog(46075)─┬─prog(46088)
            │             │                                         └─prog(46090)
            │             └─prog(46062)─┬─prog(46065)─┬─prog(46073)───prog(46091)
            │                           │             └─prog(46077)
            │                           └─prog(46069)─┬─prog(46074)
            │                                         └─prog(46078)
            └─prog(46059)─┬─prog(46061)─┬─prog(46067)─┬─prog(46083)
                          │             │             └─prog(46086)
                          │             └─prog(46070)─┬─prog(46081)
                          │                           └─prog(46085)
                          └─prog(46064)─┬─prog(46068)─┬─prog(46084)
                                        │             └─prog(46087)
                                        └─prog(46071)─┬─prog(46076)
                                                      └─prog(46079)
```
