#pragma once

#include "settings.h"
#include <QtWidgets/QMainWindow>

namespace Twig
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow();
        void LoadFile(const QString& filename);

        void dragEnterEvent(QDragEnterEvent* event);
        void dropEvent(QDropEvent* event);

    protected:
        // slots
        void About();
        void keyPressEvent(QKeyEvent* e) override;
        void Open();
        void OpenRecentFile();
        void OnReloadTriggered();

    private:
        void MakeMenus();
        void MakeHelpMenu();
        void MakeFileMenu();
        void MakeEditMenu();
        void MakeViewMenu();
        void MakeStatusBar();

        void SetCurrentFile(const QString& fileName);
        void UpdateRecentFileActions();
        static void SetClipBoard(const QString&);

        QList<QAction*> recentFileActions;
	Settings* settings;
        static constexpr int numberOfRecentFiles = 10;
    };
}
