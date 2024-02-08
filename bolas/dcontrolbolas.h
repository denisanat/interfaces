
#ifndef DCONTROLBOLAS_H
#define DCONTROLBOLAS_H

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>

#include "ui_dcontrolbolas.h"
#include "bola.h"

class DControlBolas : public QDialog, public Ui::DControlBolas {
Q_OBJECT

	public:
		DControlBolas( QVector<Bola*> ,QWidget *parent = NULL );

	public slots:
		void slotEjemplo();
		void slotPararTodas();
		
};

#endif 
