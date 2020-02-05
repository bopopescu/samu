#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/kfifo.h>
#include"export.h"

static int __init desd_init(void)
{
	printk(KERN_INFO "%s : import_init() is called\n",THIS_MODULE->name);
	printk(KERN_INFO "%s: %d %d %d\n",THIS_MODULE->name,kfifo_size,len,avail);
	kfifo_push('S');
	printk(KERN_INFO "%s: %d %d %d\n",THIS_MODULE->name,kfifo_size,len,avail);
	kfifo_pop();
	printk(KERN_INFO "%s: %d %d %d\n",THIS_MODULE->name,kfifo_size,len,avail);
	
}

static void __exit desd_exit(void)
{
	printk(KERN_INFO "%s : import_exit() is called\n",THIS_MODULE->name);
	kfifo_pop();
	kfifo_pop();
	kfifo_pop();
	printk(KERN_INFO "%s : import_exit() is called\n",THIS_MODULE->name);
}

module_init(desd_init);
module_exit(desd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Siddhi Ghosalkar<siddhighosalkar44@gmail.com>");
MODULE_DESCRIPTION("Export Import Kernel Module");
