From 0268038fbc1e9227da22f32d2ea56048a742804b Mon Sep 17 00:00:00 2001
From: xiejihua <jihua.xie@zlintek.com>
Date: Sat, 18 Oct 2025 10:25:34 +0800
Subject: [PATCH] =?UTF-8?q?=E7=A7=BB=E9=99=A4=E6=A8=A1=E6=8B=9F=E8=80=B3?=
 =?UTF-8?q?=E6=9C=BA=E9=85=8D=E7=BD=AE=EF=BC=8C=E8=AE=BE=E5=A4=87=E4=B8=8D?=
 =?UTF-8?q?=E6=94=AF=E6=8C=81=E6=A8=A1=E6=8B=9F=E8=80=B3=E6=9C=BA?=
MIME-Version: 1.0
Content-Type: text/plain; charset=UTF-8
Content-Transfer-Encoding: 8bit

---
 .../audio_policy_configuration.xml                 | 37 +++-------------------
 ..._policy_configuration_a2dp_offload_disabled.xml | 29 +++--------------
 ...figuration_a2dp_offload_disabled_cg_enabled.xml | 31 +++---------------
 ...configuration_a2dp_offload_enable_cg_enable.xml | 31 +++---------------
 ...o_policy_configuration_bluetooth_legacy_hal.xml | 23 +-------------
 .../usb_audio_policy_configuration.xml             |  0
 .../audio_policy_configuration.xml                 | 31 +++---------------
 ...o_policy_configuration_bluetooth_legacy_hal.xml | 19 +----------
 .../usb_audio_policy_configuration.xml             |  0
 9 files changed, 24 insertions(+), 177 deletions(-)
 mode change 100644 => 100755 mediatek/mt8189/audio_policy_config/audio_policy_configuration.xml
 mode change 100644 => 100755 mediatek/mt8189/audio_policy_config/audio_policy_configuration_a2dp_offload_disabled.xml
 mode change 100644 => 100755 mediatek/mt8189/audio_policy_config/audio_policy_configuration_a2dp_offload_disabled_cg_enabled.xml
 mode change 100644 => 100755 mediatek/mt8189/audio_policy_config/audio_policy_configuration_a2dp_offload_enable_cg_enable.xml
 mode change 100644 => 100755 mediatek/mt8189/audio_policy_config/audio_policy_configuration_bluetooth_legacy_hal.xml
 mode change 100644 => 100755 mediatek/mt8189/audio_policy_config/usb_audio_policy_configuration.xml
 mode change 100644 => 100755 mediatek/vendor/common/audio_policy_config/audio_policy_configuration.xml
 mode change 100644 => 100755 mediatek/vendor/common/audio_policy_config/audio_policy_configuration_bluetooth_legacy_hal.xml
 mode change 100644 => 100755 mediatek/vendor/common/audio_policy_config/usb_audio_policy_configuration.xml

diff --git a/mediatek/mt8189/audio_policy_config/audio_policy_configuration.xml b/mediatek/mt8189/audio_policy_config/audio_policy_configuration.xml
old mode 100644
new mode 100755
index 0097eaf..b559edb
--- a/mediatek/mt8189/audio_policy_config/audio_policy_configuration.xml
+++ b/mediatek/mt8189/audio_policy_config/audio_policy_configuration.xml
@@ -126,18 +126,6 @@
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
                 </devicePort>
-                <devicePort tagName="Wired Headset" type="AUDIO_DEVICE_OUT_WIRED_HEADSET" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
-                <devicePort tagName="Wired Headphones" type="AUDIO_DEVICE_OUT_WIRED_HEADPHONE" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
                 <devicePort tagName="HDMI" type="AUDIO_DEVICE_OUT_AUX_DIGITAL" role="sink">
                     <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
                              samplingRates="8000 11025 16000 22050 32000 44100 48000 64000 88200 96000 128000 176400 192000"
@@ -158,12 +146,6 @@
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="8000 16000" channelMasks="AUDIO_CHANNEL_OUT_MONO"/>
                 </devicePort>
-                <devicePort tagName="Analog Dock Headset" type="AUDIO_DEVICE_OUT_ANLG_DOCK_HEADSET" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
                 <devicePort tagName="Digital Dock Headset" type="AUDIO_DEVICE_OUT_DGTL_DOCK_HEADSET" role="sink">
                     <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
                              samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
@@ -180,11 +162,6 @@
                              samplingRates="8000 16000 32000 44100 48000"
                              channelMasks="AUDIO_CHANNEL_IN_MONO AUDIO_CHANNEL_IN_STEREO"/>
                 </devicePort>
-                <devicePort tagName="Wired Headset Mic" type="AUDIO_DEVICE_IN_WIRED_HEADSET" role="source">
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="8000 16000 32000 44100 48000"
-                             channelMasks="AUDIO_CHANNEL_IN_MONO AUDIO_CHANNEL_IN_STEREO"/>
-                </devicePort>
                 <devicePort tagName="BT SCO Headset Mic" type="AUDIO_DEVICE_IN_BLUETOOTH_SCO_HEADSET" role="source">
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="8000 16000" channelMasks="AUDIO_CHANNEL_IN_MONO"/>
@@ -209,30 +186,24 @@
             <routes>
                 <route type="mix" sink="Speaker"
                        sources="primary_output,deep_buffer,mmap_no_irq_out,fast,voip_rx"/>
-                <route type="mix" sink="Wired Headset"
-                       sources="primary_output,deep_buffer,mmap_no_irq_out,fast,voip_rx"/>
-                <route type="mix" sink="Wired Headphones"
-                       sources="primary_output,deep_buffer,mmap_no_irq_out,fast,voip_rx"/>
                 <route type="mix" sink="BT SCO"
                        sources="primary_output,deep_buffer,fast,voip_rx"/>
                 <route type="mix" sink="BT SCO Headset"
                        sources="primary_output,deep_buffer,fast,voip_rx"/>
                 <route type="mix" sink="BT SCO Car Kit"
                        sources="primary_output,deep_buffer,fast,voip_rx"/>
-                <route type="mix" sink="Analog Dock Headset"
-                       sources="primary_output"/>
                 <route type="mix" sink="Digital Dock Headset"
                        sources="primary_output"/>
                 <route type="mix" sink="HDMI"
                        sources="hdmi_mix_output,primary_output,deep_buffer,fast,voip_rx"/>
                 <route type="mix" sink="primary input"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In"/>
                 <route type="mix" sink="mmap_no_irq_in"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic"/>
+                       sources="Built-In Mic,Built-In Back Mic"/>
                 <route type="mix" sink="voip_tx"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In"/>
                 <route type="mix" sink="fast input"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In"/>
                 <route type="mix" sink="line input"
                        sources="Line In"/>
             </routes>
diff --git a/mediatek/mt8189/audio_policy_config/audio_policy_configuration_a2dp_offload_disabled.xml b/mediatek/mt8189/audio_policy_config/audio_policy_configuration_a2dp_offload_disabled.xml
old mode 100644
new mode 100755
index 72a4829..2b3f79a
--- a/mediatek/mt8189/audio_policy_config/audio_policy_configuration_a2dp_offload_disabled.xml
+++ b/mediatek/mt8189/audio_policy_config/audio_policy_configuration_a2dp_offload_disabled.xml
@@ -126,18 +126,6 @@
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
                 </devicePort>
-                <devicePort tagName="Wired Headset" type="AUDIO_DEVICE_OUT_WIRED_HEADSET" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
-                <devicePort tagName="Wired Headphones" type="AUDIO_DEVICE_OUT_WIRED_HEADPHONE" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
                 <devicePort tagName="HDMI" type="AUDIO_DEVICE_OUT_AUX_DIGITAL" role="sink">
                     <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
                              samplingRates="8000 11025 16000 22050 32000 44100 48000 64000 88200 96000 128000 176400 192000"
@@ -180,11 +168,6 @@
                              samplingRates="8000 16000 32000 44100 48000"
                              channelMasks="AUDIO_CHANNEL_IN_MONO AUDIO_CHANNEL_IN_STEREO"/>
                 </devicePort>
-                <devicePort tagName="Wired Headset Mic" type="AUDIO_DEVICE_IN_WIRED_HEADSET" role="source">
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="8000 16000 32000 44100 48000"
-                             channelMasks="AUDIO_CHANNEL_IN_MONO AUDIO_CHANNEL_IN_STEREO"/>
-                </devicePort>
                 <devicePort tagName="BT SCO Headset Mic" type="AUDIO_DEVICE_IN_BLUETOOTH_SCO_HEADSET" role="source">
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="8000 16000" channelMasks="AUDIO_CHANNEL_IN_MONO"/>
@@ -209,10 +192,6 @@
             <routes>
                 <route type="mix" sink="Speaker"
                        sources="primary output,deep_buffer,mmap_no_irq_out,fast,voip_rx"/>
-                <route type="mix" sink="Wired Headset"
-                       sources="primary output,deep_buffer,mmap_no_irq_out,fast,voip_rx"/>
-                <route type="mix" sink="Wired Headphones"
-                       sources="primary output,deep_buffer,mmap_no_irq_out,fast,voip_rx"/>
                 <route type="mix" sink="BT SCO"
                        sources="primary output"/>
                 <route type="mix" sink="BT SCO Headset"
@@ -226,13 +205,13 @@
                 <route type="mix" sink="HDMI"
                        sources="hdmi_mix_output"/>
                 <route type="mix" sink="primary input"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In"/>
                 <route type="mix" sink="mmap_no_irq_in"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic"/>
+                       sources="Built-In Mic,Built-In Back Mic"/>
                 <route type="mix" sink="voip_tx"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In"/>
                 <route type="mix" sink="fast input"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In"/>
                 <route type="mix" sink="line input"
                        sources="Line In"/>
             </routes>
diff --git a/mediatek/mt8189/audio_policy_config/audio_policy_configuration_a2dp_offload_disabled_cg_enabled.xml b/mediatek/mt8189/audio_policy_config/audio_policy_configuration_a2dp_offload_disabled_cg_enabled.xml
old mode 100644
new mode 100755
index 658ce6e..e037d62
--- a/mediatek/mt8189/audio_policy_config/audio_policy_configuration_a2dp_offload_disabled_cg_enabled.xml
+++ b/mediatek/mt8189/audio_policy_config/audio_policy_configuration_a2dp_offload_disabled_cg_enabled.xml
@@ -147,18 +147,6 @@
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
                 </devicePort>
-                <devicePort tagName="Wired Headset" type="AUDIO_DEVICE_OUT_WIRED_HEADSET" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
-                <devicePort tagName="Wired Headphones" type="AUDIO_DEVICE_OUT_WIRED_HEADPHONE" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
                 <devicePort tagName="HDMI" type="AUDIO_DEVICE_OUT_AUX_DIGITAL" role="sink">
                     <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
                              samplingRates="8000 11025 16000 22050 32000 44100 48000 64000 88200 96000 128000 176400 192000"
@@ -217,11 +205,6 @@
                              samplingRates="8000 16000 32000 44100 48000"
                              channelMasks="AUDIO_CHANNEL_IN_MONO AUDIO_CHANNEL_IN_STEREO"/>
                 </devicePort>
-                <devicePort tagName="Wired Headset Mic" type="AUDIO_DEVICE_IN_WIRED_HEADSET" role="source">
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="8000 16000 32000 44100 48000"
-                             channelMasks="AUDIO_CHANNEL_IN_MONO AUDIO_CHANNEL_IN_STEREO"/>
-                </devicePort>
                 <devicePort tagName="BT SCO Headset Mic" type="AUDIO_DEVICE_IN_BLUETOOTH_SCO_HEADSET" role="source">
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="8000 16000" channelMasks="AUDIO_CHANNEL_IN_MONO"/>
@@ -300,10 +283,6 @@
                        sources="primary output,deep_buffer,voip_rx,mmap_no_irq_out,fast,Voice Call In"/>
                 <route type="mix" sink="Speaker"
                        sources="primary output,deep_buffer,mmap_no_irq_out,fast,compress_offload,FM Tuner In,voip_rx,Voice Call In"/>
-                <route type="mix" sink="Wired Headset"
-                       sources="primary output,deep_buffer,mmap_no_irq_out,compress_offload,fast,FM Tuner In,voip_rx,Voice Call In"/>
-                <route type="mix" sink="Wired Headphones"
-                       sources="primary output,deep_buffer,mmap_no_irq_out,compress_offload,fast,FM Tuner In,voip_rx,Voice Call In"/>
                 <route type="mix" sink="USB Device Out"
                        sources="primary output,deep_buffer,fast,FM Tuner In,voip_rx,Voice Call In,hifi_playback"/>
                 <route type="mix" sink="USB Headset Out"
@@ -329,11 +308,11 @@
                 <route type="mix" sink="HDMI"
                        sources="hdmi_mix_output"/>
                 <route type="mix" sink="Telephony Tx"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,USB Device In,USB Headset In,incall_music_uplink,BLE CG In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,USB Device In,USB Headset In,incall_music_uplink,BLE CG In"/>
                 <route type="mix" sink="primary input"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In,BLE BlueTooth In,BLE Headset In,BLE CG In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In,BLE BlueTooth In,BLE Headset In,BLE CG In"/>
                 <route type="mix" sink="mmap_no_irq_in"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic"/>
+                       sources="Built-In Mic,Built-In Back Mic"/>
                 <route type="mix" sink="voice tx"
                        sources="Voice Call In"/>
                 <route type="mix" sink="FM Tuner input"
@@ -341,9 +320,9 @@
                 <route type="mix" sink="hifi_input"
                        sources="USB Device In,USB Headset In"/>
                 <route type="mix" sink="voip_tx"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In,BLE CG In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In,BLE CG In"/>
                 <route type="mix" sink="fast input"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In,BLE BlueTooth In,BLE Headset In,BLE CG In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In,BLE BlueTooth In,BLE Headset In,BLE CG In"/>
             </routes>
 
         </module>
diff --git a/mediatek/mt8189/audio_policy_config/audio_policy_configuration_a2dp_offload_enable_cg_enable.xml b/mediatek/mt8189/audio_policy_config/audio_policy_configuration_a2dp_offload_enable_cg_enable.xml
old mode 100644
new mode 100755
index e7f2716..25233c0
--- a/mediatek/mt8189/audio_policy_config/audio_policy_configuration_a2dp_offload_enable_cg_enable.xml
+++ b/mediatek/mt8189/audio_policy_config/audio_policy_configuration_a2dp_offload_enable_cg_enable.xml
@@ -147,18 +147,6 @@
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
                 </devicePort>
-                <devicePort tagName="Wired Headset" type="AUDIO_DEVICE_OUT_WIRED_HEADSET" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
-                <devicePort tagName="Wired Headphones" type="AUDIO_DEVICE_OUT_WIRED_HEADPHONE" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
                 <devicePort tagName="HDMI" type="AUDIO_DEVICE_OUT_AUX_DIGITAL" role="sink">
                     <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
                              samplingRates="8000 11025 16000 22050 32000 44100 48000 64000 88200 96000 128000 176400 192000"
@@ -229,11 +217,6 @@
                              samplingRates="8000 16000 32000 44100 48000"
                              channelMasks="AUDIO_CHANNEL_IN_MONO AUDIO_CHANNEL_IN_STEREO"/>
                 </devicePort>
-                <devicePort tagName="Wired Headset Mic" type="AUDIO_DEVICE_IN_WIRED_HEADSET" role="source">
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="8000 16000 32000 44100 48000"
-                             channelMasks="AUDIO_CHANNEL_IN_MONO AUDIO_CHANNEL_IN_STEREO"/>
-                </devicePort>
                 <devicePort tagName="BT SCO Headset Mic" type="AUDIO_DEVICE_IN_BLUETOOTH_SCO_HEADSET" role="source">
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="8000 16000" channelMasks="AUDIO_CHANNEL_IN_MONO"/>
@@ -312,10 +295,6 @@
                        sources="primary output,deep_buffer,voip_rx,mmap_no_irq_out,fast,Voice Call In"/>
                 <route type="mix" sink="Speaker"
                        sources="primary output,deep_buffer,mmap_no_irq_out,fast,compress_offload,FM Tuner In,voip_rx,Voice Call In"/>
-                <route type="mix" sink="Wired Headset"
-                       sources="primary output,deep_buffer,mmap_no_irq_out,fast,compress_offload,FM Tuner In,voip_rx,Voice Call In"/>
-                <route type="mix" sink="Wired Headphones"
-                       sources="primary output,deep_buffer,mmap_no_irq_out,fast,compress_offload,FM Tuner In,voip_rx,Voice Call In"/>
                 <route type="mix" sink="USB Device Out"
                        sources="primary output,deep_buffer,fast,FM Tuner In,voip_rx,Voice Call In,hifi_playback"/>
                 <route type="mix" sink="USB Headset Out"
@@ -347,11 +326,11 @@
                 <route type="mix" sink="BLE Speaker Out"
                        sources="primary output,deep_buffer,fast,compress_offload"/>
                 <route type="mix" sink="Telephony Tx"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,USB Device In,USB Headset In,incall_music_uplink,BLE CG In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,USB Device In,USB Headset In,incall_music_uplink,BLE CG In"/>
                 <route type="mix" sink="primary input"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In,BLE BlueTooth In,BLE Headset In,BLE CG In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In,BLE BlueTooth In,BLE Headset In,BLE CG In"/>
                 <route type="mix" sink="mmap_no_irq_in"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic"/>
+                       sources="Built-In Mic,Built-In Back Mic"/>
                 <route type="mix" sink="voice tx"
                        sources="Voice Call In"/>
                 <route type="mix" sink="FM Tuner input"
@@ -359,9 +338,9 @@
                 <route type="mix" sink="hifi_input"
                        sources="USB Device In,USB Headset In"/>
                 <route type="mix" sink="voip_tx"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In,BLE CG In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In,BLE CG In"/>
                 <route type="mix" sink="fast input"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In,BLE BlueTooth In,BLE Headset In,BLE CG In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In,BLE BlueTooth In,BLE Headset In,BLE CG In"/>
             </routes>
 
         </module>
diff --git a/mediatek/mt8189/audio_policy_config/audio_policy_configuration_bluetooth_legacy_hal.xml b/mediatek/mt8189/audio_policy_config/audio_policy_configuration_bluetooth_legacy_hal.xml
old mode 100644
new mode 100755
index 2b2359d..b76a702
--- a/mediatek/mt8189/audio_policy_config/audio_policy_configuration_bluetooth_legacy_hal.xml
+++ b/mediatek/mt8189/audio_policy_config/audio_policy_configuration_bluetooth_legacy_hal.xml
@@ -93,18 +93,6 @@
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
                 </devicePort>
-                <devicePort tagName="Wired Headset" type="AUDIO_DEVICE_OUT_WIRED_HEADSET" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
-                <devicePort tagName="Wired Headphones" type="AUDIO_DEVICE_OUT_WIRED_HEADPHONE" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
                 <devicePort tagName="AUX Digital Out" type="AUDIO_DEVICE_OUT_AUX_DIGITAL" role="sink">
                     <profile name="" format="AUDIO_FORMAT_PCM_32_BIT"
                              samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
@@ -159,11 +147,6 @@
                              samplingRates="8000 16000 32000 44100 48000"
                              channelMasks="AUDIO_CHANNEL_IN_MONO AUDIO_CHANNEL_IN_STEREO"/>
                 </devicePort>
-                <devicePort tagName="Wired Headset Mic" type="AUDIO_DEVICE_IN_WIRED_HEADSET" role="source">
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="8000 16000 32000 44100 48000"
-                             channelMasks="AUDIO_CHANNEL_IN_MONO AUDIO_CHANNEL_IN_STEREO"/>
-                </devicePort>
                 <devicePort tagName="BT SCO Headset Mic" type="AUDIO_DEVICE_IN_BLUETOOTH_SCO_HEADSET" role="source">
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="8000 16000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
@@ -195,10 +178,6 @@
                        sources="primary output,deep_buffer,fast"/>
                 <route type="mix" sink="Speaker"
                        sources="primary output,deep_buffer,fast,FM Tuner In"/>
-                <route type="mix" sink="Wired Headset"
-                       sources="primary output,deep_buffer,fast,FM Tuner In"/>
-                <route type="mix" sink="Wired Headphones"
-                       sources="primary output,deep_buffer,fast,FM Tuner In"/>
                 <route type="mix" sink="AUX Digital Out"
                        sources="primary output"/>
                 <route type="mix" sink="BT SCO"
@@ -216,7 +195,7 @@
                 <route type="mix" sink="USB Primary Out"
                        sources="primary output"/>
                 <route type="mix" sink="primary input"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In,FM Tuner In,USB Primary In,Voice Call In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In,FM Tuner In,USB Primary In,Voice Call In"/>
             </routes>
 
         </module>
diff --git a/mediatek/mt8189/audio_policy_config/usb_audio_policy_configuration.xml b/mediatek/mt8189/audio_policy_config/usb_audio_policy_configuration.xml
old mode 100644
new mode 100755
diff --git a/mediatek/vendor/common/audio_policy_config/audio_policy_configuration.xml b/mediatek/vendor/common/audio_policy_config/audio_policy_configuration.xml
old mode 100644
new mode 100755
index e983378..284245c
--- a/mediatek/vendor/common/audio_policy_config/audio_policy_configuration.xml
+++ b/mediatek/vendor/common/audio_policy_config/audio_policy_configuration.xml
@@ -107,14 +107,6 @@
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
                 </devicePort>
-                <devicePort tagName="Wired Headset" type="AUDIO_DEVICE_OUT_WIRED_HEADSET" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
-                <devicePort tagName="Wired Headphones" type="AUDIO_DEVICE_OUT_WIRED_HEADPHONE" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
                 <devicePort tagName="AUX Digital Out" type="AUDIO_DEVICE_OUT_AUX_DIGITAL" role="sink">
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
@@ -131,10 +123,6 @@
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="8000 16000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
                 </devicePort>
-                <devicePort tagName="Analog Dock Headset" type="AUDIO_DEVICE_OUT_ANLG_DOCK_HEADSET" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
                 <devicePort tagName="Digital Dock Headset" type="AUDIO_DEVICE_OUT_DGTL_DOCK_HEADSET" role="sink">
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
@@ -164,11 +152,6 @@
                              samplingRates="8000 16000 32000 44100 48000"
                              channelMasks="AUDIO_CHANNEL_IN_MONO AUDIO_CHANNEL_IN_STEREO"/>
                 </devicePort>
-                <devicePort tagName="Wired Headset Mic" type="AUDIO_DEVICE_IN_WIRED_HEADSET" role="source">
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="8000 16000 32000 44100 48000"
-                             channelMasks="AUDIO_CHANNEL_IN_MONO AUDIO_CHANNEL_IN_STEREO"/>
-                </devicePort>
                 <devicePort tagName="BT SCO Headset Mic" type="AUDIO_DEVICE_IN_BLUETOOTH_SCO_HEADSET" role="source">
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="8000 16000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
@@ -221,10 +204,6 @@
                        sources="primary output,fast,deep_buffer,Voice Call In"/>
                 <route type="mix" sink="Speaker"
                        sources="primary output,fast,deep_buffer,FM Tuner In,Voice Call In"/>
-                <route type="mix" sink="Wired Headset"
-                       sources="primary output,fast,deep_buffer,FM Tuner In,Voice Call In"/>
-                <route type="mix" sink="Wired Headphones"
-                       sources="primary output,fast,deep_buffer,FM Tuner In,Voice Call In"/>
                 <route type="mix" sink="AUX Digital Out"
                        sources="primary output"/>
                 <route type="mix" sink="USB Device Out"
@@ -237,16 +216,14 @@
                        sources="primary output,deep_buffer,fast,Voice Call In"/>
                 <route type="mix" sink="BT SCO Car Kit"
                        sources="primary output,deep_buffer,fast,Voice Call In"/>
-                <route type="mix" sink="Analog Dock Headset"
-                       sources="primary output"/>
                 <route type="mix" sink="Digital Dock Headset"
                        sources="primary output"/>
                 <route type="mix" sink="FM Tuner Out"
                        sources="primary output"/>
                 <route type="mix" sink="Telephony Tx"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,USB Device In,USB Headset In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,USB Device In,USB Headset In"/>
                 <route type="mix" sink="primary input"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In,FM Tuner In,Voice Call In,USB Device In,USB Headset In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In,FM Tuner In,Voice Call In,USB Device In,USB Headset In"/>
                 <route type="mix" sink="voice tx"
                        sources="Voice Call In"/>
                 <route type="mix" sink="FM Tuner input"
@@ -254,9 +231,9 @@
                 <route type="mix" sink="hifi_input"
                        sources="USB Device In,USB Headset In"/>
                 <route type="mix" sink="voip_tx"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In"/>
                 <route type="mix" sink="fast input"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In,USB Device In,USB Headset In"/>
             </routes>
 
         </module>
diff --git a/mediatek/vendor/common/audio_policy_config/audio_policy_configuration_bluetooth_legacy_hal.xml b/mediatek/vendor/common/audio_policy_config/audio_policy_configuration_bluetooth_legacy_hal.xml
old mode 100644
new mode 100755
index 246ea99..9f851b9
--- a/mediatek/vendor/common/audio_policy_config/audio_policy_configuration_bluetooth_legacy_hal.xml
+++ b/mediatek/vendor/common/audio_policy_config/audio_policy_configuration_bluetooth_legacy_hal.xml
@@ -79,14 +79,6 @@
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
                 </devicePort>
-                <devicePort tagName="Wired Headset" type="AUDIO_DEVICE_OUT_WIRED_HEADSET" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
-                <devicePort tagName="Wired Headphones" type="AUDIO_DEVICE_OUT_WIRED_HEADPHONE" role="sink">
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
-                </devicePort>
                 <devicePort tagName="AUX Digital Out" type="AUDIO_DEVICE_OUT_AUX_DIGITAL" role="sink">
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="44100 48000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
@@ -126,11 +118,6 @@
                              samplingRates="8000 16000 32000 44100 48000"
                              channelMasks="AUDIO_CHANNEL_IN_MONO AUDIO_CHANNEL_IN_STEREO"/>
                 </devicePort>
-                <devicePort tagName="Wired Headset Mic" type="AUDIO_DEVICE_IN_WIRED_HEADSET" role="source">
-                    <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
-                             samplingRates="8000 16000 32000 44100 48000"
-                             channelMasks="AUDIO_CHANNEL_IN_MONO AUDIO_CHANNEL_IN_STEREO"/>
-                </devicePort>
                 <devicePort tagName="BT SCO Headset Mic" type="AUDIO_DEVICE_IN_BLUETOOTH_SCO_HEADSET" role="source">
                     <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
                              samplingRates="8000 16000" channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
@@ -157,10 +144,6 @@
                        sources="primary output,fast"/>
                 <route type="mix" sink="Speaker"
                        sources="primary output,fast,FM Tuner In"/>
-                <route type="mix" sink="Wired Headset"
-                       sources="primary output,fast,FM Tuner In"/>
-                <route type="mix" sink="Wired Headphones"
-                       sources="primary output,fast,FM Tuner In"/>
                 <route type="mix" sink="AUX Digital Out"
                        sources="primary output"/>
                 <route type="mix" sink="BT SCO"
@@ -176,7 +159,7 @@
                 <route type="mix" sink="FM Tuner Out"
                        sources="primary output"/>
                 <route type="mix" sink="primary input"
-                       sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic,AUX Digital In,FM Tuner In,Voice Call In"/>
+                       sources="Built-In Mic,Built-In Back Mic,BT SCO Headset Mic,AUX Digital In,FM Tuner In,Voice Call In"/>
             </routes>
 
         </module>
diff --git a/mediatek/vendor/common/audio_policy_config/usb_audio_policy_configuration.xml b/mediatek/vendor/common/audio_policy_config/usb_audio_policy_configuration.xml
old mode 100644
new mode 100755
-- 
2.7.4

