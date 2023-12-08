#include <QMouseEvent>
#include <videoWidget.h>

VideoWidget::VideoWidget(QWidget *parent)
{
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    QPalette p = palette();
    p.setColor(QPalette::Window, Qt::black);
    setPalette(p);
    setAttribute(Qt::WA_OpaquePaintEvent);
}
void VideoWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Escape: //нажат Escape;
        setFullScreen(false);
        break;
    case Qt::Key_Up: //нажата Up;
        break;
        //... default:
        QVideoWidget::keyPressEvent(event);
        break;
    }
}
void VideoWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    setFullScreen(!isFullScreen());
    event->accept();
}
