#include "about.h"
#include "globals.h"
#include "ui_about.h"

#include <QDesktopServices>
#include <QDate>
#include <QDebug>
#include <QUrl>


About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

    QString versionBuilder = QString("version " ) + SW_VERSION;
    ui->buidDateLabel->setText(versionBuilder);

    QIcon mIcon(":pslogo.png");
    setWindowTitle("About Packet Sender");
    setWindowIcon(mIcon);

    setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);


    ui->DNLinkButton->setStyleSheet(HYPERLINKSTYLE);
    ui->DNLinkButton->setIcon( QIcon(":dannagle32.jpg"));
    ui->DNLinkButton->setFlat(true);
    ui->DNLinkButton->setCursor(Qt::PointingHandCursor);
    connect(ui->DNLinkButton, SIGNAL(clicked()),
            this, SLOT(gotoDanNagleDotCom()));


    ui->twitterButton->setStyleSheet(HYPERLINKSTYLE);
    ui->twitterButton->setIcon( QIcon(":Twitter_logo_blue.png"));
    ui->twitterButton->setFlat(true);
    ui->twitterButton->setCursor(Qt::PointingHandCursor);
    connect(ui->twitterButton, SIGNAL(clicked()),
            this, SLOT(gotoNagleCode()));


    ui->DNAmazonLinkButton->setStyleSheet(HYPERLINKSTYLE);
    ui->DNAmazonLinkButton->setFlat(true);
    ui->DNAmazonLinkButton->setCursor(Qt::PointingHandCursor);
    connect(ui->DNAmazonLinkButton, SIGNAL(clicked()),
            this, SLOT(gotoDanNaglePayPal()));


    ui->psLinkButton->setStyleSheet(HYPERLINKSTYLE);
    ui->psLinkButton->setIcon( QIcon(":pslogo.png"));
    ui->psLinkButton->setFlat(true);
    ui->psLinkButton->setCursor(Qt::PointingHandCursor);
    connect(ui->psLinkButton, SIGNAL(clicked()),
            this, SLOT(gotoPacketSenderDotCom()));




}

About::~About()
{
    delete ui;
}

void About::gotoPacketSenderDotCom()
{
    //Open URL in browser
    QDesktopServices::openUrl(QUrl("https://packetsender.com/"));

}

void About::gotoDanNagleDotCom()
{

    //Open URL in browser
    QDesktopServices::openUrl(QUrl("https://dannagle.com/"));

}


void About::gotoDanNaglePayPal()
{

    //Open URL in browser
    QDesktopServices::openUrl(QUrl("http://dannagle.com/paypal"));

}

void About::gotoNagleCode()
{
    //Open URL in browser
    QDesktopServices::openUrl(QUrl("http://twitter.com/NagleCode"));

}
