#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kfifo.h>
#include "export.h"

char name[50];

static int __init import_init(void)
{
	int i;
	printk(KERN_INFO "%s: import_init() is called.\n", THIS_MODULE->name);
	printk(KERN_INFO "%s (init): size = %d.\n", THIS_MODULE->name, size);
	printk(KERN_INFO "%s (init): lenght = %d.\n", THIS_MODULE->name, lenght);
	printk(KERN_INFO "%s (init): avl = %d.\n", THIS_MODULE->name, avl);
	for(i=0;i<8;i++)
	{
         kfifo_push(name[i]);
        }
	size=sizef();
	lenght=lenghtf();
	avl=avlf();
	printk(KERN_INFO "%s (init): After adding data into kfifo.\n", THIS_MODULE->name);
	printk(KERN_INFO "%s (init): size = %d.\n", THIS_MODULE->name, size);
	printk(KERN_INFO "%s (init): lenght = %d.\n", THIS_MODULE->name, lenght);
	printk(KERN_INFO "%s (init): avl = %d.\n", THIS_MODULE->name, avl);
	
	return 0;	
}

static void __exit import_exit(void)
{
        int i;
        char c;
	printk(KERN_INFO "%s:  import_exit() is called.\n", THIS_MODULE->name);
	printk(KERN_INFO "%s (exit): size = %d.\n", THIS_MODULE->name, size);
	printk(KERN_INFO "%s (exit): lenght = %d.\n", THIS_MODULE->name, lenght);
	printk(KERN_INFO "%s (exit): avl = %d.\n", THIS_MODULE->name, avl);
	for(i=0;i<3;i++)
	{
         c=kfifo_pop();
	 printk(KERN_INFO "%s: popped character = %c.\n", THIS_MODULE->name, c);
	}
	size=sizef();
	lenght=lenghtf();
	avl=avlf();
	printk(KERN_INFO "%s (exit): After Popping 3 character from kfifo.\n", THIS_MODULE->name);
	printk(KERN_INFO "%s (exit): size = %d.\n", THIS_MODULE->name, size);
	printk(KERN_INFO "%s (exit): lenght = %d.\n", THIS_MODULE->name, lenght);
	printk(KERN_INFO "%s (exit): avl = %d.\n", THIS_MODULE->name, avl);
}	

module_init( import_init);
module_exit(import_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Om Ganesh Samal");
MODULE_DESCRIPTION("DESD: LDD EXAM");

