#ifndef SETTING_H
#define SETTING_H

#include <QSettings>
#include <QDebug>
#include <QMap>
#include "Singleton.h"

class Setting:public Singleton<Setting>
{
    friend class Singleton<Setting>;
public slots:
    void SyncSetting(){
        for(auto it=m_settingMap.constBegin();it!=m_settingMap.end();++it){
            m_settings.setValue(it.key(),it.value());
        }
        m_settings.sync();
    }
public:
    void SetValue(const QString &key,const QVariant &value);
    QVariant GetValue(const QString &key,const QVariant &defalutValue=QVariant()) const;
private:
    Setting(){}
    QSettings m_settings{"BrowserSnapshotSetting.ini",QSettings::IniFormat};
    QMap<QString,QVariant> m_settingMap;
};

#endif // SETTING_H
