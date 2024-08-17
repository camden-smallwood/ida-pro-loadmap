#include <string.h>
#include "utils.h"

void pathExtensionSwitch(char *fname, const char *newext, size_t fnbuf_len)
{
    size_t len = strlen(fname);
    char *target = strrchr(fname, '.');
    char *mintarget = strpbrk(fname, ":\\/");

    if ((target == NULL) || (target <= mintarget))
        target = fname + len;

    size_t extlen = strlen(newext);

    // If end of the buffer
    if (target + extlen + 1 >= fname + fnbuf_len)
        return;

    strncpy(target, newext, extlen + 1);
}
