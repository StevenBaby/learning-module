# 试验 Linux 驱动程序

[试验 Linux 驱动程序 (本文件地址)](https://github.com/StevenBaby/learning-module)

## hello world

对于 Archlinux，下面说一下开发环境的配置。

首先需要更新 `linux` 和 `gcc`，如果有更新的话，需要重启。

```sh
pacman -Sy linux
pacman -Sy gcc
```

 需要安装包 `linux-headers`，

```sh
pacman -S linux-headers
```

程序原型 `hello.c`

```c
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
    printk(KERN_ALERT "hello, module!!!\n");
    return 0;
}

static void hello_exit(void)
{
    printk(KERN_ALERT "bye, the world!!!\n");
}

module_init(hello_init);
module_exit(hello_exit);
```

`makefile`

```makefile
obj-m:=hello.o
obj-m2:=hello.ko

KVERSION:=$(shell uname -r)
KDIR:=/lib/modules/$(KVERSION)/build
PWD:=$(shell pwd)

MAKE:= make
INSMOD:= insmod
RMMOD:= rmmod

modules:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

modules_install:
	$(MAKE) -C $(KDIR) M=$(PWD) modules_install

install:
	$(INSMOD) $(obj-m2)

uninstall:
	$(RMMOD) $(obj-m2)

.PHONY: clean
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
```

编译时需要 root 账号，sudo 都不行，不知道为啥！！！

