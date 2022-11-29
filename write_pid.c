#include <stdio.h>
#include <unistd.h>
int main(int argc, char* argv) {
    printf("pid: %d\n", getpid());
    while(1);
}