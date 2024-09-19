LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := Myserver
LOCAL_SRC_FILES := MyService.cpp ../com/example/myservice/IMyService.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../com
LOCAL_SHARED_LIBRARIES := libbinder liblog
LOCAL_LDLIBS := -llog -landroid -lutils
include $(BUILD_EXECUTABLE)

