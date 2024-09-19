#include <binder/IServiceManager.h>
#include <utils/String16.h>
#include "../com/example/myservice/IMyService.h"

using namespace android;
using namespace com::example::myservice;

int main(int /*argc*/, char** /*argv*/) {
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16("MyService"));
    if (binder == nullptr) {
        ALOGE("Failed to get MyService");
        return -1;
    }

    sp<IMyService> service = interface_cast<IMyService>(binder);
    if (service != nullptr) {
        service->myMethod();
    } else {
        ALOGE("Failed to cast to IMyService");
    }

    return 0;
}

