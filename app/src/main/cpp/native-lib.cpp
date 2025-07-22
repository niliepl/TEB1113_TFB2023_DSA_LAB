#include <jni.h>
#include <string>
#include <vector>
#include <chrono>
#include <algorithm>

std::vector<std::string> arrayData;
long arrayTotalTime = 0;
int arrayStepCount = 0;

extern "C" JNIEXPORT void JNICALL
Java_com_example_attendance_1app_MainActivity_addToArrayNative(
        JNIEnv* env,
        jobject /* this */,
        jstring studentIdJ) {

    const char* studentId = env->GetStringUTFChars(studentIdJ, 0);
    arrayData.insert(arrayData.begin(), std::string(studentId));
    env->ReleaseStringUTFChars(studentIdJ, studentId);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_attendance_1app_MainActivity_searchInArrayNative(
        JNIEnv* env,
        jobject /* this */,
        jstring studentIdJ) {

    const char* studentId = env->GetStringUTFChars(studentIdJ, 0);
    std::string id(studentId);
    env->ReleaseStringUTFChars(studentIdJ, studentId);

    auto start = std::chrono::high_resolution_clock::now();
    std::string steps = "Array Search:\n";
    int searchSteps = 0;
    bool found = false;
    int position = -1;

    // Linear search
    for (int i = 0; i < arrayData.size(); i++) {
        searchSteps++;
        steps += "Step " + std::to_string(searchSteps) +
                 ": Index " + std::to_string(i) +
                 " = " + arrayData[i] + "\n";

        if (arrayData[i] == id) {
            found = true;
            position = i;
            break;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    long timeTaken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    // Update global counters
    arrayTotalTime += timeTaken;
    arrayStepCount += searchSteps;

    steps += found ? "FOUND at index " + std::to_string(position) + "\n"
                   : "NOT FOUND\n";
    steps += "Time: " + std::to_string(timeTaken / 1000) + "μs\n";
    steps += "Steps: " + std::to_string(searchSteps);

    return env->NewStringUTF(steps.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_attendance_1app_MainActivity_getArrayStatsNative(
        JNIEnv* env,
        jobject /* this */) {

    std::string stats = "Array Statistics:\n";
    stats += "Items: " + std::to_string(arrayData.size()) + "\n";
    stats += "Total Steps: " + std::to_string(arrayStepCount) + "\n";
    stats += "Total Time: " + std::to_string(arrayTotalTime / 1000000) + "ms\n";
    stats += "Avg Time/Step: " +
             std::to_string(arrayTotalTime / (arrayStepCount > 0 ? arrayStepCount : 1) / 1000) +
             "μs";

    return env->NewStringUTF(stats.c_str());
}