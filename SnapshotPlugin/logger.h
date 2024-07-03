#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QDebug>
#include "Singleton.h"

class Logger:public Singleton<Logger>
{
    friend class Singleton<Logger>;
public:
    void LogInfo(const QString& message);
    void LogWarning(const QString& message);
    void LogError(const QString& message);
    void LogCriticalError(const QString& message);
private:
    Logger(){
        m_file.setFileName("BrowserSnapshotLog.txt");
        if(!m_file.open(QIODevice::WriteOnly|QIODevice::Append|QIODevice::Text)){
            qWarning()<<"Cannot open MoocLogger File.";
        }
    }
    void Log(const QString& level, const QString& message){
        if(m_file.isOpen()&&m_file.isWritable()){
            QTextStream logStream(&m_file);
            logStream<<QDateTime::currentDateTime().toString("yyy-MM-dd hh:mm:ss")<<" ";
            logStream<<level<<": "<<message<<endl;
        }else{
            qWarning()<<"Cannot write to Logger File.";
        }
        QTextStream(stdout)<<level<<": "<<message<<endl;
    }
    QFile m_file;
};

#endif // LOGGER_H
