/** Copyright 2014 Rian Shelley */
#ifndef GENERATEDSTRUCTURE_H_
#define GENERATEDSTRUCTURE_H_

#include <QSharedPointer>
#include <QString>
#include "./overlayitem.h"

class Tag;
class QColor;

class GeneratedStructure: public OverlayItem {
 public:
  static QList<QSharedPointer<GeneratedStructure>> tryParse(const Tag* tag);

  virtual bool intersects(const Point& min, const Point& max) const;
  virtual void draw(double offsetX, double offsetZ, double scale,
                   QPainter *canvas) const;
  virtual Point midpoint() const;

 protected:
  GeneratedStructure() {}

  // these are used to draw a rounded rect. If you want to draw something
  // else, override draw()
  void setBounds(const Point& min, const Point& max) {p1 = min; p2 = max;}

  static const int RADIUS = 10;

 private:
  Point p1, p2;
};

#endif  // GENERATEDSTRUCTURE_H_
