Let's be honest, C is a mess. I'm gonna explore it to find as many informatoin that may be relevant. The final goal being to write a cheat sheet of all important information about the C language.

---

`short`, `int` and `long` are worthless remnants of retro-compatibility, `<stdint.h>` have actually useful integer types that are guarenteed to be of a fixed sized rather than depend on the compiler's mood.

For whatever reason even though `<stdbool.h>` defines `true` as `#define true 1`, any non-zero value will count as equal to `true` (i.e. `5 == true` would pass)