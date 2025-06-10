#include <stdio.h>
#include <string.h>

int countBinarySubstrings(char* s) {
    int count = 0;
    int prev = 0;
    int curr = 1;

    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == s[i - 1]) {
            curr++;
        } else {
            if (prev < curr) {
                count += prev;
            } else {
                count += curr;
            }
            prev = curr;
            curr = 1;
        }
    }
    if (prev < curr) {
        count += prev;
    } else {
        count += curr;
    }

    return count;
}

int main(){
    countBinarySubstrings("00100");
}