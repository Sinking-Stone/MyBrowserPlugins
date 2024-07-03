#include "SnapshotPlugin.h"
#include <QDebug>
#include <QQuickItem>
#include <QQuickWindow>
#include <QDateTime>
#include <QImage>
#include <QDir>
#include <QGuiApplication>
#include "logger.h"
#include "setting.h"

SnapshotPlugin::SnapshotPlugin(QObject* parent):QObject(parent)
{
    m_type="snapshot";
    QVariant savePathQ=Setting::GetInstance().GetValue("SavePath");
    if(savePathQ.isValid()){
        m_savePath=savePathQ.toString();
    }else{
        m_savePath="./plugins/snapshot/";
    }
}
SnapshotPlugin::~SnapshotPlugin(){
    Setting::GetInstance().SetValue("SavePath","./plugins/snapshot/");
    Setting::GetInstance().SyncSetting();
}
QString SnapshotPlugin::performAction(QObject* item,const QString &input){
    Q_UNUSED(item);
    Q_UNUSED(input);

    QString strFileNamePath=QDir::currentPath();
    strFileNamePath+=m_savePath;
    QDir targetDir(strFileNamePath);
    if(!targetDir.exists()){
        if(targetDir.mkpath(".")){
            qDebug()<<"make the dir: "<<strFileNamePath;
        }else{
            Logger::GetInstance().LogError("Error to make dir: "+strFileNamePath);
            return "Error to make dir";
        }
    }
    auto window=qobject_cast<QQuickWindow*>(QGuiApplication::focusWindow());    // 获得窗体
    if(!window){
        Logger::GetInstance().LogError("We could not find the window to snapshot:"+strFileNamePath);
        return "We could not find the window to snapshot.";
    }
    QImage screenshot=window->grabWindow();     // 获得窗体的截图
    QString strFileName2Save=QDateTime::currentDateTime().toString("yyyyMMddHHmmss")+"browser.png";
    strFileNamePath+=strFileName2Save;
    if(screenshot.save(strFileNamePath)){       // 保存图像
        Logger::GetInstance().LogInfo("Do snapshot successful, file name: "+strFileNamePath);
        return strFileNamePath;
    }else{
        Logger::GetInstance().LogError("Error to save image "+strFileNamePath);
        return "Error to save image.";
    }
}
bool SnapshotPlugin::isKindOf(const QString &type){
    return m_type==type;
}
