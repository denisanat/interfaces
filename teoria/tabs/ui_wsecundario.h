/********************************************************************************
** Form generated from reading UI file 'wsecundario.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WSECUNDARIO_H
#define UI_WSECUNDARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WSecundario
{
public:
    QLabel *label;

    void setupUi(QWidget *WSecundario)
    {
        if (WSecundario->objectName().isEmpty())
            WSecundario->setObjectName(QString::fromUtf8("WSecundario"));
        WSecundario->resize(400, 300);
        label = new QLabel(WSecundario);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 70, 67, 17));

        retranslateUi(WSecundario);

        QMetaObject::connectSlotsByName(WSecundario);
    } // setupUi

    void retranslateUi(QWidget *WSecundario)
    {
        WSecundario->setWindowTitle(QCoreApplication::translate("WSecundario", "Form", nullptr));
        label->setText(QCoreApplication::translate("WSecundario", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WSecundario: public Ui_WSecundario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WSECUNDARIO_H
