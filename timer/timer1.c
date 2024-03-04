#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

time_t duration=10;
time_t stop_time;
time_t current_time;

stop_time = time(NULL) + duration;

for(;;) {
   current_time = time(NULL);
   if (current_time>stop_time){
      stop_time=current_time + duration;
      printf("%ld \n", current_time);
      }
}

}
