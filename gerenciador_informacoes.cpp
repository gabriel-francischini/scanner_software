/*
 * Esse arquivo é responsável por implementar
 * a lógica e os algoritmos (i.e. o código) da
 * classe definida no arquivo gerenciador_janelas.h.
 *
 */

// Inclui a definição da classe
#include "gerenciador_informacoes.h"

// Declara o construtor de GerenciadorWidgets e
// especifica que o construtor da classe-mãe (QMainWindow)
// deve ser chamado (e como deve ser chamado)
GerenciadorInformacoes::GerenciadorInformacoes(QObject *parent){

    // Após chamar o construtor da classe-pai
    // (necessário para o correto funcionamento do Qt)

    // Define uma ""mensagem""/caminho de banco de dados padrão
    caminhoBancoDeDados = QString("");

    // Define o nome da tabela atual
    tabelaAtual = QString("");

    // Define as tabelas do banco de dados atual
    listaDeTabelasAtuais = (QStringList() << "");



    // Dinamicamente aloca a interface do banco de dados
    interface_bancoDeDados = new QSqlTableModel(this, bancoDeDados);

    // Define que a interface não deve salvar automaticamente as modificações,
    // devendo aguardar um sinal para tal
    interface_bancoDeDados->setEditStrategy(QSqlTableModel::OnManualSubmit);


    // Conecta os sinais (p.e. quando o usuário clica em algo)
    // aos respectivos slots (p.e. abrir a função de apontar
    // um outro banco de dados

    // Essa classe provavelmente não conectará, por si mesma,
    // a algum slot/signal. Ela proverá sinais e slots (funcionalidades)
    // para outras classes
}



// Declara o destrutor do GerenciadorWidgets
GerenciadorInformacoes::~GerenciadorInformacoes(){

    
    // libera os recursos usados pelo banco
    // de dados, evitando arquivos corrompidos
    bancoDeDados.close();



    // Libera recursos dinamicamento alocados
    delete interface_bancoDeDados;


}



// Função que retorna os drivers SQL disponíveis
QStringList GerenciadorInformacoes::obterDrivers(){

    // Obtem os drivers disponíveis no sistema
    listaDeDriversAtuais = QSqlDatabase::drivers();

    // Disponibiliza a lista de drivers para widgets que usem View/Model
    this->driversDisponiveis.setStringList(listaDeDriversAtuais);

    // Mostra no debugger o que foi encontrado
    qDebug() << "Lista de drivers atuais: " << listaDeDriversAtuais;

    // Retorna a lista de drivers para quem pediu
    return listaDeDriversAtuais;
}


// Função responsável por obter (e atualizar) as tabelas disponíveis
QStringList GerenciadorInformacoes::obterTabelas(){

    // Obtem as tabelas do banco de dados
    listaDeTabelasAtuais = bancoDeDados.tables();

    // Disponibiliza a lista para widgets View/Model
    this->tabelasDisponiveis.setStringList(listaDeTabelasAtuais);

    // Mostra no debugger as informações obtidas
    qDebug() << "Lista de tabelas: " << listaDeTabelasAtuais;

    // Retorna a lista para quem pediu
    return listaDeTabelasAtuais;
}

// Função responsável por disponibilizar a função abrirTabela(QString)
// para componentes Model/View. Naturalmente, index deverá conter o nome de
// uma tabela do banco de dados.
void GerenciadorInformacoes::abrirTabela(const QModelIndex &index){

    // Faz a conversão do QModelIndex (e do QVariant que contém o nome da tabela)
    // para uma QString
    QString tabela = tabelasDisponiveis.data(index, Qt::DisplayRole).toString();

    // Mostra no debugger a informação obtida
    qDebug() << "Convertendo QVariant para string: " << tabela;

    // Procede em abrir a tabela como se o pedido viesse de um componente/código normal
    abrirTabela(tabela);
}

// Função responsável por mudar a tabela sendo acessada na TableModel interface_tabela
void GerenciadorInformacoes::abrirTabela(QString nomeDaTabela){

    // Atualiza e obtém dentro da listaDeTabelaAtuas a lista de tabelas disponíveis
    this->obterTabelas();

    // Procura se a tabela existe de fato na lista
    if(listaDeTabelasAtuais.contains(nomeDaTabela)){

        // Mostra no debugger a informação obtida
        qDebug() << "Abrindo tabela " << nomeDaTabela;

        // Define qual tabela está sendo usada no momento
        interface_bancoDeDados->setTable(nomeDaTabela);

        // Faz um "SELECT * FROM (nome da tabela)" para
        // deixar as informações disponíveis
        interface_bancoDeDados->select();

        // Envia, para as funções/objetos/slots interessados,
        // a mensagem que a tabela foi modificada
        emit tabelaMudou();

    }

    // Se a tabela não existir
    else{

        // Indica isso no debug
        qDebug() << "Tabela " << nomeDaTabela << " inexistente";
    }
}

// Função para conectar um widget Model/View à lista de tabelas disponíveis
void GerenciadorInformacoes::conectarTabelasModel(QAbstractItemView *view){

    // Atualiza a lista de tabelas
    this->obterTabelas();

    // E a disponibiliza para o componente que pediu
    view->setModel(&tabelasDisponiveis);
}

// Função para disponibilizar a lista de drivers SQL para um componente 
// que use o paradigma Model/View
void GerenciadorInformacoes::conectarDriversModel(QAbstractItemView *view){

    // Atualiza a lista de drivers
    this->obterDrivers();

    // E a disponibiliza para o componente que pediu
    view->setModel(&driversDisponiveis);
}

// Função para conectar a visão da tabela com uma TableView (grid) da tabela
void GerenciadorInformacoes::conectarTableViewNaTabela(QTableView *tableView, QString tabela){

    // Abre a tabela pedida
    abrirTabela(tabela);

    // E a disponibiliza para o componente que a pediu
    tableView->setModel(interface_bancoDeDados);
}

// Função para obter, indiretamente, o caminho do banco de dados atual
QString GerenciadorInformacoes::obterCaminhoBancoDeDados(){
    return this->caminhoBancoDeDados;
}

// Função para modificar, indiretamente, o atual caminho do banco de dados
void GerenciadorInformacoes::setarCaminhoBancoDeDados(QString novoCaminho){
    caminhoBancoDeDados = novoCaminho;
}

// Função mais curta para abrir o banco de dados (pressupõe que o banco 
// de dados a ser aberto é o que está na variável QString caminhoBancoDeDados desta classe)
bool GerenciadorInformacoes::abrirBancoDeDados(QString driver){
    return abrirBancoDeDados(driver, this->caminhoBancoDeDados);
}


// Função que abre o banco de dados
bool GerenciadorInformacoes::abrirBancoDeDados(QString driver, QString caminho){
    
    // Fecha o banco de dados previamente aberto
    bancoDeDados.close();
    
    // Indica qual driver usaremos no banco de dados que abriremos
    bancoDeDados = QSqlDatabase::addDatabase(driver);

    // As linhas a seguir seriam parametros opcionais ainda não disponíveis
    //bancoDeDados.setHostName("localhost");
    //bancoDeDados.setUserName("admin");

    // Define qual banco de dados abriremos
    bancoDeDados.setDatabaseName(caminho);

    // Tenta abrir o banco de dados
     if(bancoDeDados.open()){
        // Caso consiga abrir...


        // Mostra no debugger que conseguiu
        qDebug() << "Conexão ok";

        // Atualiza a tableModel (visão sobre o banco de dados), pois
        // não é possível mudar qual banco de dados se está usando APÓS
        // criar a tableModel, portante é necessário destruí-la e criar uma
        // nova ao mudar o banco de dados

        // destrói da tableModel
        delete interface_bancoDeDados;

        // Cria uma nova que use o banco de dados atual
        interface_bancoDeDados = new QSqlTableModel(this, bancoDeDados);

        // Impede que a table model faça modificações sem expressa autorização do usuário
        interface_bancoDeDados->setEditStrategy(QSqlTableModel::OnManualSubmit);

        // Atualiza a lista de tabelas para as do novo banco de dados
        obterTabelas();

        // Abre a primeira tabela
        abrirTabela(listaDeTabelasAtuais.value(0));
        
        // Retorna que abriu o banco com sucesso
        return true;
    }

    // Caso não tenha conseguido abrir o banco de dados...
    else
        {   
            // Mostre no debug1
            qDebug() << "Conexão falhou";

            // Indique isso para quem chamou esta função
            return false;
    }
}

