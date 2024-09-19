#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/BinderService.h>
#include "../com/example/myservice/IMyService.h"
#include "../com/example/myservice/BnMyService.h"

using namespace android;
using namespace com::example::myservice;

class MyService : public BnMyService {
public:
    static void instantiate() {
        defaultServiceManager()->addService(String16("MyService"), new MyService());
    }

    virtual ::android::binder::Status myMethod() override {
        // 实现你的服务逻辑
        ALOGI("MyService::myMethod called");
	return ::android::binder::Status::ok();
    }
};

int main(int /*argc*/, char** /*argv*/) {
    sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm = defaultServiceManager();
    MyService::instantiate();
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    return 0;
}

