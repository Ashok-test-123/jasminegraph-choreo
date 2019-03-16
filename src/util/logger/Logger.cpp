/**
Copyright 2019 JasmineGraph Team
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 */

#include "Logger.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/file_sinks.h>

auto logger = spdlog::stdout_logger_mt("logger");
auto daily_logger = spdlog::daily_logger_mt("JasmineGraph", "logs/server_log", 0, 00, true);

void Logger::log(std::string message, const std::string log_type) {
    if (log_type.compare("info") == 0) {
        daily_logger->info(message);
        logger->info(message);
    } else if (log_type.compare("warn") == 0) {
        daily_logger->warn(message);
        logger->warn(message);
    } else if (log_type.compare("trace") == 0) {
        daily_logger->trace(message);
        logger->trace(message);
    } else if (log_type.compare("error") == 0) {
        daily_logger->error(message);
        logger->error(message);
    } else {
        std::cout << "Invalid logging type" << std::endl;
    }

}