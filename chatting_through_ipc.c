#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX_MESSAGE_SIZE 256
#define MSG_TYPE 1

// Structure for the message
struct message {
    long mtype;
    char mtext[MAX_MESSAGE_SIZE];
};

// Function to send a message
void sendMessage(int msqid, struct message msg) {
    if (msgsnd(msqid, &msg, sizeof(struct message) - sizeof(long), 0) == -1) {
        perror("msgsnd");
        exit(1);
    }
}

// Function to receive a message
void receiveMessage(int msqid, struct message* msg, long mtype) {
    if (msgrcv(msqid, msg, sizeof(struct message) - sizeof(long), mtype, 0) == -1) {
        perror("msgrcv");
        exit(1);
    }
}

int main() {
    key_t key;
    int msqid;
    struct message msg;

    // Generate a unique key for the message queue
    key = ftok(".", 'm');

    // Create a message queue
    msqid = msgget(key, IPC_CREAT | 0666);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    // Fork a child process to handle sending and receiving messages
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process handles sending messages

        printf("Child process (Sender) started. Enter messages to send (type 'exit' to quit):\n");

        // Continuously read messages from the user and send them
        while (1) {
            // Read input from the user
            fgets(msg.mtext, sizeof(msg.mtext), stdin);

            // Remove trailing newline character
            msg.mtext[strcspn(msg.mtext, "\n")] = '\0';

            // Check if the user wants to exit
            if (strcmp(msg.mtext, "exit") == 0) {
                break;
            }

            // Set the message type
            msg.mtype = MSG_TYPE;

            // Send the message
            sendMessage(msqid, msg);
        }

        printf("Child process (Sender) exiting.\n");

        // Remove the message queue
        if (msgctl(msqid, IPC_RMID, NULL) == -1) {
            perror("msgctl");
            exit(1);
        }

        exit(0);
    } else {
        // Parent process handles receiving messages

        printf("Parent process (Receiver) started. Waiting for messages (type 'exit' to quit):\n");

        // Continuously receive messages and display them
        while (1) {
            // Receive a message
            receiveMessage(msqid, &msg, MSG_TYPE);

            // Check if the user wants to exit
            if (strcmp(msg.mtext, "exit") == 0) {
                break;
            }

            // Display the received message
            printf("Received message: %s\n", msg.mtext);
        }

        printf("Parent process (Receiver) exiting.\n");

        exit(0);
    }

    return 0;
}
