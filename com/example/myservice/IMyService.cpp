#include "IMyService.h"
#include "BpMyService.h"

namespace com {

namespace example {

namespace myservice {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(MyService, "com.example.myservice.IMyService")

}  // namespace myservice

}  // namespace example

}  // namespace com
#include "BpMyService.h"
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace com {

namespace example {

namespace myservice {

BpMyService::BpMyService(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IMyService>(_aidl_impl){
}

::android::binder::Status BpMyService::myMethod() {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* myMethod */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IMyService::getDefaultImpl())) {
     return IMyService::getDefaultImpl()->myMethod();
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace myservice

}  // namespace example

}  // namespace com
#include "BnMyService.h"
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace com {

namespace example {

namespace myservice {

BnMyService::BnMyService()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnMyService::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* myMethod */:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(myMethod());
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
  }
  break;
  default:
  {
    _aidl_ret_status = ::android::BBinder::onTransact(_aidl_code, _aidl_data, _aidl_reply, _aidl_flags);
  }
  break;
  }
  if (_aidl_ret_status == ::android::UNEXPECTED_NULL) {
    _aidl_ret_status = ::android::binder::Status::fromExceptionCode(::android::binder::Status::EX_NULL_POINTER).writeToParcel(_aidl_reply);
  }
  return _aidl_ret_status;
}

}  // namespace myservice

}  // namespace example

}  // namespace com
