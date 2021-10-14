//   strtok test                                                               */

#include <string.h>

#define MAX_STRING_LEN  20

char *record1 = "one two three";
char *record2 = "Hello there friend";
char *p, *i;

void setup() {

   Serial.begin(9600);
   
   Serial.println("Split record1: ");
   Serial.println(subStr(record1, ' ', 1));
   Serial.println(subStr(record1, ' ', 2));
   Serial.println(subStr(record1, ' ', 3));

   Serial.println("Split record2: ");
   Serial.println(subStr(record2, ' ', 1));
   Serial.println(subStr(record2, ' ', 2));
   Serial.println(subStr(record2, ' ', 3));
}

void loop () {
}

// Function to return a substring defined by a delimiter at an index
char* subStr (char* str, char delim, int index) {
   char *act, *sub, *ptr;
   char copy[MAX_STRING_LEN];
   int i;

   // Since strtok consumes the first arg, make a copy
   strcpy(copy, str);

   for (i = 1, act = copy; i <= index; i++, act = NULL) {
      //Serial.print(".");
      sub = strtok_r(act, &delim, &ptr);
      if (sub == NULL) break;
   }
   return sub;

}
