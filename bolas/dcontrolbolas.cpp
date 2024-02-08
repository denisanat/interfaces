#include <QDebug>
#include <QPushButton>

#include "dcontrolbolas.h"
#include "wcontrolbola.h"

DControlBolas::DControlBolas(QVector<Bola*> bPasadas , QWidget *parent): QDialog(parent){
		setupUi(this);

		tabBolas->clear();
		
		for ( int i = 0 ; i < bPasadas.size() ; i++ ){
			
			WControlBola *w = new WControlBola( bPasadas.at(i) );
			tabBolas->addTab(w, bPasadas.at(i) -> nombre);
		}
		
		connect(bPararTodas, SIGNAL(clicked()),
				this, SLOT(slotPararTodas()));
				
				
		/* accedemos al widget que tiene cada tab y ponemos el focus en el line edit */
		
		QWidget * w = tabBolas -> widget( 0 ); // accedemos al widget que tiene cada tab
		WControlBola * wcb = qobject_cast<WControlBola*>( w ); // lo casteamos a un WControlBola
			wcb -> leNombre -> setFocus(); // ponemos el focus al line edit
}


void DControlBolas::slotEjemplo(){

}


void DControlBolas::slotPararTodas(){

		for ( int i = 0 ; i < tabBolas -> count() ; i++ ) {
		
			QWidget * w = tabBolas -> widget(i);
			WControlBola * wcb = qobject_cast<WControlBola*>(w);
				wcb -> bParar -> animateClick( 500 );
		}	 
}








