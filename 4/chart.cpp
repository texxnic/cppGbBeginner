#include <chart.h>

Chart::Chart(QObject *parent) {
  m_xValues = {1, 2, 3, 4};
  m_yValues = {2, 3, 4, 5};
};

void Chart::calculateYValues() {
  m_yValues.clear();
  if (m_chartType == ChartType::LIN) {
    m_yValues = m_xValues;
  }
  for (auto &element : m_xValues) {
    switch (m_chartType) {
    case ChartType::SIN:
      m_yValues.push_back(sin(element));
      break;
    case ChartType::ARI:
      m_yValues.push_back(abs(element - 2.5));
      break;
    case ChartType::SQR:
      m_yValues.push_back(sqrt(element));
      break;
    case ChartType::LOG:
      m_yValues.push_back(log2(element));
      break;
    default:
      break;
    }
  }
}

QVector<double> Chart::xValues() const { return m_xValues; }

QVector<double> Chart::yValues() const { return m_yValues; }

QColor Chart::color() const { return m_color; }

void Chart::setColor(const QColor &color) { m_color = color; };

QString Chart::parameterName() const { return m_parameterName; };
void Chart::setParameterName(const QString &name) { m_parameterName = name; };
Chart::ChartType Chart::chartType() const { return m_chartType; };
void Chart::setChartType(ChartType type) { m_chartType = type; };
