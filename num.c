#include <stdio.h>
#include <string.h>

#define MAX_FRAME_SIZE 100

int sender(char* message, char* frame) {
    int message_size = strlen(message);
    if (message_size > MAX_FRAME_SIZE) {
        return -1; // message too large for frame
    }
    strcpy(frame, message);
    return message_size;
}

void receiver(char* frame) {
    int frame_size;
    printf("Received frame of size %d bytes: %s\n", frame_size, frame);
}

int main() {
    char message[] = "Hello, world!";
    char frame[MAX_FRAME_SIZE];
    int message_size = sender(message, frame);
    if (message_size != -1) {
        receiver(frame);
    }
    return 0;
}
