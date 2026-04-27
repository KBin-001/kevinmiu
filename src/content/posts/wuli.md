---
title: "[MTK]修改物理分辨率"
slug: wuli
description: 修改物理分辨率
category: tutorials
tags:
  - Android
publishedAt: 2026-04-27
updatedAt: 2026-04-27
featured: false
draft: false
accessProtected: false
---
**在lk和kernel屏幕参数修改以下参数**

# vendor

```c

+#define PHYSICAL_WIDTH_MM                               (172)
+#define PHYSICAL_HEIGHT_MM                              (258)

+       params->physical_width = PHYSICAL_WIDTH_MM;
+       params->physical_height = PHYSICAL_HEIGHT_MM;


```

# kernel

```c

+#define PHYSICAL_WIDTH_MM              172
+#define PHYSICAL_HEIGHT_MM             258
+#define PHYSICAL_WIDTH_UM              (PHYSICAL_WIDTH_MM * 1000)
+#define PHYSICAL_HEIGHT_UM             (PHYSICAL_HEIGHT_MM * 1000)

+       connector->display_info.width_mm = PHYSICAL_WIDTH_MM;
+       connector->display_info.height_mm = PHYSICAL_HEIGHT_MM;


```

