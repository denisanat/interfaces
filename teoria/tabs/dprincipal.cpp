
#include "dprincipal.h"
#include <QDebug>
#include <QVector>
#include <QString>

#include "wsecundario.h"

DPrincipal::DPrincipal(QWidget *parent): QDialog(parent){
		setupUi(this);

		QVector<QString> palabras = { "hey", "muy", "buenas", "a", "todos", "guapisimos" };
		
		tabWidget -> clear();
		
		for ( int i = 0 ; i < palabras.size() ; i++ ) {
			WSecundario * widget = new WSecundario( palabras.at( i ));
			tabWidget -> addTab( widget, QString::number( i ));
		}
}


void DPrincipal::slotEjemplo(){

}

