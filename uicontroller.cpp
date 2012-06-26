#include "uicontroller.h"
#include <QString>

void UiController::setProperty(const char* objectName, const char* propertyName, const char* value)
{
    root->findChild<QObject*>(objectName)->setProperty(propertyName, QString(value));
}

string UiController::getProperty(const char* objectName, const char* propertyName)
{
    return root->findChild<QObject*>(objectName)->property(propertyName).toString().toStdString();
}
