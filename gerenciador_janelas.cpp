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
#include "apontar_banco_de_dados.h"


// Declara o construtor de GerenciadorWidgets e
// especifica que o construtor da classe-mãe (QMainWindow)
// deve ser chamado (e como deve ser chamado)
GerenciadorWidgets::GerenciadorWidgets(QWidget *parent) :
    QMainWindow(parent){

    // Após chamar o construtor da classe-pai
    // (necessário para o correto funcionamento do Qt),
    // o construtor executa o código a seguir

    // Dinamicamente reserva um espaço e cria uma JanelaPrincipal,
    // associando-a ao ponteiro reservado no objeto para isso
    janelaPrincipal = new Ui::JanelaPrincipal;

    // Faz com que a janelaPrincipal seja a interface
    // da janela atual
    janelaPrincipal->setupUi(this);

    // Cria o layout/ui da janela "Selecionar Banco de Dados"
    layoutApontarBancoDeDados = new Ui::layoutApontarBancoDeDados();

    // Define como o layout da janela "Selecionar Banco de Dados"
    // deve ser, incluindo suas funcionalidades
    janelaApontarBancoDeDados = new QWidget;

    // Liga o layout à janela, ainda que a janela não esteja visível
    // (ainda) para o usuário
    layoutApontarBancoDeDados->setupUi(janelaApontarBancoDeDados);

    // Cria, dinamicamente, o gerenciador de informações
    gerenciadorInformacoes = new GerenciadorInformacoes(this);

    // Define que é não é possível mudar o nome das tabelas na lista de tabelas
    janelaPrincipal->listaDeTabelas->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // A linha a seguir deveria fazer com que as colunas sempre ocupassem todo o espaço disponível
    // porém, isso ainda não acontece todas as vezes que se abre uma tabela (bug)
    //janelaPrincipal->listaImpressoras->horizontalHeader()->setStretchLastSection(true);

    // Conecta os sinais (p.e. quando o usuário clica em algo)
    // aos respectivos slots (p.e. abrir a função de apontar
    // um outro banco de dados

    // Conecta o ato de clicar em "Selecionar Banco de Dados" com a janela de configurações
    // do banco de dados
    connect(janelaPrincipal->action_selecionar_banco, SIGNAL(triggered(bool)),
            this, SLOT( mostrarConfiguracoesBancoDeDados() )  );

    // Conecta o botão "Selecionar Banco de Dados" da tela de configuração de banco de dados
    // com uma janela para achar o arquivo no sistema de arquivos
    connect(this->layoutApontarBancoDeDados->botaoMudarCaminhoDB, SIGNAL(clicked(bool)),
            this, SLOT( acharCaminhoBancoDeDados() ) );

    // Conecta os botões cancelar e abrir/ok da janela "Selecionar Banco de Dados" com as respectivas funções
    connect(this->layoutApontarBancoDeDados->botaoCancelar, SIGNAL(clicked(bool)), janelaApontarBancoDeDados, SLOT(hide()) );
    connect(this->layoutApontarBancoDeDados->botaoOk, SIGNAL(clicked(bool)), this, SLOT(abrirBancoDeDados()) );

    // Conecta a lista das tabelas do banco de dados com a visão da tabela em si
    // assim o usuário pode clicar duas vezes no nome da tabela e já abri-la
    connect(this->janelaPrincipal->listaDeTabelas, SIGNAL(activated(QModelIndex)), gerenciadorInformacoes, SLOT(abrirTabela(QModelIndex)));

    // Conecta a mudança da tabela com a função que rearranja a visão da tabela
    // assim cada coluna já vem redimensionada no tamanho certo, sem precisar ficar mostrando elipses (...)
    // quando a informação não cabe em alguma cédula
    connect(gerenciadorInformacoes, SIGNAL(tabelaMudou()), this, SLOT(recarregarListaImpressoras()));
}



// Declara o destrutor do GerenciadorWidgets
GerenciadorWidgets::~GerenciadorWidgets(){

    // deleta, explicitamente, o espaço
    // alocado para a janelaPrincipal
    delete janelaPrincipal;

    // O mesmo acima para as outras janelas
    delete janelaApontarBancoDeDados;
    delete layoutApontarBancoDeDados;

    // Idem para o gerenciador do banco de dados
    delete gerenciadorInformacoes;

}

// Função para mostrar uma janela para selecionar o banco e o tipo de banco de dados
// Essa função é chamada quando o usuário clica em Arquivos->Selecionar Banco de Dados
void GerenciadorWidgets::mostrarConfiguracoesBancoDeDados(){

    // Se já ainda não temos um banco selecionado...
    if(gerenciadorInformacoes->obterCaminhoBancoDeDados().isEmpty())

        // Mostre uma mensagem padrão para selecionar o banco
        layoutApontarBancoDeDados->etiquetaCaminhoDB->setText(QString("(Banco de Dados ainda não selecionado)"));

    // Caso contrário...
    else

        // Mostre o banco de dados atual
        layoutApontarBancoDeDados->etiquetaCaminhoDB->setText(this->gerenciadorInformacoes->obterCaminhoBancoDeDados());

    // Primeiro atualizamos a lista de drivers SQL
    gerenciadorInformacoes->obterDrivers();

    // E então a deixamos disponíveis para o usuário
    layoutApontarBancoDeDados->comboBox->setModel(&gerenciadorInformacoes->driversDisponiveis);

    // Torna a janela visível para o usuário
    janelaApontarBancoDeDados->show();

}

// Função responsável por processar quando o usuário clica
// em Arquivos->Selecionar Banco de Dados->Banco de Dados
void GerenciadorWidgets::acharCaminhoBancoDeDados(){

    // Prepara a caixa de pesquisa de arquivos
    QFileDialog selecionarArquivo(this->janelaApontarBancoDeDados);
    selecionarArquivo.setFileMode(QFileDialog::ExistingFile);
    selecionarArquivo.setNameFilter(tr("Qualquer arquivo (*.*)"));
    selecionarArquivo.setViewMode(QFileDialog::Detail);

    // Abre a caixa de pesquisa de arquivos para o usuário
    if(selecionarArquivo.exec())

        // Obtem o resultado da caixa de arquivos
        gerenciadorInformacoes->setarCaminhoBancoDeDados(selecionarArquivo.selectedFiles().first());

    // Mostra no debug a informação obtida
    qDebug() << QString("\nBanco de dados selecionado:\t") << gerenciadorInformacoes->obterCaminhoBancoDeDados();

    // Define o caminho para o banco de dados como o usuário escolheu
    this->layoutApontarBancoDeDados->etiquetaCaminhoDB->setText(this->gerenciadorInformacoes->obterCaminhoBancoDeDados());

}


// Função para esconder a barra de ferramentas
void GerenciadorWidgets::esconderBarraDeFerramentas(){

    // Chama a função de esconder da própria barra de
    // ferramentas da janela principal
    janelaPrincipal->barraFerramentas->hide();
}


// Função chamada quando o usuário clica em "ok" na janela de "Selecionar Banco de Dados"
void GerenciadorWidgets::abrirBancoDeDados(){

    // Abre o banco de dados usando o driver SQL que o usuário escolheu
    gerenciadorInformacoes->abrirBancoDeDados(layoutApontarBancoDeDados->comboBox->currentText());

    // Acha a primeira tabela disponível no banco de dados
    QString tabelaPadrao = gerenciadorInformacoes->obterTabelas().at(0);

    // Abre, para o usuário, a primeira tabela disponível no banco de dados
    gerenciadorInformacoes->conectarTableViewNaTabela(janelaPrincipal->listaImpressoras, tabelaPadrao);

    // Esconde a janela de seleção do banco de dados
    janelaApontarBancoDeDados->hide();

    // Atualiza a lista de tabelas com as tabelas do banco de dados recém-aberto
    gerenciadorInformacoes->conectarTabelasModel(janelaPrincipal->listaDeTabelas);

    // Reajusta o tamanho das colunas para ser mais confortável ao usuário
    recarregarListaImpressoras();
}

void GerenciadorWidgets::recarregarListaImpressoras(){

    //janelaPrincipal->listaImpressoras->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    janelaPrincipal->listaImpressoras->resizeColumnsToContents();
    janelaPrincipal->listaImpressoras->resizeRowsToContents();

}

