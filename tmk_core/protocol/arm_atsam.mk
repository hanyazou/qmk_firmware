ARM_ATSAM_DIR = protocol/arm_atsam

ifeq ($(strip $(USB_DUALPORT_ENABLE)), yes)
  SRC += $(ARM_ATSAM_DIR)/adc.c
endif
#SRC += $(ARM_ATSAM_DIR)/clks.c
SRC += $(ARM_ATSAM_DIR)/clks_d21.c
SRC += $(ARM_ATSAM_DIR)/d21_util.c
#SRC += $(ARM_ATSAM_DIR)/d51_util.c
SRC += $(ARM_ATSAM_DIR)/i2c_master.c
ifeq ($(RGB_MATRIX_ENABLE),custom)
  SRC += $(ARM_ATSAM_DIR)/led_matrix_programs.c
  SRC += $(ARM_ATSAM_DIR)/led_matrix.c
endif
SRC += $(ARM_ATSAM_DIR)/main_arm_atsam.c
SRC += $(ARM_ATSAM_DIR)/serial_print.c
ifeq ($(strip $(USB_DUALPORT_ENABLE)), yes)
  SRC += $(ARM_ATSAM_DIR)/spi.c
endif
#SRC += $(ARM_ATSAM_DIR)/startup.c
SRC += $(ARM_ATSAM_DIR)/startup_d21.c

SRC += $(ARM_ATSAM_DIR)/usb/main_usb.c
SRC += $(ARM_ATSAM_DIR)/usb/udc.c
SRC += $(ARM_ATSAM_DIR)/usb/udi_cdc.c
SRC += $(ARM_ATSAM_DIR)/usb/udi_hid.c
SRC += $(ARM_ATSAM_DIR)/usb/udi_hid_kbd.c
SRC += $(ARM_ATSAM_DIR)/usb/udi_hid_kbd_desc.c
SRC += $(ARM_ATSAM_DIR)/usb/ui.c
#SRC += $(ARM_ATSAM_DIR)/usb/usb2422.c
SRC += $(ARM_ATSAM_DIR)/usb/usb.c
SRC += $(ARM_ATSAM_DIR)/usb/usb_device_udd.c
SRC += $(ARM_ATSAM_DIR)/usb/usb_util.c

LDFLAGS += -T$(TMK_DIR)/$(ARM_ATSAM_DIR)/samd21g18a_flash_with_bootloader.ld

# Search Path
VPATH += $(TMK_DIR)/$(ARM_ATSAM_DIR)
