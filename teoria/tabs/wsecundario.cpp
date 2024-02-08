
#include "wsecundario.h"
#include <QDebug>

WSecundario::WSecundario(QString palabra, QWidget *parent): QWidget(parent){
		setupUi(this);

		label -> setText( palabra );
}


void WSecundario::slotEjemplo(){

}

