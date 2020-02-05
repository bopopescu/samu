#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>
#include<linux/kfifo.h>

int kfifo_size=1024;
module_param(kfifo_size,int,0644);
int len=0;
int avail=0;

struct kfifo myfifo;

void kfifo_push(char ch)
{
	printk(KERN_INFO "%s : kfifo_push() is called\n",THIS_MODULE->name);
	if(!(kfifo_is_full(&myfifo)))
	{
		ch=kfifo_in(&myfifo,ch,1);
		printk(KERN_INFO "%s : char is addeed\n",THIS_MODULE->name);
	}
	printk(KERN_INFO "%s : myfifo is full\n",THIS_MODULE->name);

}

char kfifo_pop(void)
{
	char ch;
	printk(KERN_INFO "%s : kfifo_pop() is called\n",THIS_MODULE->name);
	if(!(kfifo_is_empty(&myfifo)))
	{
		ch=kfifo_out(&myfifo,ch,1);
		printk(KERN_INFO "%s : char is removed.\n",THIS_MODULE->name);
	}
	printk(KERN_INFO "%s : myfifo is empty\n",THIS_MODULE->name);
	return ch;


}

static int __init export_init(void)
{
	int ret;
	printk(KERN_INFO "%s : export_init() is called\n",THIS_MODULE->name);
	ret=kfifo_alloc(&myfifo,kfifo_size,GFP_KERNEL);
	if(ret != 0)
	{
		printk(KERN_INFO "%s kfifo_alloc() is failed\n",THIS_MODULE->name);
		return -1;
	}
	
	if(kfifo_size(&myfifo) > 1024)
	{
		printk(KERN_INFO "%s : Error.Size is more than 1024\n",THIS_MODULE->name);
		
	}

	kfifo_push('A');
	kfifo_pop();
	return 0;
}

static void __exit export_exit(void)
{
	printk(KERN_INFO "%s : export_exit() is called\n",THIS_MODULE->name);
	kfifo_size=kfifo_size(&myfifo);
	len=kfifo_len(&myfifo);
	avail=kfifo_avail(&myfifo);
	printk(KERN_INFO "%s: %d %d %d\n",THIS_MODULE->name,kfifo_size,len,avail);
}

EXPORT_SYMBOL(kfifo_size);
EXPORT_SYMBOL(len);
EXPORT_SYMBOL(avail);
EXPORT_SYMBOL(kfifo_push);
EXPORT_SYMBOL(kfifo_pop);

module_init(export_init);
module_exit(export_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Siddhi Ghosalkar<siddhighosalkar44@gmail.com>");
MODULE_DESCRIPTION("Export Import Kernel Module");

