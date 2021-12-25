#include <QApplication>
#include <QPlainTextEdit>
#include <QWebEngineView>
#include <QHBoxLayout>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto *redactorWindow = new QWidget;
    auto *htmlEdit = new QPlainTextEdit;
    auto *webView = new QWebEngineView;
    auto *hbox = new QHBoxLayout(redactorWindow);

    hbox->addWidget(htmlEdit);
    hbox->addWidget(webView);

    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(1);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(htmlEdit->sizePolicy().hasHeightForWidth());

    htmlEdit->setSizePolicy(sizePolicy);
    webView->setSizePolicy(sizePolicy);
    webView->setUrl(QUrl(QString::fromUtf8("about:blank")));

    QObject::connect(htmlEdit, &QPlainTextEdit::textChanged, [htmlEdit, webView]() {
        webView->setHtml(htmlEdit->toPlainText());
    });
    redactorWindow->show();
    return a.exec();
}
#include "main.moc"
