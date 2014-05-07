ifneq ($(TARGET_SIMULATOR),true)

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

ifneq ($(MTK_BOOT_DEVICE_NAME),)
    LOCAL_CFLAGS += -DMTK_BOOT_DEVICE_NAME="$(MTK_BOOT_DEVICE_NAME)"
endif

ifneq ($(MTK_BOOT_DEVICE_SIZE),)
    LOCAL_CFLAGS += -DMTK_BOOT_DEVICE_SIZE=$(MTK_BOOT_DEVICE_SIZE)
endif

ifneq ($(MTK_RECOVERY_DEVICE_NAME),)
    LOCAL_CFLAGS += -DMTK_RECOVERY_DEVICE_NAME="$(MTK_RECOVERY_DEVICE_NAME)"
endif

ifneq ($(MTK_RECOVERY_DEVICE_SIZE),)
    LOCAL_CFLAGS += -DMTK_RECOVERY_DEVICE_SIZE=$(MTK_RECOVERY_DEVICE_SIZE)
endif

ifneq ($(MTK_UBOOT_DEVICE_NAME),)
    LOCAL_CFLAGS += -DMTK_UBOOT_DEVICE_NAME="$(MTK_UBOOT_DEVICE_NAME)"
endif

ifneq ($(MTK_UBOOT_DEVICE_SIZE),)
    LOCAL_CFLAGS += -DMTK_UBOOT_DEVICE_SIZE=$(MTK_UBOOT_DEVICE_SIZE)
endif

LOCAL_SRC_FILES := \
	mmcutils.c

LOCAL_MODULE := libmmcutils
LOCAL_MODULE_TAGS := eng

include $(BUILD_STATIC_LIBRARY)

endif	# !TARGET_SIMULATOR