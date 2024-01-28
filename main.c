#include <stdio.h>
#include <stdint.h>  // I mean, seriously, WHY ? (This is rethorical, I know why)
#include <stdbool.h> // I get you wanna be low level, but I really don't think supporting booleans properly get in the way of that

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

    printf("Result: %d\n", a + b); // Really ? Couldn't do a println ? Even as a built-in macro ?
    return 0;
}