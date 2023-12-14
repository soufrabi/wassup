#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QWebEngineView>
#include <QWebEngineProfile>
#include <QWebEngineSettings>
#include <QWebEnginePage>
#include <QWebEngineDownloadRequest>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QVBoxLayout *vbox_main = new QVBoxLayout(this);
    ui->centralwidget->setLayout(vbox_main);
    std::string url_whatsapp = "https://web.whatsapp.com";
    std::string url_duckduckgo = "https://duckduckgo.com" ;
    std::string url_test1 = "https://github.com/neovim/neovim/releases" ;

    QUrl url = QUrl(QString::fromStdString(url_whatsapp));

    const std::string user_agent_firefox_linux115 = "Mozilla/5.0 (X11; Linux x86_64; rv:109.0) Gecko/20100101 Firefox/115.0";
    QString user_agent = QString::fromStdString(user_agent_firefox_linux114);
    QWebEngineView *view = new QWebEngineView(parent);
//    view->load(url);
//    view->show();

//    QWebEngineProfile *profile = new QWebEngineProfile();
//     profile->setHttpUserAgent(user_agent);


    QWebEngineProfile::defaultProfile()->settings()->setAttribute(QWebEngineSettings::PluginsEnabled, true);
    QWebEngineProfile::defaultProfile()->settings()->setAttribute(QWebEngineSettings::DnsPrefetchEnabled, true);
    QWebEngineProfile::defaultProfile()->setHttpUserAgent(user_agent);


//    QWebEnginePage *page = new QWebEnginePage(profile);
//    page->setUrl(url);
//    view->setPage(page);
     view->load(url);



    vbox_main->addWidget(view);




}


MainWindow::~MainWindow()
{
    delete ui;
}



