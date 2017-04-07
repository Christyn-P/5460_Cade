/**
   Hello.
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
 
#define BUFFER_LENGTH 256               ///< The buffer length (crude but fine)
static char receive[BUFFER_LENGTH];     ///< The receive buffer from the LKM
 
int main(){
   int ret, fd, sendy;
   char stringToSend[BUFFER_LENGTH];
   printf("Starting device test code example...\n");
   fd = open("/dev/sleepy0", O_RDWR);             // Open the device with read/write access
   if (fd < 0){
      perror("Failed to open the device...");
      return errno;
   }
   printf("Type in a short string to send to the kernel module:\n"); 
   scanf("%[^\n]%*c", stringToSend);
   sendy = atoi(stringToSend);
   printf("Writing message to the device [%d].\n", sendy);
   ret = write(fd, &sendy, sizeof(sendy)); // Send the string to the LKM
   printf("Reading from the device...\n");
   printf("Time left: %d\n", ret/100);
   ret = read(fd, receive, BUFFER_LENGTH);        // Read the response from the LKM
   printf("End of the program\n");
   return 0;
}
