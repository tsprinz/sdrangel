#ifndef INCLUDE_RTLSDRPLUGIN_H
#define INCLUDE_RTLSDRPLUGIN_H

#include <QObject>
#include "plugin/plugininterface.h"

class PluginAPI;

#define RTLSDR_DEVICE_TYPE_ID "sdrangel.samplesource.rtlsdr"

class RTLSDRPlugin : public QObject, public PluginInterface {
	Q_OBJECT
	Q_INTERFACES(PluginInterface)
	Q_PLUGIN_METADATA(IID RTLSDR_DEVICE_TYPE_ID)

public:
	explicit RTLSDRPlugin(QObject* parent = NULL);

	const PluginDescriptor& getPluginDescriptor() const;
	void initPlugin(PluginAPI* pluginAPI);

	virtual SampleSourceDevices enumSampleSources();
	virtual PluginGUI* createSampleSourcePluginGUI(const QString& sourceId, QWidget **widget, DeviceAPI *deviceAPI);

	static const QString m_deviceTypeID;

private:
	static const PluginDescriptor m_pluginDescriptor;
};

#endif // INCLUDE_RTLSDRPLUGIN_H
