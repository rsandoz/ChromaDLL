/*
 * Copyright (c) 2015 Terry Cain <terrys-home.co.uk>
 */

/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 */

#ifndef __HID_RAZER_MUG_H
#define __HID_RAZER_MUG_H

#ifndef USB_VENDOR_ID_RAZER
    #define USB_VENDOR_ID_RAZER 0x1532
#endif

#ifndef USB_DEVICE_ID_RAZER_CHROMA_MUG
    #define USB_DEVICE_ID_RAZER_CHROMA_MUG 0x0f07
#endif

struct razer_mug_device {
    struct usb_device *usb_dev;
    struct input_dev *input;
    struct mutex lock;
    unsigned char usb_interface_protocol;
    
    unsigned short usb_vid;
    unsigned short usb_pid;
    
    unsigned char mug_present_poll;
    
    char serial[23];
    // 3 Bytes, first byte is wether fw version is collected, 2nd byte is major version, 3rd is minor, should be printed out in hex form as are bcd
    unsigned char firmware_version[3];
};

/* 
 * USB INTERRUPT
 * 
 * */

#if defined(WIN32) || defined(_WIN64)
#undef DEVICE_ATTR
#define DEVICE_ATTR(_name, _mode, _show, _store) DEVICE_ATTR1(mug, _name, _mode, _show, _store)
DLL_INTERNAL unsigned int init_razer_mug_driver(struct hid_device** hdev);
DLL_INTERNAL struct device_attribute devmug_attr_matrix_effect_custom;
DLL_INTERNAL struct device_attribute devmug_attr_matrix_custom_frame;
#endif

#endif
