#ifndef BROWSERPLUGININTERFACE_H
#define BROWSERPLUGININTERFACE_H

#include <QObject>
#include <QString>

class BrowserPluginInterface{
public:
    virtual QString performAction(QObject *item,const QString &input)=0;
    virtual bool isKindOf(const QString &type)=0;
    virtual ~BrowserPluginInterface(){}
};

#define BrowserPluginInterface_IID "org.myBrowser.BrowserPluginInterface"

// https://blog.csdn.net/hebbely/article/details/72830043
// 定义了接口ID查找函数和几个QObject到接口的转换函数
Q_DECLARE_INTERFACE(BrowserPluginInterface,BrowserPluginInterface_IID)

#endif // BROWSERPLUGININTERFACE_H
