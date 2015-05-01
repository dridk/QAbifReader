# QAbifReader
Qt5 ABIF file reader for Genetic Analysis i
======================================

[![Join the chat at https://gitter.im/papyros/qml-material](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/papyros/qml-material?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

[![License](https://img.shields.io/badge/license-LGPLv2.1%2B-blue.svg)](https://img.shields.io/badge/license-LGPL%203%2B-blue.svg)

QAbifReader is a library to load data from an abif file following the specification of [Abif file format](http://www6.appliedbiosystems.com/support/software_community/ABIF_File_Format.pdf).
It allows you to read all content of ab1 and fsa file. But it doesn't provide any widget to show data. You can do it easily using 
[QCustomPlot](http://www.qcustomplot.com/index.php/demos/datedemo)

### Dependencies

Requires Qt 5.4 or higher 
Not tested on previous version, but it should work.

### Installation

Just copy abifreader.cpp and abifreader.h to your main project 


## Use

    AbifReader reader("file.fsa")
    reader.data("Peak.1") 
  
  
## Full example 

  #include <QApplication>
  #include "qcustomplot.h"
  #include "abireader.h"
  
  int main(int argc, char *argv[])
  {

      QApplication a(argc, argv);
      QCustomPlot * customPlot = new QCustomPlot;
     
      AbifReader r = AbifReader("/home/sacha/temp/M.fsa");
      QVariantList list = r.data("DATA.1").toList(); 

      QVector<double> x(list.size()), y(list.size());
      QVector<double> y(list.size());

      for (int i=0; i<list.size(); ++i)
      {
          x[i] = i;
          y[i] = list.at(i).toDouble();
      }
      customPlot->addGraph();
      customPlot->graph(0)->setData(x, y);
  
      // give the axes some labels:
      customPlot->xAxis->setLabel("x");
      customPlot->yAxis->setLabel("y");
      
      customPlot->setInteraction(QCP::iRangeZoom,true);
      customPlot->setInteraction(QCP::iRangeDrag,true);
      customPlot->replot();
      customPlot->rescaleAxes();
      customPlot->show();
      customPlot->resize(800,400);
      return a.exec();
  }