# Floats

It's recommended to append 'f' to the end of a float value:

```c
float amount = 2.52f;
```

To print a float use the "%f" placeholder, and to specify the number of digits do
`.<num_digits>%f`:

```c
printf("amount: %.2f", amount);
// amount: 2.52
```

# Directives

You don't need semicolons at the end of `#directive`s.

To define a constant you do 

```c
#define CONSTANT_NAME 7
```

You can assign expressions to constants but they must be wrapped in parentheses.

You can use constants in the body of your C file; they'll be replaced by the values in the preprocessing step.

# `main()`

You can end this with `exit(0)` if you want, instead of `return 0`.

# gcc flags

```bash
> gcc -Wall -W -pedantic -std=c99 progname.c -o progname
```
