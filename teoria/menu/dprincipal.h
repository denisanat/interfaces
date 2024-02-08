#ifndef DPRINCIPAL_H
#define DPRINCIPAL_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QVector>


class DPrincipal : public QMainWindow {
Q_OBJECT

	public:
		DPrincipal( QWidget *parent = NULL );

		QAction *actionUno;
		QAction *actionDos;
		QAction *actionTres;
		
		QVector<QAction *> actions;


		void crearActions();
		void crearMenus();
		
	public slots:
		void slotUno();
		void slotDos();
		void slotTres();
		void slotActionNumero();
		
};

#endif
