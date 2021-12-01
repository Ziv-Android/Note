#! /bin/bash
echo "PicName: $1"
# adb shell screencap -p | sed 's/\r$//' > $1.png
adb shell screencap -p /sdcard/$1.png
adb pull /sdcard/$1.png .
adb shell rm /sdcard/$1.png