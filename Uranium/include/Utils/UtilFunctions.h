#pragma once
#include <string>
#include <iostream>
#include <chrono>
#include <Logger/Logger.h>
#include <Utils/macros.h>
namespace Uranium
{
	namespace Utils
	{
		std::string CreateUUID(); // Creates a UUID

		std::string GetNameWithNamespace(std::string& name); // Creates a name with the project namespace

        class Timer {
        public:
            Timer(const std::string& name) : name(name), start(std::chrono::high_resolution_clock::now()) {}
            Timer(int* writeLocation) : writeLocation(writeLocation), start(std::chrono::high_resolution_clock::now()) {}

            ~Timer() {
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
                if (writeLocation != nullptr) {
					*writeLocation = duration.count();
                    return;
				}
                Logs::Logger::Info("Timer {} has, Elapsed time: {}, milliseconds", name, duration.count());
            }

        private:
            std::chrono::time_point<std::chrono::high_resolution_clock> start;
            const std::string name;
            int* writeLocation = nullptr;
        };


        static auto StrToRJ(std::string& translation)
        {
            return rapidjson::StringRef(translation.c_str(), translation.size());
        };
	}
}


#define BENCHMARK_FUNCTION(Function, Count, ...) \
{ \
	Uranium::Utils::Timer timer(#Function); \
	for (int i = 0; i < Count; i++) { \
		Function(__VA_ARGS__); \
	} \
}