#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>


int main(void){
int file;
ssize_t write_size;
char * buf = "hello world\n";
char * buf_out[256];
int close;
size_t read_size;

file = open("/dev/sleepy0", O_RDWR);
write_size = write(file, buf, sizeof(buf));
read_size = read(file, buf_out, sizeof(buf_out));
close(file);

printf("%s\n", buf_out);

return 0;
}
