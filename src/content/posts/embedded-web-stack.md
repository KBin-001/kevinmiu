---
title: 指令速查手册
slug: zhilin
description: 指令速查手册
category: tutorials
tags:
  - Android
  - 开发者
  - 编程
  - 命令行
publishedAt: 2026-04-23
updatedAt: 2026-04-23
featured: true
draft: false
accessProtected: true
accessPassword: kb
cover: /images/chatgpt-image-2026423-175652.png
---
# 📋 指令速查手册

> 涵盖 ADB、Git、Repo、ESP-IDF、环境配置等常用指令，按场景分类整理。

---

## 📱 一、ADB 常用命令

### 1.1 安装应用

```bash
# 绕过低版本 SDK 限制安装
adb install --bypass-low-target-sdk-block xxx.apk

# 示例
adb install --bypass-low-target-sdk-block chuanganqi.apk
adb install --bypass-low-target-sdk-block QQ.apk

```

### 1.2 查看传感器服务

```bash
adb shell dumpsys sensorservice
adb shell pm list features

```

### 1.3 查看设备信息

```bash
# 进入 shell
adb shell
su
getevent

# 查看安卓版本
cat sys/out_system/target/product/ussi_arm64/system/build.prop | grep "ro.build.version"

# 查询 TP 参数
adb shell
su
cd /proc/android_touch

# 查询 UFS 型号
adb shell "cat /sys/class/block/sda/device/model"   # 查询 ID
adb shell "cat /sys/class/block/sda/device/vendor"  # 查询厂商

```

### 1.4 查看 Vendor 版本（SDK 级别）

```bash
adb shell getprop ro.build.version.sdk
adb shell getprop ro.vendor.api_level

```


| **SDK** | **Android 版本** |
| ------- | -------------- |
| 33 | Android 13 |
| 34 | Android 14 |
| 35 | Android 15 |


### 1.5 Push 固件文件

```bash
adb push wcnmodem.bin /odm/firmware/
adb shell ls -lZ /odm/firmware/wcnmodem.bin

adb push Himax_firmware.bin /vendor/firmware/Himax_firmware.bin
adb shell ls -li /vendor/firmware/Himax_firmware.bin

```

### 1.6 TP 解锁 / Remount

```bash
adb reboot bootloader
fastboot flashing unlock
fastboot reboot
adb root
adb remount

```

### 1.7 查询指南针服务与缓存清理

```bash
# 查询指南针是否有服务
adb shell "pm list features | grep compass"

# 删除指南针缓存
rm -f out/target/product/*/vendor/etc/permissions/handheld_core_hardware.xml
rm -f out/target/product/*/system/etc/permissions/handheld_core_hardware.xml

```

### 1.7 ADB 抓取日志分析

```bash
#先清空
adb logcat -c

#把设备当前开始输出的所有 logcat 日志，按带时间和线程信息的格式，持续保存到本地文件 camera_intents_fail_pass.txt 里。

adb logcat -b all -v threadtime > camera_intents_fail_pass.txt

adb logcat

从 Android 设备读取日志。

-b all

抓 所有 buffer 的日志。
也就是不只 main，还包括 system、crash、events 等。

如果不加这个，默认通常只看一部分日志。
你这个场景是 CTS 异常流程，抓 all 更稳。

```

---

## 🐛 二、调试与日志

### 2.1 启动 MTK Log

```bash
# 打开 debug logger
adb shell am start -n com.debug.loggerui/com.debug.loggerui.MainActivity

# 打开 MTK logger
adb shell am start -n com.mediatek.mtklogger/com.mediatek.mtklogger.MainActivity

# 用 adb 拉取日志到电脑
adb pull /data/debuglogger C:\\Users\\PC\\mtklog_backup

echo 1 > /sys/class/misc/scp/scp_mobile_log
while true;do cat /dev/scp;done

adb shell dumpsys sensorservice

```

### 2.2 Dmesg 日志

```bash
# 抓取 SCP 日志
adb shell "dmesg | grep -i scp"

# 查看 sensorhub 相关日志
adb root
adb shell "dmesg | grep -iE 'sensorhub|sipc'"

```

### 2.3 Gsensor 调试

```bash
# 打印 gsensor 日志
adb root
adb shell "cat /dev/slog_ch"

# 实时打印 gsensor
adb root
adb shell
echo "4 2" > /sys/class/sprd_sensorhub/sensor_hub/logctl
logcat | grep SensorHub

```

### 2.4 读取 TP 固件信息

```bash
adb shell
su
cd proc/android_touch/
cat vendor

# 示例输出：
# IC = HX83102J
# FW_VER = 0x8403
# TOUCH_VER = 0xA5
# DISPLAY_VER = 0xD1
# CID_VER = 0x6001
# PANEL_VER = 0x38
# Cusomer = Lecoo
# Project = T8123

```

### 2.5 查看 GPIO 与霍尔传感器

```bash
# 查看所有 GPIO 信息
cat /sys/kernel/debug/gpio
cat /sys/kernel/debug/pinctrl/*/pins

# 霍尔传感器相关
lsmod | grep hall
cat /proc/interrupts | grep hall
dmesg -w | grep hall

```

### 2.6 查看内核模块与振动器配置

```bash
# 查看 aw87 相关打印
dmesg | grep aw87
i2cdetect -y 2

# 读取内核振动器编译配置
zcat /proc/config.gz | grep VIBRATOR

# 查找 hall 驱动模块
find out/ -name "hall*.ko"

```

### 2.7 Camera Luma 控制

```bash
echo 1 > /sys/devices/platform/gc6133_luma/camera2_luma
cat /sys/devices/platform/gc6133_luma/camera2_luma

```

### 2.8 展锐 YLog 抓取流程

```bash
# 进入工程模式
adb shell am start -n com.sprd.engineermode/.EngineerModeActivity
# 在工程模式中选择 DEBUG&LOG > YLog，开始抓取

# 导出 YLog
adb pull /data/ylog C:\\ylog_export

# 抓取 ALS / PS 原始数据
cat raw_data_als
cat raw_data_ps

```

### 2.9 抓取 Tarng（Perfetto Trace）

```bash
adb shell content query --uri content://com.android.traceur.documents/document/traces/children

# 示例导出
adb shell content read --uri content://com.android.traceur.documents/document/traces:trace-ums9360_y2-BP2A.250605.031.A3-2025-12-12-18-31-14.perfetto-trace > trace.perfetto-trace

```

### 2.10 Audio Dump（PCM / AudioFlinger）

```bash
# 打开状态栏秒针显示
adb root
adb remount
adb shell pm enable com.android.systemui/com.android.systemui.tuner.TunerActivity
adb shell am start -n com.android.systemui/com.android.systemui.tuner.TunerActivity

# A11-A14：开启 PCM dump
adb root
adb remount
adb shell setenforce 0
adb shell setprop af.media.audiofw.devices.dump 0xffffff
adb shell setprop af.media.audiofw.dump 0xffffff
adb shell setprop persist.audio.pcm_dump true
adb shell setprop log.tag.APM_AudioPolicyManager V
adb shell stop audioserver
adb shell start audioserver
# DUMP 文件路径：/data/vendor/local/media/

# A15：开启 PCM dump
adb root
adb remount
adb shell setenforce 0
adb shell setprop af.media.audiofw.dump 0xff
adb shell setprop persist.vendor.audio.pcm_dump 0x7f
adb shell setprop log.tag.APM_AudioPolicyManager V
adb shell stop audioserver
adb shell start audioserver
# DUMP 文件路径：/data/ylog/audio/media/

# AudioPolicy / AudioFlinger dump
adb shell dumpsys media.audio_flinger > af.txt
adb shell dumpsys media.audio_policy > ap.txt

```

---

## 🌿 三、Git 操作

### 3.1 基础操作

```bash
# 查看当前状态
git status

# 查看文件差异
git diff (具体文件路径)

# 查看分支
git branch -a

# 查看提交历史
git log
git log --author="你的名字"
git log --grep="bug fix"       # 关键词筛选
git log -n 10                  # 只显示最近 10 条
git log --oneline              # 单行显示
git log --graph --oneline --all  # 图形化显示分支

# 查看具体提交的详细信息
git show --raw (commit-id)

```

### 3.2 暂存与推送

```bash
# 处理 Pull 冲突
git stash          # 暂存本地修改
git pull           # 拉取远程代码
git stash pop      # 恢复之前的修改

# 重新推送
git push

# 创建远程分支（示例 c50）
git push -u mt8391-u c50

# 把 add 的文件退回工作区
git reset HEAD (文件名)

# 将暂存区退回工作区
git reset

```

### 3.3 Commit 管理

```bash
# 覆盖 commit 描述
git commit --amend -m "(描述)"

# Cherry-pick（跨分支同步提交）
git cherry-pick 19a6d8e37f1ca035dbba6b785256748c6b471a2f

#放弃这次 cherry-pick：
git cherry-pick --abort

# 撤销某个 commit（保留历史）
git revert (commit的id)

# 回滚到某个 commit（强制，不保留历史）
git reset --hard 1150ee6996cec0144dab568732e579406289370c^

# 强制推送
git push -f
git push --force mt8391-u kp1202_huion

```

### 3.4 比较差异并导出

```bash
# 比较工作区与暂存区
git diff > my_changes.diff

# 比较暂存区与最新提交 (HEAD)
git diff --staged > staged_changes.patch

# 比较两个提交之间的差异
git diff <commit-id-1> <commit-id-2> > commit_compare.diff

# 比较当前分支与另一个分支
git diff main..feature-branch > branch_diff.diff

```

### 3.5 Patch 操作

```bash
# 生成 patch
git format-patch -1 <commit id>

# 应用 patch
git apply --reject <patch文件>

# 移动 patch 文件
mv 0001-remove-compass.patch /blue/zengkaibin/kp1202_v16/mt8391_u/device/

```

### 3.6 用服务器版本解决冲突

```bash
git checkout --theirs \\
mediatek/proprietary/bootable/bootloader/preloader/custom/aiot8391p2_64_bsp/dct/dct/codegen.dws

git checkout --theirs \\
mediatek/proprietary/tools/dct/dws/mt8189/aiot8391p2_64_bsp.dws

git add \\
mediatek/proprietary/bootable/bootloader/preloader/custom/aiot8391p2_64_bsp/dct/dct/codegen.dws

git add \\
mediatek/proprietary/tools/dct/dws/mt8189/aiot8391p2_64_bsp.dws

```

---

## 🔀 四、分支与 Repo 管理

### 4.1 分支切换

```bash
# 切到子分支 c13t
git checkout -b c13t ums9360-ker/c13t

# 切换并追踪远程分支
git checkout -b a3 mt8391-u/a3
git checkout -b kp1202 mt8391-u/kp1202
git checkout -b a16 ums9360-ker-a16/master

# 更新远程分支
git fetch --all

# 推送代码到远程
git push origin c13t

```

### 4.2 Repo 管理

```bash
# 初始化并同步
./.repo/repo/repo init -m ums9360-vnd.xml
./.repo/repo/repo sync -j32

# 上传代码审核
./.repo/repo/repo upload

# 全部切换到 master
repo forall -c "git checkout master"

# 查看分支
../../repo/repo branch

# 查看所有项目当前分支
./.repo/repo/repo forall -c 'echo $REPO_PATH: $(git rev-parse --abbrev-ref HEAD)'

# 查看最后一次提交
./.repo/repo/repo forall -c 'echo $REPO_PATH: $(git log -1 --oneline)'

# 切换到 master 分支（绝对路径）
/blue/zengkaibin/bin/repo forall -p -c 'git checkout master'

# 批量切换到 c13t 分支
../../repo/repo forall -c 'git checkout c13t 2>/dev/null || git checkout -b c13t ums9360-ker/c13t 2>/dev/null || echo "[$REPO_PATH] no c13t"'

# 查看所有项目的当前分支（另一种写法）
repo forall -c 'echo "$REPO_PATH : $(git rev-parse --abbrev-ref HEAD)"'

```

---

## 🔄 五、文件批量操作

### 5.1 批量重命名与替换内容

```bash
# 示例：从 ov8856 更改到 gc08a3

# 批量改文件名
rename 's/ov8856/gc08a3/' ./*ov8856*
rename 's/ov8856/gc08a3/' ./*/*ov8856*

# 批量改文件内容
sed -i "s/OV8856/GC08A3/g" `grep OV8856 -rl ./`
sed -i "s/ov8856/gc08a3/g" `grep ov8856 -rl ./`

```

### 5.2 更新时间戳

```bash
# 更新指定目录下所有文件的时间戳
find mediatek/proprietary/custom/mt8189/hal/imgsensor/ver1/ov16880_mipi_raw/ -type f -exec touch {} +

```

### 5.3 清理未追踪文件

```bash
# 查看 git status 里的 Untracked files
git status

# 先预览会删什么（不实际删除）
git clean -n -d

```

---

## 💾 六、刷镜像（VTS 测试）

```bash
# 重启到 bootloader
adb reboot bootloader

# 解锁 flashing（按一下音量 -，进入模式）
fastboot flashing unlock

# 刷入镜像
fastboot flash vendor_boot vendor_boot-debug.img    # 替换为自己打包的 img
fastboot flash preloader_a preloader_aiot8391p2_64_bsp_SBOOT_DIS.bin
fastboot reboot fastboot
fastboot flash system_a system.img
fastboot reboot

```

---

## ⚙️ 七、环境配置

### 7.1 Lunch 编译环境

```bash
# 在 bsp 目录下设置环境
source build/envsetup.sh
lunch
# 选择对应产品，例如：full_tb8788p1_64_bsp-userdebug

```

### 7.2 ESP-IDF 环境

```bash
# 在 esp-idf 路径下执行
source ./export.sh

# 常用构建命令
idf.py fullclean
idf.py build
rm -rf build

# 搜索目标芯片的配置
grep "CONFIG_IDF_TARGET" sdkconfig

# 设置目标芯片
idf.py set-target esp32c5

# 打开菜单配置
idf.py menuconfig

```

### 7.3 Python 环境切换（conda）

```bash
# 激活 Python2 环境（用于 repo）
conda activate py2_repo

# 退出当前环境
conda deactivate

# 回到 base 环境
conda activate base

```

---

