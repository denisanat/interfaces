#include <QDebug>
#include <QVector>
#include <QColor>
#include <QString>

#include "tablaidol.h"
#include "idol.h"


TablaIdol::TablaIdol(QWidget *parent): QDialog(parent){
		setupUi(this);
		
		crearIdols( "heejin", "loona", 24, QColor( 200 , 160 , 160 ));
		crearIdols( "nayeon", "twice", 26, QColor( 250 , 200 , 200 ));
		crearIdols( "gowon", "loona", 23, QColor( 230 , 245 , 250 ));

		modelo = new ModeloTabla();
			modelo -> idols = idols;
		
		vista -> setModel( modelo );
}


void TablaIdol::crearIdols( QString nombre, QString grupo, int edad, QColor color ) {
		
		Idol idol;
			idol.nombre = nombre;
			idol.grupo = grupo;
			idol.edad = edad;
			idol.color = color;
		
		idols.append( idol );
		
}


		// el numero de filas que habrá en la tabla
int	ModeloTabla::rowCount( const QModelIndex &parent ) const { 
	
		return idols.size();
}

		// el numero de columnas que habrá en la tabla
int	ModeloTabla::columnCount( const QModelIndex &parent ) const {

		return 3;
}


		// el valor de cada casilla
QVariant ModeloTabla::data( const QModelIndex &index, int role ) const { 
		
		int columna = index.column();
		int fila = index.row();
		
			// hace que se coloree la casilla
		if ( role == Qt::BackgroundColorRole )
				return QVariant( idols.at(fila).color );
		
			// quita la checkbox
		if ( role != Qt::DisplayRole )
				return QVariant();
		
		Idol idol = idols.at( fila );
		QString valor;
		
		switch ( columna ) {
			case 0:
					valor = idol.nombre;
					break;
			case 1:
					valor = QString::number( idol.edad );
					break;
			case 2:
					valor = idol.grupo;
					break;
		};
					
		return QVariant( valor );
}


		// nos permite seleccionar la casilla para modificarla
Qt::ItemFlags ModeloTabla::flags( const QModelIndex &index ) const {

		return Qt::ItemIsEditable | QAbstractTableModel::flags( index );
}


		// cambia el encabezado de las filas y las columnas
QVariant ModeloTabla::headerData( int section, Qt::Orientation orientation, int role ) const {

		QStringList lista = { "Nombre", "Edad", "Grupo" };
		
		if ( role != Qt::DisplayRole ) 
			return QVariant();
			
		if ( orientation == Qt::Horizontal )
			return QVariant( lista.at( section ));

		if ( orientation = Qt::Vertical ) {
			QString cadena = QString( "Idol " ) + QString::number( section );
			return cadena;
		}

}

		// una vez seleccionemos una casilla, podemos guardar valores
bool ModeloTabla::setData( const QModelIndex &index, const QVariant &value, int role ) {

		return true;
}

