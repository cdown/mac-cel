#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <IOKit/hidsystem/IOHIDLib.h>
#include <IOKit/hidsystem/IOHIDParameter.h>
#include <IOKit/hidsystem/event_status_driver.h>

int main(int argc, char *argv[]) {
    CFStringRef device;
    const int32_t accel_amount = INT32_MIN;
    NXEventHandle handle;
    kern_return_t set_accel;

    if (argc > 1 && (!(strncmp(argv[1], "-t", 2))))
        device = CFSTR(kIOHIDTrackpadAccelerationType);
    else
        device = CFSTR(kIOHIDMouseAccelerationType);

    handle = NXOpenEventStatus();
    if (!handle) {
        perror("NXOpenEventStatus");
        return EXIT_FAILURE;
    }

    set_accel = IOHIDSetParameter(
        handle,
        device,
        &accel_amount,
        sizeof(accel_amount)
    );
    if (set_accel != KERN_SUCCESS) {
        perror("IOHIDSetParameter");
        return EXIT_FAILURE;
    }

    NXCloseEventStatus(handle);
    return EXIT_SUCCESS;
}
