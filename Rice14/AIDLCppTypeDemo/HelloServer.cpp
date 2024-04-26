#define LOG_TAG "aidl_cpp"

#include <stdlib.h>
#include <utils/RefBase.h>
#include <utils/Log.h>
#include <binder/TextOutput.h>
#include <binder/IInterface.h>
#include <binder/IBinder.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "com/yuandaima/IHello.h"
#include "com/yuandaima/BnHello.h"

using namespace android;

class IHelloServer : public com::yuandaima::BnHello
{
public:
    binder::Status hello() override
    {
        ALOGI("hello");
        return binder::Status();
    }

    binder::Status sum(int32_t v1, int32_t v2, int32_t *_aidl_return) override
    {
        ALOGI("server: sum: %d + %d", v1, v2);
        *_aidl_return = v1 + v2;
        return binder::Status();
    }

    binder::Status printList(const ::std::vector<::android::String16>& strs, int32_t* _aidl_return) override
    {
        for (const auto & str : strs)
        {
            ALOGI("%s", String8(str).c_str());
        }

        *_aidl_return = 1;
        return binder::Status();
    }

    binder::Status printMap(const ::android::binder::Map& maps, int32_t* _aidl_return) override
    {
        for(auto it : maps){
            std::string val;
            it.second.getString(&val);
            ALOGI("key is %s, value is %s", it.first.c_str(), val.c_str());
        }
        *_aidl_return = 1;
        return binder::Status();
    }

    binder::Status printStudent(const ::com::yuandaima::Student& student, int32_t* _aidl_return) override
    {
        ALOGI("student name is %s, age is %d", String8(student.getName()).c_str(), student.getAge());
        *_aidl_return = 1;
        return binder::Status();
    }

};

int main(int argc, char const *argv[])
{
    defaultServiceManager()->addService(String16("IHello"), new IHelloServer());
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
    return 0;
}