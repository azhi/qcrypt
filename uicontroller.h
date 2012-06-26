#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QtCore>
#include <string>
using namespace std;

class UiController
{
public:
    UiController(QObject* root) : root(root) {}

    void setProperty(const char* objectName, const char* propertyName, const char* value);
    string getProperty(const char* objectName, const char* propertyName);
    void setPolarizationPicture(const char* objectName, bool polarization_type, bool polarization_value);


private:
    QObject* root;
};

#endif // UICONTROLLER_H
