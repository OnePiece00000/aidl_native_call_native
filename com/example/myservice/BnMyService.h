#ifndef AIDL_GENERATED_COM_EXAMPLE_MYSERVICE_BN_MY_SERVICE_H_
#define AIDL_GENERATED_COM_EXAMPLE_MYSERVICE_BN_MY_SERVICE_H_

#include <binder/IInterface.h>
#include "../com/example/myservice/IMyService.h"

namespace com {

namespace example {

namespace myservice {

class BnMyService : public ::android::BnInterface<IMyService> {
public:
  explicit BnMyService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnMyService

}  // namespace myservice

}  // namespace example

}  // namespace com

#endif  // AIDL_GENERATED_COM_EXAMPLE_MYSERVICE_BN_MY_SERVICE_H_
