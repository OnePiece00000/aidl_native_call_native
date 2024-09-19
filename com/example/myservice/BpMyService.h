#ifndef AIDL_GENERATED_COM_EXAMPLE_MYSERVICE_BP_MY_SERVICE_H_
#define AIDL_GENERATED_COM_EXAMPLE_MYSERVICE_BP_MY_SERVICE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include "IMyService.h"

namespace com {

namespace example {

namespace myservice {

class BpMyService : public ::android::BpInterface<IMyService> {
public:
  explicit BpMyService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpMyService() = default;
  ::android::binder::Status myMethod() override;
};  // class BpMyService

}  // namespace myservice

}  // namespace example

}  // namespace com

#endif  // AIDL_GENERATED_COM_EXAMPLE_MYSERVICE_BP_MY_SERVICE_H_
