#include <QMenuBar>
#include <QMainWindow>
#include <QDebug>
#include <QAction>
#include <QMenu>
#include <QString>
#include <QVariant>

#include "dprincipal.h"

DPrincipal::DPrincipal( QWidget *parent ): QMainWindow( parent ) {

		crearActions();
		crearMenus();
}


void DPrincipal::crearActions() {

		actionUno = new QAction( "Uno" );
			connect(actionUno, SIGNAL( triggered()),
					this, SLOT( slotUno()));
					
		actionDos = new QAction( "Dos" );
			connect(actionDos, SIGNAL( triggered()),
					this, SLOT( slotDos()));
					
		actionTres = new QAction( "Tres" );
			connect(actionTres, SIGNAL( triggered()),
					this, SLOT( slotTres()));
					
		for ( int i = 0 ; i < 10 ; i++ ) {
			QAction *nuevo = new QAction( QString::number( i ));
				connect(nuevo, SIGNAL( triggered()),
						this, SLOT( slotActionNumero()));
						
			nuevo -> setData( QVariant( i ));
			actions.append( nuevo );
		}
}


void DPrincipal::crearMenus() {

		QMenu * primerMenu = menuBar() -> addMenu( "Primer" );
			primerMenu -> addAction( actionUno );
			primerMenu -> addAction( actionDos );
			primerMenu -> addAction( actionTres );
			
		QMenu * segundoMenu = menuBar() -> addMenu( "Segundo" );
			for ( int i = 0 ; i < 10 ; i++ ) {
				QAction * action = actions.at( i );
				segundoMenu -> addAction( action );
			}
}


// SLOTS
void DPrincipal::slotUno() {

		qDebug() << "Uno";
}


void DPrincipal::slotDos() {

		qDebug() << "Dos";
}


void DPrincipal::slotTres() {

		qDebug() << "Tres";
}


void DPrincipal::slotActionNumero() {

		QObject * objCulpable = sender();
		QAction * accCulpable = qobject_cast<QAction *> ( objCulpable );
		
		int i = accCulpable -> data().toInt(); 

		qDebug() << QString::number( i );
}
