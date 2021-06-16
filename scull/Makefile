MODULE:=scull

obj-m:=$(MODULE).o
obj-m2:=$(MODULE).ko

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

.PHONY: log
log:
	journalctl -p err -kq --no-pager -n 10
