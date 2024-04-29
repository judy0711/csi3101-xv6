// Test that fork fails gracefully.
// Tiny executable so that the limit can be filling the proc table.

#include "types.h"
#include "stat.h"
#include "user.h"

int atoi_custom(const char *str) {
    int result = 0; 
    int sign = 1; 
    int i = 0;

    if (str[0] == '-') {
        sign = -1;
        i++;
    }
    else if (str[0] == '+') {
        i++;
    }

    while (str[i] != '\0') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;
}

int
main(int argc, char *argv[])
{
  nice(atoi_custom(argv[1]));

  exit();
}
