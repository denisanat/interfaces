/********************************************************************************
** Form generated from reading UI file 'wcontrolbola.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WCONTROLBOLA_H
#define UI_WCONTROLBOLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WControlBola
{
public:
    QPushButton *bParar;
    QLineEdit *leNombre;
    QPushButton *bColor;
    QFrame *fBotonesChoques;

    void setupUi(QWidget *WControlBola)
    {
        if (WControlBola->objectName().isEmpty())
            WControlBola->setObjectName(QString::fromUtf8("WControlBola"));
        WControlBola->resize(397, 183);
        bParar = new QPushButton(WControlBola);
        bParar->setObjectName(QString::fromUtf8("bParar"));
        bParar->setGeometry(QRect(20, 20, 80, 25));
        leNombre = new QLineEdit(WControlBola);
        leNombre->setObjectName(QString::fromUtf8("leNombre"));
        leNombre->setGeometry(QRect(20, 60, 81, 25));
        bColor = new QPushButton(WControlBola);
        bColor->setObjectName(QString::fromUtf8("bColor"));
        bColor->setGeometry(QRect(20, 120, 80, 25));
        fBotonesChoques = new QFrame(WControlBola);
        fBotonesChoques->setObjectName(QString::fromUtf8("fBotonesChoques"));
        fBotonesChoques->setGeometry(QRect(110, 20, 261, 80));
        fBotonesChoques->setFrameShape(QFrame::StyledPanel);
        fBotonesChoques->setFrameShadow(QFrame::Raised);

        retranslateUi(WControlBola);

        QMetaObject::connectSlotsByName(WControlBola);
    } // setupUi

    void retranslateUi(QWidget *WControlBola)
    {
        WControlBola->setWindowTitle(QCoreApplication::translate("WControlBola", "Form", nullptr));
        bParar->setText(QCoreApplication::translate("WControlBola", "Parar", nullptr));
        bColor->setText(QCoreApplication::translate("WControlBola", "Color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WControlBola: public Ui_WControlBola {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WCONTROLBOLA_H
