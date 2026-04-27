---
title: "[MTK]修改屏幕最低亮度"
slug: zuidiliangdu
description: 修改屏幕最低亮度
category: tutorials
tags:
  - Android
publishedAt: 2026-04-27
updatedAt: 2026-04-27
featured: false
draft: false
accessProtected: false
---
现象：**背光进度条调至 0% ，屏幕几乎完全黑屏，看不清内容**

```c

--- a/mediatek/proprietary/packages/overlay/vendor/FrameworkResOverlay/res/values/config.xml
+++ b/mediatek/proprietary/packages/overlay/vendor/FrameworkResOverlay/res/values/config.xml
@@ -22,7 +22,7 @@
     <bool name="config_showNavigationBar">true</bool>
     <!-- Minimum screen brightness setting allowed by power manager.
     Set this to 0.0 to allow screen to go to minimal brightness.-->
-    <item name="config_screenBrightnessSettingMinimumFloat" format="float" type="dimen">0.0</item>
+    <item name="config_screenBrightnessSettingMinimumFloat" format="float" type="dimen">0.1</item>
     <!-- Maximum screen brightness allowed by the power manager.
     Set this to 1.0 for maximum brightness range.-->


```

