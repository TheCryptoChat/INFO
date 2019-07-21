#include "resources.h"
#include "ui_resources.h"
#include "main.h"
#include "base58.h"
#include "clientmodel.h"

#include <QPainter>
#include <QDesktopServices>
#include <QUrl>

using namespace std;

Resources::Resources(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Resources)
{
    ui->setupUi(this);
    setBaseSize(800, 524);
}

void Resources::setModel(ClientModel *model)
{
    this->model = model;
}

Resources::~Resources()
{
    delete ui;
}

void Resources::on_pushButton_bitcointalk_clicked()
{
    QString link="https://bitcointalk.org/index.php?topic=1967550.0";
    QDesktopServices::openUrl(QUrl(link));
}

void Resources::on_pushButton_infocoinfrm_clicked()
{
    QString link="https://cryptoinforum.com/";
    QDesktopServices::openUrl(QUrl(link));
}

void Resources::on_pushButton_garden_clicked()
{
    QString link="https://bitcoingarden.org/forum/index.php?topic=15531.0";
    QDesktopServices::openUrl(QUrl(link));
}

void Resources::on_pushButton_discord_clicked()
{
    QString link="https://discord.gg/V6jKftU";
    QDesktopServices::openUrl(QUrl(link));
}
