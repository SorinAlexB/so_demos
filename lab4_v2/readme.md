# Lab4

## mmap_demo

```
cd mmap_demo
make
```

Now run `./map_writer` and `./map_reader`. The terminal should look like this:
```
(base) sorinbirchi@pop-os:~/so_demos/lab4_v2/mmap_demo$ ./map_writer 
[writer] writing to hello.txt via mmap
[writer] Message written.
(base) sorinbirchi@pop-os:~/so_demos/lab4_v2/mmap_demo$ ./map_reader 
[reader] reading from hello.txt via mmap:
hello from file

```

This demo shows the shared maping that mmap is doing on the hello.txt file. The first process writes to file and the second one reads the content and print to terminal. 


## memleak

```
cd memleak
make
```

Now run `valgrind ./memleak`. The terminal should look like this:
```
(base) sorinbirchi@pop-os:~/so_demos/lab4_v2/memleak$ valgrind ./memleak 
==128898== Memcheck, a memory error detector
==128898== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==128898== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==128898== Command: ./memleak
==128898== 
==128898== 
==128898== HEAP SUMMARY:
==128898==     in use at exit: 140 bytes in 3 blocks
==128898==   total heap usage: 3 allocs, 0 frees, 140 bytes allocated
==128898== 
==128898== LEAK SUMMARY:
==128898==    definitely lost: 20 bytes in 1 blocks
==128898==    indirectly lost: 0 bytes in 0 blocks
==128898==      possibly lost: 80 bytes in 1 blocks
==128898==    still reachable: 40 bytes in 1 blocks
==128898==         suppressed: 0 bytes in 0 blocks
==128898== Rerun with --leak-check=full to see details of leaked memory
==128898== 
==128898== For lists of detected and suppressed errors, rerun with: -s
==128898== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

It shows the memory leak of the process through valgrind.