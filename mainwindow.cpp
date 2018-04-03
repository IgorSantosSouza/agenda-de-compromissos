#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classes.h"

using namespace std;

extern Pilha<Pessoa> pessoas(10);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnEmpilhar_clicked()
{
    if((ui->edtPessoa->text() != "")&&(pessoas.f != pessoas.quant)){
        string s = (ui->edtPessoa->text()).toLocal8Bit().constData();
        pessoas.empilhar(Pessoa(s));
        ui->listWidget->addItem(ui->edtPessoa->text());
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget->takeItem((pessoas.f)-1);
    pessoas.desempilhar();
}

void MainWindow::on_btnAdicionar_clicked()
{
    if(ui->edtTitulo->text() != ""){
        string t = (ui->edtTitulo->text()).toLocal8Bit().constData();
        string l = (ui->edtPessoa->text()).toLocal8Bit().constData();
        Compromisso novo_comp(t,ui->edtDia->value(),ui->edtMes->value(),ui->edtAno->value(),l);
    }
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->compList->clear();
    int index = item->listWidget()->row(item);
    string str;
    QString qstr;
    No<Compromisso> *atual;
    if(pessoas.pilha[index].agenda.quant != 0){
        atual = pessoas.pilha[index].agenda.primeiro;
        while(atual != NULL){
            str = "Compromisso: " + atual->n.getTitulo() + " ";
            str += "Data: " + to_string(atual->n.getDia()) + "/";
            str += to_string(atual->n.getMes()) + "/";
            str += to_string(atual->n.getAno()) + " ";
            str += "Local: " + atual->n.getLocal();
            atual = atual->prox;
            qstr = QString::fromStdString(str);
            ui->compList->addItem(qstr);
        }
    }
}
