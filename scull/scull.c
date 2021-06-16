#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int scull_init(void)
{
    printk(KERN_ALERT "hello, scull!!!\n");
    return 0;
}

static void scull_exit(void)
{
    printk(KERN_ALERT "bye, scull!!!\n");
}

module_init(scull_init);
module_exit(scull_exit);
