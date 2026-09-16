# Question 1

Write a program that calls `fork()`. Before calling `fork()`, have the main
process access a variable (e.g., `x`) and set its value to something (e.g.,
`100`).

> See [q1.c](./q1.c).

What value is the variable in the child process?

> The value is `100`.

What happens to the variable when both the child and parent change the value
of `x`?

> There is no issue with this. Each process has its own memory, so when they
> set `x` they are setting their own copy of it.

# Question 2

Write a program that opens a file (with the `open()` system call) and then
calls `fork()` to create a new process.

> See [q2.c](./q2.c).

Can both the child and parent access the file descriptor returned by `open()`? 

> Yes they can. Each process gets its own copy of a file descriptor table.

What happens when they are writing to the file concurrently, i.e., at the same 
time?

> They both can write to the file. But I'm not sure how the OS has supported 
> this.

