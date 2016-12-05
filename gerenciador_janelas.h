/*
 * As duas linhas a seguir protegem
 * o arquivo contra ser inserido múltiplas vezes
 * acidentalmente (causando erros de duplicidade)
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlTableModel>

#include <QDebug>

#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>

#include <QTableWidget>

#include <QFileDialog>
#include <QModelIndex>

// O arquivo janela_principal.h é gerado
// automaticamente ao se rodar make all
// no arquivo meu_makefile (ou rodando "uic
// -o janela_principal.h janelaprincipal.ui"
// manualmente). O arquivo janela_principal.h
// contem todo o design da janela principal
#include "janela_principal.h"


// Inclui a classe responsável por implementar
// toda a parte lógica e cuidar do manuseio
// das informações (de forma geral).
// É útil separar a parte gráfica da parte processual.
#include "gerenciador_informacoes.h"




// Os arquivos gerados automaticamente a partir
// de um .ui são declarados dentro do namespace Ui
// Por isso, para acessá-los é necessário usar tal namespace
namespace Ui {

    // Indica previamente que usaremos essa(s) classe(s),
    // que está(ão) em um arquivo .h gerado automaticamente
    // a partir de outro arquivo .ui
    class JanelaPrincipal;
    class layoutApontarBancoDeDados;

}

// Indica que usaremos a classe GerenciadorInformacoes
class GerenciadorInformacoes;


/*
 * Essa é a classe principal desse arquivo, a
 * classe GerenciadorWidgets que deriva/herda
 * da classe QMainWindow.
 *
 */
class GerenciadorWidgets : public QMainWindow
{
    // O comando a seguir é uma macro de Qt
    // necessária para todos os objetos com
    // funções do Qt
    Q_OBJECT

public:

    // Declara os construtores e destrutores
    // dessa classe
    explicit GerenciadorWidgets(QWidget *parent = 0);
    ~GerenciadorWidgets();


    // Declara um objeto responsável por cuidar
    // de toda a parte lógica
    GerenciadorInformacoes *gerenciadorInformacoes;


    // Declara um ponteiro que pode ser usado para a janela
    // principal, quando essa estiver ativa
    Ui::JanelaPrincipal *janelaPrincipal;


    // A janela (QWidget) janelaApontarBancoDeDados é uma janela
    // genérica "em branco" para ser preenchida com a interface/layout/
    // interface de usuário definida pela classe Ui::apontarBancoDeDados
    QWidget *janelaApontarBancoDeDados;


    // Esse ponteiro guarda o objeto que define como a janela
    // de selecionar o banco de dados deve ser e todas as funcionalidades
    // relacionadas
    Ui::layoutApontarBancoDeDados *layoutApontarBancoDeDados;


    // A seguir estão as funções disponíveis dessa classe


    // Função para esconder a barra de ferramentas, que
    // ainda está em desenvolvimento
    void esconderBarraDeFerramentas();


    // Define os slots (i.e.  funções a serem ativadas
    // quando o usuário efetua alguma ação pré-determinada)
    // Essas funções também podem ser chamadas "normalmente"
    // i.e. proceduralmente
public slots:

    // Slot para abrir a janela "Selecionar Banco de Dados"
    void mostrarConfiguracoesBancoDeDados();

    // Slot para selecionar o caminho do arquivo do banco de dados
    void acharCaminhoBancoDeDados();

    // Slot para, de fato, abrir o banco de dados
    void abrirBancoDeDados();

    // Função para acomodar os headers/colunas para melhor visão da tabela
    void recarregarListaImpressoras();

};




// Indica o fim da proteção contra duplicidade
#endif
