#include "logger.h"

void Logger::LogInfo(const QString& message){
    Log("INFO",message);
}
void Logger::LogWarning(const QString& message){
    Log("Warning",message);
}
void Logger::LogError(const QString& message){
    Log("Error",message);
}
void Logger::LogCriticalError(const QString& message){
    Log("CriticalError",message);
}

