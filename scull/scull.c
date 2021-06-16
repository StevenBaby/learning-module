#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>

MODULE_LICENSE("Dual BSD/GPL");

static dev_t dev_first;
static const u32 dev_count = 1;
static const char *module_name = "scull";

static int scull_init(void)
{
    printk(KERN_ALERT "hello, start initialize scull!!!\n");

    alloc_chrdev_region(&dev_first, 0, dev_count, module_name);

    file_operations fo;

    return 0;
}

static void scull_exit(void)
{
    printk(KERN_ALERT "bye, scull!!!\n");
    unregister_chrdev_region(dev_first, dev_count);
}

module_init(scull_init);
module_exit(scull_exit);
