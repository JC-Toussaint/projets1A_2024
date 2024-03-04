#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(time_t duration){
time_t stop_time = time(NULL) + duration;
for(;;) {
   time_t current_time = time(NULL);
   if (current_time>stop_time){
      break;
      }
   }
}

int main() {

for(;;) {
   delay(5);
   time_t current_time = time(NULL);
   printf("%ld \n", current_time);
   }
}


