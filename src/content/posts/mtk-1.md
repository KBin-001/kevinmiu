---
title: "[MTK]去除功放音效文件"
slug: "[MTK]去除功放音效文件"
description: "[MTK]去除功放音效文件"
category: tutorials
tags:
  - Android
publishedAt: 2026-04-25
updatedAt: 2026-04-25
featured: false
draft: false
---
# 软件编译去除音效文件

## 把lib、[lib64里面的awinic.audio.effect.so](http://lib64里面的awinic.audio.effect.so)去除

```c
deleted:    mediateksample/aiot8391p2_64_bsp/aw87391/lib/awinic.audio.effect.so
deleted:    mediateksample/aiot8391p2_64_bsp/aw87391/lib64/awinic.audio.effect.so

```

## mediateksample/aiot8391p2_64_bsp/[device-vext.mk](http://device-vext.mk)注释掉

```c
+#PRODUCT_COPY_FILES += $(LOCAL_PATH)/aw87391/lib/awinic.audio.effect.so:$(TARGET_COPY_OUT_VENDOR)/lib/hw/awinic.audio.effect.so
+#PRODUCT_COPY_FILES += $(LOCAL_PATH)/aw87391/lib64/awinic.audio.effect.so:$(TARGET_COPY_OUT_VENDOR)/lib64/hw/awinic.audio.effect.so

```

