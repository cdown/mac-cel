#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <IOKit/hidsystem/IOHIDLib.h>
#include <IOKit/hidsystem/IOHIDParameter.h>
#include <IOKit/hidsystem/event_status_driver.h>

int main(int argc, char *argv[]) {
    io_connect_t handle;
    const int32_t acceleration_amount = INT32_MIN;
    CFStringRef device_type;

    if ((handle = NXOpenEventStatus())) {
        if (argc > 1 && (!(strncmp(argv[1], "-t", 3))))
            device_type = CFSTR(kIOHIDTrackpadAccelerationType);
        else
            device_type = CFSTR(kIOHIDMouseAccelerationType);

        if (IOHIDSetParameter(handle, device_type, &acceleration_amount,
                              sizeof(acceleration_amount)) != KERN_SUCCESS)
        {
            fputs("Failed to set HID parameters.\n", stderr);
            NXCloseEventStatus(handle);
            return EXIT_FAILURE;
        }

        NXCloseEventStatus(handle);
    } else {
        fputs("Couldn't acquire handle.\n", stderr);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
