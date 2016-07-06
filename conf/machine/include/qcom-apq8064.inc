SOC_FAMILY = "apq8064"
require conf/machine/include/soc-family.inc
require conf/machine/include/tune-cortexa8.inc

XSERVER_OPENGL ?= "xf86-video-freedreno \
                   xserver-xorg-module-exa \
                   xserver-xorg-extension-glx \
                   xserver-xorg-extension-dri \
                  "

XSERVER = " \
	xserver-xorg \
    ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', '${XSERVER_OPENGL}', 'xf86-video-fbdev', d)} \
	xf86-input-mouse \
	xf86-input-keyboard \
	xf86-input-evdev \
"

PREFERRED_PROVIDER_virtual/egl ?= "mesa"
PREFERRED_PROVIDER_virtual/libgl ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles1 ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles2 ?= "mesa"
PREFERRED_PROVIDER_virtual/xserver = "xserver-xorg"
PREFERRED_PROVIDER_virtual/kernel = "linux-linaro-qcomlt"

BOOTIMG_CMDLINE_ROOT ?= "root=/dev/mmcblk0p12 rootwait"
BOOTIMG_PAGE_SIZE ?= "2048"
BOOTIMG_BASE_ADDR ?= "0x80200000"
DT_IMAGE_BASE_NAME ?= ""
DT_IMAGE_SYMLINK_NAME ?= ""

IMAGE_ROOTFS_ALIGNMENT = "4096"
