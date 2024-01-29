Let's be honest, C is a mess. I'm gonna explore it to find as many informatoin that may be relevant. The final goal being to write a cheat sheet of all important information about the C language.

---

`short`, `int` and `long` are worthless remnants of retro-compatibility, `<stdint.h>` have actually useful integer types that are guarenteed to be of a fixed sized rather than depend on the compiler's mood.

For whatever reason even though `<stdbool.h>` defines `true` as `#define true 1`, any non-zero value will count as equal to `true` (i.e. `5 == true` would pass)

Including `<stdarg.h>` is necessary for variable arguments, it requires at least one normal argument too, typically one that help it tell how many variable arguments there are, we need to declare a `va_list` which is used to contain information about the variable arguments, call `va_start(list, previous_arg)` to initialize it, then call `va_arg(list, type)` to retrieve the next one, then finally `va_end(list)` for cleanup.

Due to C being C, we typically need either a sentinel value to indicate the end of var args or tell the lenght of the var args.
However this can be alleviated with a macro:
```c
#define macro_func(...) true_func(sizeof((const type[]){__VA_ARGS__}) / sizeof(type), __VA_ARGS__)
```
For the most part though, it appears variable arguments are not often going to be useful in C however, but I'll be sure of that with experience.