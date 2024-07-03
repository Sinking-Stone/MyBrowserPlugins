#ifndef SNAPSHOTPLUGIN_H
#define SNAPSHOTPLUGIN_H

#include "SnapshotPlugin_global.h"
#include "BrowserPluginInterface.h"

class SNAPSHOTPLUGIN_EXPORT SnapshotPlugin:public QObject,BrowserPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID BrowserPluginInterface_IID);
    Q_INTERFACES(BrowserPluginInterface);
public:
    explicit SnapshotPlugin(QObject* parent=nullptr);
    QString performAction(QObject* item,const QString &input) override;
    bool isKindOf(const QString &type) override;
    ~SnapshotPlugin();
private:
    QString m_type;
    QString m_savePath;
};

#endif // SNAPSHOTPLUGIN_H
