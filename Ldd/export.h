#ifndef __EXPORT_H
#define __EXPORT_H

extern int kfifo_size;
extern int len;
extern int avail;
void kfifo_push(char ch);
char kfifo_pop(void);

#endif

