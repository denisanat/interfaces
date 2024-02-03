/********************************************************************************
** Form generated from reading UI file 'dtablachoques.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTABLACHOQUES_H
#define UI_DTABLACHOQUES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DTablaChoques
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *vistaChoques;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DTablaChoques)
    {
        if (DTablaChoques->objectName().isEmpty())
            DTablaChoques->setObjectName(QString::fromUtf8("DTablaChoques"));
        DTablaChoques->resize(400, 300);
        verticalLayout = new QVBoxLayout(DTablaChoques);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        vistaChoques = new QTableView(DTablaChoques);
        vistaChoques->setObjectName(QString::fromUtf8("vistaChoques"));

        verticalLayout->addWidget(vistaChoques);

        buttonBox = new QDialogButtonBox(DTablaChoques);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DTablaChoques);
        QObject::connect(buttonBox, SIGNAL(accepted()), DTablaChoques, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DTablaChoques, SLOT(reject()));

        QMetaObject::connectSlotsByName(DTablaChoques);
    } // setupUi

    void retranslateUi(QDialog *DTablaChoques)
    {
        DTablaChoques->setWindowTitle(QCoreApplication::translate("DTablaChoques", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DTablaChoques: public Ui_DTablaChoques {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTABLACHOQUES_H
