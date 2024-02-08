#include <QApplication>

#include "dprincipal.h"

int main(int argc, char *argv[])
{
     QApplication app(argc, argv);
     
  	 DPrincipal * window = new DPrincipal();
  	 
  	 window -> show();
     
     return app.exec();
}
