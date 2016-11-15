/*
 * Esse arquivo é responsável por implementar
 * a lógica e os algoritmos (i.e. o código) da
 * classe definida no arquivo gerenciador_janelas.h.
 *
 */

// Inclui a definição da classe
#include "gerenciador_janelas.h"

// Inclui o arquivo de outras classes pertinentes
#include "janela_principal.h"


// Declara o construtor de GerenciadorWidgets e
// especifica que o construtor da classe-mãe (QMainWindow)
// deve ser chamado (e como deve ser chamado)
GerenciadorWidgets::GerenciadorWidgets(QWidget *parent) :
    QMainWindow(parent){

    // Após chamar o construtor da classe-pai
    // (necessário para o correto funcionamento do Qt)

    // Dinamicamente reserva um espaço e cria uma JanelaPrincipal,
    // associando-a ao ponteiro disponível no objeto
    janelaPrincipal = new Ui::JanelaPrincipal;

    // Faz com que a janelaPrincipal seja a interface
    // da janela atual
    janelaPrincipal->setupUi(this);
}



// Declara o destrutor do GerenciadorWidgets
GerenciadorWidgets::~GerenciadorWidgets(){

    // deleta, explicitamente, o espaço
    // alocado para a janelaPrincipal
    delete janelaPrincipal;
}


// Função para esconder a barra de ferramentas
void GerenciadorWidgets::esconderBarraDeFerramentas(){

    // Chama a função de esconder da própria barra de
    // ferramentas da janela principal
    janelaPrincipal->barraFerramentas->hide();
}
