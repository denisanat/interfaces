
#include "wcontrolbola.h"
#include <QDebug>

WControlBola::WControlBola(Bola * bPasada, QWidget *parent): QWidget(parent),miBola(bPasada) {
		setupUi(this);

		miBola = bPasada;
		
			// crea un boton por cada bola con la que puede chocar que deja los choques entre ella a 0
		QHBoxLayout * layoutBotones = new QHBoxLayout();
			for ( int i = 0 ; i < miBola -> choques.size() ; i++ ) {
				QPushButton * nB = new QPushButton( QString::number(i) );
				layoutBotones -> addWidget(nB);
				botonesParar.append(nB);
				connect(nB,SIGNAL(clicked()),
						this,SLOT(slotBotonParar()));
			}
		
			// el layout que hemos creado con todos los botones lo estacamos en el frame
		fBotonesChoques -> setLayout( layoutBotones );
		
		connect(bParar, SIGNAL(clicked()),
				this, SLOT(slotParar()));
			
		leNombre -> setFocus();
		leNombre -> setText( bPasada -> nombre ); // por defect el line edit tendra el nombre de la bola
			connect(leNombre,SIGNAL(textChanged(const QString &)),
					this,SLOT(slotCambiarNombre(const QString &)));
}


void WControlBola::slotParar(){

		miBola -> velX = miBola -> velY = 0;
}


void WControlBola::slotEjemplo(){

}


void WControlBola::slotBotonParar(){

			// sender() devuelve un puntero del objeto que ha enviado la señal
		QPushButton * bCulpable = qobject_cast<QPushButton*>( sender() ); // lo parseamos a un QPushButton
			 
		for ( int i = 0 ; i < botonesParar.size() ; i++ )
			if ( botonesParar.at(i) == bCulpable )
				miBola -> choques[i] = 0 ;
}


void WControlBola::slotCambiarNombre(const QString &cad){

	miBola -> nombre = cad;
}


