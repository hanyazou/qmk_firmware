#pragma once

#include <compiler.h>
#include <config.h>

#ifndef USB_DEVICE_VENDOR_ID
#define USB_DEVICE_VENDOR_ID VENDOR_ID
#endif
#ifndef USB_DEVICE_PRODUCT_ID
#define USB_DEVICE_PRODUCT_ID PRODUCT_ID
#endif
#ifndef USB_DEVICE_MAJOR_VERSION
#define USB_DEVICE_MAJOR_VERSION ((DEVICE_VER >> 8) & 0xff)
#endif
#ifndef USB_DEVICE_MINOR_VERSION
#define USB_DEVICE_MINOR_VERSION ((DEVICE_VER >> 0) & 0xff)
#endif
#define USB_DEVICE_POWER 100
#define USB_DEVICE_ATTR USB_CONFIG_ATTR_BUS_POWERED

#define UDI_HID_KBD_ENABLE_EXT() arm_atsam_asf_udi_hid_callback_keyboard_enable()
#define UDI_HID_KBD_DISABLE_EXT() arm_atsam_asf_udi_hid_callback_keyboard_disable()
#define UDI_HID_KBD_CHANGE_LED(value)

#include "class/hid/device/kbd/udi_hid_kbd_conf.h" // At the end of conf_usb.h file
