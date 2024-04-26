#define LOG_TAG "aidl_cpp"

#include <utils/Log.h>
#include <binder/IServiceManager.h>
#include "com/yuandaima/IHello.h"

using namespace android;
using com::yuandaima::IHello;

int main(int argc, char const *argv[])
{
    // サービスマネージャーからIHelloサービスのバインダーを取得
    sp<IBinder> binder = defaultServiceManager()->getService(String16("IHello"));
    if (binder == nullptr) {
        ALOGE("Failed to get IHello service binder");
        return -1;
    }

    // IHelloインターフェースを取得
    sp<IHello> hello = interface_cast<IHello>(binder);
    if (hello == nullptr) {
        ALOGE("Failed to get IHello interface");
        return -1;
    }

    // サービスのhelloメソッドを呼び出し
    hello->hello();

    // サービスのsumメソッドを呼び出し
    int32_t result;
    hello->sum(3, 5, &result);
    ALOGI("sum result: %d", result);

    // サービスのprintListメソッドを呼び出し
    std::vector<android::String16> strings = {String16("Hello"), String16("world"), String16("!")};
    int32_t listResult;
    hello->printList(strings, &listResult);
    ALOGI("printList result: %d", listResult);

    // サービスのprintMapメソッドを呼び出し
    android::binder::Map map;
    map.emplace("key1", String16("value1"));
    map.emplace("key2", String16("value2"));
    int32_t mapResult;
    hello->printMap(map, &mapResult);
    ALOGI("printMap result: %d", mapResult);

    return 0;
}
