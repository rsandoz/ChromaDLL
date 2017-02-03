/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 */

#include "razerinit.h"
#include "lusb0_usb.h"

void init() {
	// Initialize the library.
	usb_init();

	// Find all busses.
	usb_find_busses();

	// Find all connected devices.
	usb_find_devices();
}

void close(struct usb_dev_handle* deviceHandle) {
	usb_close(deviceHandle);
}
