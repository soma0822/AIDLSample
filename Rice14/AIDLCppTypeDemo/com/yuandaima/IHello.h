#ifndef AIDL_GENERATED_COM_YUANDAIMA_I_HELLO_H_
#define AIDL_GENERATED_COM_YUANDAIMA_I_HELLO_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Map.h>
#include <binder/Status.h>
#include <binder/Value.h>
#include <com/yuandaima/Student.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace com {

namespace yuandaima {

class IHello : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Hello)
  virtual ::android::binder::Status hello() = 0;
  virtual ::android::binder::Status sum(int32_t x, int32_t y, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status printList(const ::std::vector<::android::String16>& strs, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status printMap(const ::android::binder::Map& maps, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status printStudent(const ::com::yuandaima::Student& student, int32_t* _aidl_return) = 0;
};  // class IHello

class IHelloDefault : public IHello {
public:
  ::android::IBinder* onAsBinder() override;
  ::android::binder::Status hello() override;
  ::android::binder::Status sum(int32_t x, int32_t y, int32_t* _aidl_return) override;
  ::android::binder::Status printList(const ::std::vector<::android::String16>& strs, int32_t* _aidl_return) override;
  ::android::binder::Status printMap(const ::android::binder::Map& maps, int32_t* _aidl_return) override;
  ::android::binder::Status printStudent(const ::com::yuandaima::Student& student, int32_t* _aidl_return) override;

};

}  // namespace yuandaima

}  // namespace com

#endif  // AIDL_GENERATED_COM_YUANDAIMA_I_HELLO_H_
