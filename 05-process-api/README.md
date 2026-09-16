# Question 1

See [q1.c](./q1.c).

The value in the child is `100`.

What happens to the variable when both the child and parent change the value
of `x`?

There is no issue with the parent and the child both changing the value of `x`.
Each process has its own memory, so when they set `x` they are setting their
own copy of it.

# Question 2

See [q2.c](./q2.c).

Yes both the child and parent access the file descriptor returned by open.
Each process gets its own copy of a file descriptor table.

[review]
I'm not sure what happens when both processes write to the file concurrently.
It appears that this works and the parent and child programs run
non-deterministically.

## Aside

An interesting side note about this question is the creation of the file. I 
wanted to create a file say `/tmp/nums.txt` in the program through the use of 
`execlp` like this.

```c
execlp("touch", "touch", "/tmp/nums.txt", (char*) NULL);
int rc = fork();
// rest of code
```

This is actually incorrect since `execlp` never returns unless an error occurs.

# Question 3

See [q3.c](./q3.c).

The most straightforward way to get the parent to run after the child is to use
`wait`. I initially tried using a spinlock to the effect of something like this

```c
int rc = fork()
int done = 0;
if (rc == 0) {
    done = 1;
    printf("child\n");
} else if (rc > 0) {
    while (done == 0);
    printf("parent\n");
}
```

This should work. If the parent runs first the CPU just does busy work
computing the false-evaluating loop. The child will be scheduled to run and
eventually terminate and `done` will be set.

It doesn't work in practice though because each process gets its own memory.

To get the parent to run after the child without using `wait()` you need a
spinlock with process-shared memory, signals or higher-order OS techniques.

# Question 4
