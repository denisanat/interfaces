#ifndef TABLAIDOL_H
#define TABLAIDOL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QDialog>
#include <QHBoxLayout>
#include <QModelIndex>

#include "ui_tablaidol.h"
#include "idol.h"


// 1. creamos un dialogo con un QTableView dentro
// 2. creamos una clase interna que herede de QAbstractTableModel y la declaramos antes de la clase principal
// 3. implementar los metodos virtuales de la clase de la tabla: rowCount, columnCount, data

class ModeloTabla;

class TablaIdol : public QDialog, public Ui::TablaIdol {
Q_OBJECT

	public:
		TablaIdol(QWidget *parent = NULL);
		
		ModeloTabla * modelo;
		QVector<Idol> idols;
		
		void crearIdols( QString nombre, QString grupo, int edad, QColor color );

};


class ModeloTabla : public QAbstractTableModel {

	public:
		QVector<Idol> idols;
		
		int	rowCount( const QModelIndex &parent = QModelIndex() ) const;
		int	columnCount( const QModelIndex &parent = QModelIndex() ) const;
		QVariant data( const QModelIndex &index, int role = Qt::DisplayRole ) const;
		
		Qt::ItemFlags flags(const QModelIndex &index) const;
		
		QVariant headerData( int section, Qt::Orientation orientation, int role ) const;
		
		bool setData( const QModelIndex &, const QVariant &, int role = Qt::EditRole );

};

#endif 
