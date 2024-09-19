#ifndef AIDL_GENERATED_COM_EXAMPLE_MYSERVICE_I_MY_SERVICE_H_
#define AIDL_GENERATED_COM_EXAMPLE_MYSERVICE_I_MY_SERVICE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace com {

namespace example {

namespace myservice {

class IMyService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(MyService)
  virtual ::android::binder::Status myMethod() = 0;
};  // class IMyService

class IMyServiceDefault : public IMyService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status myMethod() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IMyServiceDefault

}  // namespace myservice

}  // namespace example

}  // namespace com

#endif  // AIDL_GENERATED_COM_EXAMPLE_MYSERVICE_I_MY_SERVICE_H_
