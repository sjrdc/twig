#pragma once

#include <QtCore/QSettings>

namespace Twig
{
    class Settings : public QSettings
    {
    public:
        Settings(QObject *parent = nullptr);

        QStringList GetRecentFiles() const;
        void SetRecentFiles(const QStringList &files);

    private:
    };
}
