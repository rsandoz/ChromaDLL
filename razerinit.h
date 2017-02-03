/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 */

#ifndef DRIVER_RAZERINIT_H_
#define DRIVER_RAZERINIT_H_

__declspec(dllexport) void init();
__declspec(dllexport) void close(struct usb_dev_handle* deviceHandle);

#endif /* DRIVER_RAZERINIT_H_ */
