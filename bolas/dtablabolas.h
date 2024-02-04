#ifndef DTABLABOLAS_H
#define DTABLABOLAS_H

#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QAbstractTableModel>
#include <QModelIndex>

#include "bola.h"
#include "ui_dtablabolas.h"


class ModeloTabla;


class DTablaBolas : public QDialog, public Ui::DTablaBolas {
Q_OBJECT

	public:
		DTablaBolas( QVector<Bola*> bPasadas, QWidget * parent = NULL );

		ModeloTabla * modelo ;

	public slots:
		void slotEjemplo();
		void slotTemporizador();
		
};



class ModeloTabla : public QAbstractTableModel {

	public:
		QVector<Bola*> bolas;
		void actualiza();

		Qt::ItemFlags flags( const QModelIndex &index ) const;

		QVariant data( const QModelIndex &index, int role = Qt::DisplayRole ) const;
		
		int	rowCount( const QModelIndex &parent = QModelIndex() ) const;
		int	columnCount( const QModelIndex &parent = QModelIndex() ) const;
		
		QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
							
		bool setData( const QModelIndex &, const QVariant &, int role = Qt::EditRole );					
							
};

#endif 
