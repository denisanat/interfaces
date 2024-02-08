
#ifndef WSECUNDARIO_H
#define WSECUNDARIO_H
#include "ui_wsecundario.h"

#include <QVector>
#include <QWidget>
#include <QHBoxLayout>
#include <QString>

class WSecundario : public QWidget, public Ui::WSecundario {
Q_OBJECT

	public:
		WSecundario(QString palabra, QWidget *parent = NULL);

	public slots:
		void slotEjemplo();

};

#endif 
