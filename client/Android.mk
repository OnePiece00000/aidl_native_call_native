LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := my_client
LOCAL_SRC_FILES := MyClient.cpp ../com/example/myservice/IMyService.cpp
LOCAL_SHARED_LIBRARIES := libbinder liblog
LOCAL_LDLIBS += -L$(SYSROOT)/usr/lib -landroid -lutils

include $(BUILD_EXECUTABLE)

