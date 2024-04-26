// Studeng.cpp
#include "Student.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;
using namespace android;

namespace com {
namespace yuandaima {

    Student::Student() {
        this->setAge(20);
        this->setName(String16("jack"));
    }

    Student::~Student() {
    }

    status_t Student::writeToParcel(Parcel* out) const {
        status_t err;
        err = out->writeString16(mName);
        if (err != NO_ERROR) {
            return err;
        }
        err = out->writeInt32(mAge);
        if (err != NO_ERROR) {
            return err;
        }
        return NO_ERROR;
    }

    status_t Student::readFromParcel(const Parcel* in) {
        status_t err;
        err = in->readString16(&mName);
        if (err != NO_ERROR) {
            return err;
        }
        err = in->readInt32(&mAge);
        if (err != NO_ERROR) {
            return err;
        }

        return NO_ERROR;
    }

    int32_t Student::getAge() const {
        return mAge;
    }

    String16 Student::getName() const {
        return mName;
    }

    void Student::setAge(int32_t age) {
        mAge = age;
    }

    void Student::setName(String16 name) {
        mName = name;
    }
}}