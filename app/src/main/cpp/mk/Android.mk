LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_LDLIBS += -llog
LOCAL_MODULE    := libjni-mk
LOCAL_SRC_FILES := com_jack_learning_ndk_mk_JNIMK.cpp Parent.cpp
include $(BUILD_SHARED_LIBRARY)