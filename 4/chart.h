#ifndef CHART_H
#define CHART_H

#include <QColor>
#include <QObject>
#include <QVector>

class Chart : public QObject {
  Q_OBJECT
  Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
  Q_PROPERTY(QString parameterName READ parameterName WRITE setParameterName
                 NOTIFY parameterNameChanged)
  Q_PROPERTY(ChartType chartType READ chartType WRITE setChartType NOTIFY
                 chartTypeChanged)
  Q_PROPERTY(QVector<double> xValues READ xValues CONSTANT)
  Q_PROPERTY(QVector<double> yValues READ yValues NOTIFY yValuesChanged)

public:
  enum ChartType { SIN, LIN, ARI, SQR, LOG };
  Q_ENUM(ChartType)

  Chart(QObject *parent = nullptr);

  QColor color() const;
  void setColor(const QColor &color);

  QString parameterName() const;
  void setParameterName(const QString &name);

  ChartType chartType() const;
  void setChartType(ChartType type);

  QVector<double> xValues() const;

  QVector<double> yValues() const;
  void calculateYValues();

signals:
  void colorChanged();
  void parameterNameChanged();
  void chartTypeChanged();
  void yValuesChanged();

private:
  QColor m_color;
  QString m_parameterName;
  ChartType m_chartType;
  QVector<double> m_xValues;
  QVector<double> m_yValues;
};
#endif // CHART_H
