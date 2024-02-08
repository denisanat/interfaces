
#ifndef DPRINCIPAL_H
#define DPRINCIPAL_H
#include "ui_dprincipal.h"

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

class DPrincipal : public QDialog, public Ui::DPrincipal {
Q_OBJECT

	public:
		DPrincipal(QWidget *parent = NULL);

	public slots:
		void slotEjemplo();

};

#endif 
