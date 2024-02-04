/********************************************************************************
** Form generated from reading UI file 'tablaidol.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLAIDOL_H
#define UI_TABLAIDOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TablaIdol
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *vista;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TablaIdol)
    {
        if (TablaIdol->objectName().isEmpty())
            TablaIdol->setObjectName(QString::fromUtf8("TablaIdol"));
        TablaIdol->resize(400, 300);
        verticalLayout = new QVBoxLayout(TablaIdol);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        vista = new QTableView(TablaIdol);
        vista->setObjectName(QString::fromUtf8("vista"));

        verticalLayout->addWidget(vista);

        buttonBox = new QDialogButtonBox(TablaIdol);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(TablaIdol);
        QObject::connect(buttonBox, SIGNAL(accepted()), TablaIdol, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TablaIdol, SLOT(reject()));

        QMetaObject::connectSlotsByName(TablaIdol);
    } // setupUi

    void retranslateUi(QDialog *TablaIdol)
    {
        TablaIdol->setWindowTitle(QCoreApplication::translate("TablaIdol", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TablaIdol: public Ui_TablaIdol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLAIDOL_H
