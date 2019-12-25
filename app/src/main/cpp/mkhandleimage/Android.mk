LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_LDLIBS += -llog
LOCAL_MODULE    := libjni-mkhandleImage
LOCAL_SRC_FILES := com_jack_learning_ndk_mkhandleimage_JNIMKHandleImage.cpp AlgFunc.cpp
include $(BUILD_SHARED_LIBRARY)