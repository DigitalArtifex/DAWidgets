#ifndef QMASKEDBUTTONPRIVATE_H
#define QMASKEDBUTTONPRIVATE_H

#include <QObject>

class QMaskedButton;
#include "dalib_global.h"

class DA_EXPORT QMaskedButtonPrivate : public QObject
{
        Q_OBJECT
        friend class QMaskedButton;

    public:

    private slots:
        void setHoverOpacity(qreal hoverOpacity);

        void setClickOpacity(qreal clickOpacity);

        void setOpacity(qreal opacity);

    signals:

        void hoverOpacityChanged();

        void clickOpacityChanged();

        void opacityChanged();

    protected slots:

    private:

        explicit QMaskedButtonPrivate(QObject *parent = nullptr);

        qreal hoverOpacity() const { return m_hoverOpacity; }

        qreal clickOpacity() const { return m_clickOpacity; }

        qreal opacity() const { return m_opacity; }

        qreal m_hoverOpacity = 0.0;
        qreal m_clickOpacity = 0.0;
        qreal m_opacity = 1.0;

        Q_PROPERTY(
            qreal hoverOpacity READ hoverOpacity WRITE setHoverOpacity NOTIFY hoverOpacityChanged
                FINAL)
        Q_PROPERTY(
            qreal clickOpacity READ clickOpacity WRITE setClickOpacity NOTIFY clickOpacityChanged
                FINAL)
        Q_PROPERTY(
            qreal opacity READ opacity WRITE setOpacity NOTIFY opacityChanged FINAL)
};

#endif // QMASKEDBUTTONPRIVATE_H
