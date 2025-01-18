#ifndef QGAUGEWIDGETPRIVATE_H
#define QGAUGEWIDGETPRIVATE_H

#include <QObject>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

class QGaugeWidget;

class QGaugeWidgetPrivate : public QObject
{
        Q_OBJECT
        friend QGaugeWidget;

    public:

    public slots:

    signals:

        void progressChanged();

        void displayedValueChanged();

    private slots:
        void setProgress(qreal progress);

        void setDisplayedValue(qreal displayedValue);

    private:
        explicit QGaugeWidgetPrivate(QObject *parent = nullptr);
        ~QGaugeWidgetPrivate();

        qreal progress() const { return m_progress; }

        qreal displayedValue() const { return m_displayedValue; }

        qreal m_progress = 0.00; // progress 0.0 to 1.0
        qreal m_displayedValue = 0.00; //for animating value text display

        Q_PROPERTY(
            qreal progress READ progress WRITE setProgress NOTIFY progressChanged FINAL)
        Q_PROPERTY(
            qreal displayedValue READ displayedValue WRITE setDisplayedValue NOTIFY
                displayedValueChanged FINAL)
};

#endif // QGAUGEWIDGETPRIVATE_H
