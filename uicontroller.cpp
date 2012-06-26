#include "uicontroller.h"
#include <QString>
#include <QEvent>
#include <iostream>

void UiController::setProperty(const char* objectName, const char* propertyName, const char* value)
{
    root->findChild<QObject*>(objectName)->setProperty(propertyName, QString(value));
}

string UiController::getProperty(const char* objectName, const char* propertyName)
{
    return root->findChild<QObject*>(objectName)->property(propertyName).toString().toStdString();
}

void UiController::clearLog()
{
    setProperty("sys_log", "text", "");
}

void UiController::writeToLog(const char* msg)
{
    string text = getProperty("sys_log", "text");
    if ( !text.empty() )
        text.append("\n");
    text.append(msg);
    setProperty("sys_log", "text", text.c_str());
    refreshForm();
}

void UiController::refreshForm(void)
{
    qApp->processEvents();
}
