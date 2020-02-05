#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kfifo.h>


int kfifo_size = 1024;

int size,lenght,avl;

module_param(kfifo_size, int, 0644);

struct kfifo fifo;

void kfifo_push(char ch)
{ 
 kfifo_in(&fifo, &ch, 1);
}

char kfifo_pop(void)
{
  char ch;
  kfifo_out(&fifo, &ch, 1);
  return ch;
}

int lenghtf()
{
 lenght=kfifo_len(&fifo);
 return lenght;
}

int sizef()
{
 size=kfifo_size(&fifo);
 return size;
}

int avlf()
{
 avl=kfifo_avail(&fifo);
 return avl;
}

static int __init my_init(void)
{
        int ret;
	printk(KERN_INFO "%s: my_init() is called.\n", THIS_MODULE->name);
	ret = kfifo_alloc(&fifo, kfifo_size, GFP_KERNEL);
	if(ret != 0)
	{
		printk(KERN_INFO "kfifo_alloc() failed.");
		return -ENOMEM;
	}
	size=kfifo_size(&fifo);
	lenght=kfifo_len(&fifo);
	avl=kfifo_avail(&fifo);
	printk(KERN_INFO "%s (init): Before adding data into kfifo.\n", THIS_MODULE->name);
	printk(KERN_INFO "%s (init): kfifo_size() = %d.\n", THIS_MODULE->name, size);
	printk(KERN_INFO "%s (init): kfifo_len() = %d.\n", THIS_MODULE->name, lenght);
	printk(KERN_INFO "%s (init): kfifo_avail() = %d.\n", THIS_MODULE->name, avl);
	
	return 0;	
}

static void __exit my_exit(void)
{
	printk(KERN_INFO "%s (exit): my_exit() is called.\n", THIS_MODULE->name);
	printk(KERN_INFO "%s (exit): kfifo_size() = %d.\n", THIS_MODULE->name, size);
	printk(KERN_INFO "%s (exit): kfifo_len() = %d.\n", THIS_MODULE->name, lenght);
	printk(KERN_INFO "%s (exit): kfifo_avail() = %d.\n", THIS_MODULE->name, avl);
}


EXPORT_SYMBOL(size);
EXPORT_SYMBOL(avl);
EXPORT_SYMBOL(lenght);
EXPORT_SYMBOL(kfifo_push);
EXPORT_SYMBOL(kfifo_pop);
EXPORT_SYMBOL(sizef);
EXPORT_SYMBOL(avlf);
EXPORT_SYMBOL(lenghtf);

module_init(my_init);
module_exit(my_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Om Ganesh Sanal");
MODULE_DESCRIPTION("DESD: LDD EXAM");
 
