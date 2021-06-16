# 字符驱动

scull (Simple Character Utility for Loading Localities)

scull 是一个字符驱动, 操作一块内存区域好像它是一个设备。

---

## 主次编号

- 传统上, 主编号标识设备相连的驱动
- 次编号被内核用来决定引用哪个设备

`dev_t` 类型(在 `<linux/types.h>`中定义) 用来持有设备编号，`dev_t` 是 32 位的类型, 12 位用作主编号, 20
位用作次编号。

## 一些重要的数据结构

