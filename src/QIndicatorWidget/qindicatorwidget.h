#ifndef QINDICATORWIDGET_H
#define QINDICATORWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPropertyAnimation>
#include <QPainter>

#include "dalib_global.h"
#include "qindicatorwidgetprivate.h"

class DA_EXPORT QIndicatorWidget : public QWidget
{
        Q_OBJECT
    public:
        enum class State
        {
            Off,
            On,
            Blinking
        };

        explicit QIndicatorWidget(QWidget *parent = nullptr);

        State state() const
        {
            return m_state;
        }

        QColor backgroundColor() const
        {
            return m_backgroundColor;
        }

        QColor indicatorColor() const
        {
            return m_indicatorColor;
        }

        QColor indicatorBackgroundColor() const
        {
            return m_indicatorBackgroundColor;
        }

        qint8 broderWidth() const
        {
            return m_broderWidth;
        }

        QColor borderColor() const
        {
            return m_borderColor;
        }

        qint8 indicatorBorderWidth() const
        {
            return m_indicatorBorderWidth;
        }

        QColor indicatorBorderColor() const
        {
            return m_indicatorBorderColor;
        }

    public slots:

        void setState(State state);

        void setBackgroundColor(const QColor &backgroundColor);

        void setIndicatorColor(const QColor &indicatorColor);

        void setIndicatorBackgroundColor(const QColor &indicatorBackgroundColor);

        void setBroderWidth(qint8 broderWidth);

        void setBorderColor(const QColor &borderColor);

        void setIndicatorBorderWidth(qint8 indicatorBorderWidth);

        void setIndicatorBorderColor(const QColor &indicatorBorderColor);

    protected slots:
        void onIndicatorOpacityChanged();

    signals:

        void stateChanged();

        void backgroundColorChanged();

        void indicatorColorChanged();

        void indicatorBackgroundColorChanged();

        void broderWidthChanged();

        void borderColorChanged();

        void indicatorBorderWidthChanged();

        void indicatorBorderColorChanged();

    protected:
        virtual void paintEvent(QPaintEvent *event) override;

    private:
        QIndicatorWidgetPrivate *m_private = nullptr;

        State m_state = State::Off;

        QColor m_backgroundColor = QColor(0,0,0,0);

        qint8 m_broderWidth = 0;
        QColor m_borderColor = QColor(0,0,0,0);

        QColor m_indicatorBackgroundColor = QColor(0,0,0);
        QColor m_indicatorColor = QColor(48,183,224);
        qint8 m_indicatorBorderWidth = 2;
        QColor m_indicatorBorderColor = QColor(128,128,128);

        Q_ENUM(State)

        Q_PROPERTY(State state READ state WRITE setState NOTIFY stateChanged FINAL)
        Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged FINAL)
        Q_PROPERTY(QColor indicatorColor READ indicatorColor WRITE setIndicatorColor NOTIFY indicatorColorChanged FINAL)
        Q_PROPERTY(QColor indicatorBackgroundColor READ indicatorBackgroundColor WRITE setIndicatorBackgroundColor NOTIFY indicatorBackgroundColorChanged FINAL)
        Q_PROPERTY(qint8 broderWidth READ broderWidth WRITE setBroderWidth NOTIFY broderWidthChanged FINAL)
        Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor NOTIFY borderColorChanged FINAL)
        Q_PROPERTY(qint8 indicatorBorderWidth READ indicatorBorderWidth WRITE setIndicatorBorderWidth NOTIFY indicatorBorderWidthChanged FINAL)
        Q_PROPERTY(QColor indicatorBorderColor READ indicatorBorderColor WRITE setIndicatorBorderColor NOTIFY indicatorBorderColorChanged FINAL)
};

Q_DECLARE_METATYPE(QIndicatorWidget)

#endif // QINDICATORWIDGET_H
