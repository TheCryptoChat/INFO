#ifndef RESOURCES_H
#define RESOURCES_H

#include "clientmodel.h"
#include "main.h"
#include <QDialog>

namespace Ui {
class Resources;
}
class ClientModel;

class Resources : public QDialog
{
    Q_OBJECT

public:
    explicit Resources(QWidget *parent = 0);
    ~Resources();

    void setModel(ClientModel *model);
    
public slots:
// Empty

private slots:

    void on_pushButton_bitcointalk_clicked();
    void on_pushButton_infocoinfrm_clicked();
    void on_pushButton_garden_clicked();
    void on_pushButton_discord_clicked();

private:
    Ui::Resources *ui;
    ClientModel *model;
    
};

#endif // RESOURCES_H
