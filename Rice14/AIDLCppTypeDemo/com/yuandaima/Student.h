//Student.h
#ifndef _COM_YUANDAIMA_STUDENT_H
#define _COM_YUANDAIMA_STUDENT_H

#include <android-base/unique_fd.h>
#include <binder/Parcel.h>
#include <binder/Parcelable.h>
#include <binder/Status.h>
#include <utils/RefBase.h>
#include <vector>

using namespace std;
using namespace android;

namespace com {
namespace yuandaima {

    class Student : public Parcelable {
        public:
            Student();
            virtual ~Student();
            
            virtual status_t writeToParcel(Parcel* out) const;
            virtual status_t readFromParcel(const Parcel* in); 

            void setAge(int32_t age);
            int32_t getAge() const;
            void setName(String16 name);
            String16 getName() const;
        private:
            String16 mName;
            int32_t mAge;
    };

}
}
#endif
