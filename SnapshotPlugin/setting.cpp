#include "setting.h"

void Setting::SetValue(const QString &key,const QVariant &value){
    m_settingMap[key]=value;
}
QVariant Setting::GetValue(const QString &key,const QVariant &defalutValue) const{
    return m_settings.value(key,defalutValue);
}
