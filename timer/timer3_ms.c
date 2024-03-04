#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <errno.h>    

int delay_ms(uint32_t msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}

int main() {
   int n;
   struct timespec current_time;

   clock_gettime(CLOCK_MONOTONIC_RAW, &current_time);
   printf("%ld %ld\n", current_time.tv_sec, current_time.tv_nsec);

   for (n=0; n<10; n++)
       delay_ms(500);

   clock_gettime(CLOCK_MONOTONIC_RAW, &current_time);
   printf("%ld %ld\n", current_time.tv_sec, current_time.tv_nsec);

}


