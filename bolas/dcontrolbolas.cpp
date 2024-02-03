
#include "dcontrolbolas.h"
#include <QDebug>
#include <QPushButton>
#include "wcontrolbola.h"

DControlBolas::DControlBolas(QVector<Bola*> bPasadas , QWidget *parent): QDialog(parent){
		setupUi(this);

	
		tabBolas->clear();
		
		for (int i = 0 ; i < bPasadas.size() ; i++){
			
			WControlBola *w = new WControlBola( bPasadas.at(i) );
			tabBolas->addTab(w, bPasadas.at(i)->nombre);
		}
		
		connect(bPararTodas,SIGNAL(clicked()),
				this,SLOT(slotPararTodas()));
				
		QWidget * w =	tabBolas->widget(0);
		WControlBola * wcb = qobject_cast<WControlBola*>(w);
		wcb->leNombre->setFocus();
}


void DControlBolas::slotEjemplo(){

}


void DControlBolas::slotPararTodas(){

		for (int i = 0 ; i < tabBolas->count() ; i++){
			QWidget * w =	tabBolas->widget(i);
			WControlBola * wcb = qobject_cast<WControlBola*>(w);
			
			wcb->bParar->animateClick(500);


	 }
	 
}








