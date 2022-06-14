#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ordena(new minhaNamespace::Ordena())
{
    ui->setupUi(this);
    ui->comboBoxPorTipo->setEnabled(false);
    ui->comboBoxPorAlfabeto->setEnabled(false);
}

MainWindow::~MainWindow()
{
    if(ordena) delete ordena;
    delete ui;
}

void MainWindow::on_actionAbrir_triggered()
{
    try {
        std::ifstream arquivo;

        QString nomeDoArquivo = QFileDialog::getOpenFileName(this, "Abrir arquivo",
                                                             QDir::currentPath(), "Arquivos texto (*.csv *.txt)");

        if(nomeDoArquivo.isEmpty()) throw QString("Arquivo não selecionado.");

        arquivo.open(nomeDoArquivo.toStdString().c_str());

        if(!arquivo.is_open()) throw QString("Erro: arquivo não pode ser aberto.");

        std::string linha = "";

        while(!arquivo.eof()) {
            std::getline(arquivo, linha);

            ordena->setLista(ordena->splitPessoa(QString::fromStdString(linha)));
        }

        arquivo.close();

        ui->textEditSaida->setText(ordena->getLista());

        ui->comboBoxPorAlfabeto->setEnabled(true);
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

void MainWindow::on_comboBoxPorAlfabeto_activated(int index)
{
    try {
        ui->textEditSaida->clear();

        if(index == 1) {
            ui->textEditSaida->setText(ordena->getListaDesc());
            return;
        }

        ui->textEditSaida->setText(ordena->getLista());
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

