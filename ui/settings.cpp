#include "settings.h"

namespace Twig
{
    const QString generalSectionKey = "general";
    const QString recentFilesKey = "recentFiles";

    Settings::Settings(QObject* parent) :
        QSettings(QSettings::IniFormat, QSettings::UserScope, "twig", "twig", parent)
    {
    }

    QStringList Settings::GetRecentFiles() const
    {
        return value(recentFilesKey).toStringList();       
    }

    void Settings::SetRecentFiles(const QStringList& files)
    {
        setValue(recentFilesKey, files); 
    }
}

    
