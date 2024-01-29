#include <stdio.h>
#include <stdint.h>  // I mean, seriously, WHY ? (This is rethorical, I know why)
#include <stdbool.h> // I get you wanna be low level, but I really don't think supporting booleans properly get in the way of that
#include <stdarg.h>  // No, really, you shouldn't need an import for this

#define no_count_sum(...) sum(sizeof((const uint32_t[]){__VA_ARGS__}) / sizeof(uint32_t), __VA_ARGS__)

uint32_t sum(uint8_t size /* This is horrible, but at least I can understand it's necessary */, ...)
{
    uint32_t total = 0;
    va_list args;
    va_start(args, size);

    for (uint8_t i = 0; i < size; i++)
    {
        total += va_arg(args, uint32_t);
    }

    va_end(args);
    return total;
}

int main()
{

    uint16_t /* `_t` ? Really ? Who thought this was a good convention, even more so IN THE STANDARD LIB ? */ a = 5;
    uint16_t b = 6;
    bool c = 5;

    if (c == true)
    {
        printf("Why does this pass ?\n");
        /* I get why this pass in any language that isn't C,
         * but in C specifically, where true is defined as 1, it shouldn't, 5 isn't equal to 1
         */
    }

    if (5 == 1)
    {
        printf("Thankfully this doesn't pass !\n");
    }

    printf("The sum of 4, 6 and 10 is %d\n", sum(3, 4, 6, 10));
    printf("The sum of 5, 7 and 11 is %d\n", no_count_sum(5, 7, 11));

    printf("Result: %d\n", a + b); // Really ? Couldn't do a println ? Even as a built-in macro ?
    return 0;
}