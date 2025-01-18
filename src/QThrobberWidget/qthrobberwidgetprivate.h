#ifndef QTHROBBERWIDGETPRIVATE_H
#define QTHROBBERWIDGETPRIVATE_H

#include <QObject>

class QThrobberWidget;

class QThrobberWidgetPrivate : public QObject
{
        Q_OBJECT
        friend QThrobberWidget;

    public:
        qreal throbberRotation() const { return m_throbberRotation; }

        qreal throbberLength() const { return m_throbberLength; }

        qreal innerThrobberRotation() const { return m_innerThrobberRotation; }

        qreal iconScale() const { return m_iconScale; }

        qreal iconOpacity() const { return m_iconOpacity; }

    public slots:
        void setThrobberRotation(qreal throbberRotation);

        void setThrobberLength(qreal throbberLength);

        void setInnerThrobberRotation(qreal innerThrobberRotation);

        void setIconScale(qreal iconScale);

        void setIconOpacity(qreal iconOpacity);

    signals:

        void throbberRotationChanged();

        void throbberLengthChanged();

        void innerThrobberRotationChanged();

        void iconScaleChanged();

        void iconOpacityChanged();

    private:
        explicit QThrobberWidgetPrivate(QObject *parent = nullptr);

        qreal m_throbberRotation = 0;
        qreal m_throbberLength = -270;
        qreal m_innerThrobberRotation = (360 * 16);

        qreal m_iconScale = 1;
        qreal m_iconOpacity = 1;

        Q_PROPERTY(
            qreal throbberRotation READ throbberRotation WRITE setThrobberRotation NOTIFY
                throbberRotationChanged FINAL)
        Q_PROPERTY(
            qreal throbberLength READ throbberLength WRITE setThrobberLength NOTIFY
                throbberLengthChanged FINAL)
        Q_PROPERTY(
            qreal innerThrobberRotation READ innerThrobberRotation WRITE setInnerThrobberRotation
                NOTIFY innerThrobberRotationChanged FINAL)
        Q_PROPERTY(
            qreal iconScale READ iconScale WRITE setIconScale NOTIFY iconScaleChanged FINAL)
        Q_PROPERTY(
            qreal iconOpacity READ iconOpacity WRITE setIconOpacity NOTIFY iconOpacityChanged FINAL)
};

#endif // QTHROBBERWIDGETPRIVATE_H
