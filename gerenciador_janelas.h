/*
 * As duas linhas a seguir protegem
 * o arquivo contra ser inserido múltiplas vezes
 * acidentalmente (causando erros de duplicidade)
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// O arquivo janela_principal.h é gerado
// automaticamente ao se rodar make all
// no arquivo meu_makefile (ou rodando "uic
// -o janela_principal.h janelaprincipal.ui"
// manualmente). O arquivo janela_principal.h
// contem todo o design da janela principal
#include "janela_principal.h"

// Os arquivos gerados automaticamente a partir
// de um .ui são declarados dentro do namespace Ui
// Por isso, para acessá-los é necessário usar tal namespace
namespace Ui {

    // Indica previamente que usaremos essa(s) classe(s),
    // que está(ão) em um arquivo .h gerado automaticamente
    // a partir de outro arquivo .ui
    class JanelaPrincipal;
}



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


    // Declara um ponteiro que pode ser usada para a janela
    // principal, quando essa estiver ativa
    Ui::JanelaPrincipal *janelaPrincipal;





    // Declara as funções disponíveis dessa classe

    // Função para esconder a barra de ferramentas, que
    // ainda está em desenvolvimento
    void esconderBarraDeFerramentas();
};




// Indica o fim da proteção contra duplicidade
#endif
