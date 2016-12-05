/*
 * As duas linhas a seguir protegem
 * o arquivo contra ser inserido múltiplas vezes
 * acidentalmente (causando erros de duplicidade)
 *
 */

#ifndef DATACLASS
#define DATACLASS

// Inclui classes pertinentes (i.e. que serão usadas ou referenciadas
// no decorrer da classe)
#include <QObject>

#include <QSqlDatabase>
#include <QSqlTableModel>

#include <QDebug>

#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QTableView>
#include <QAbstractItemView>
#include <QStringListModel>


// Define a classe GerenciadorInfomacoes como derivada
// da classe QObject
class GerenciadorInformacoes : public QObject {

    // Para poder ter acesso aos slots e
    // sinais do qt, uma classe deve ser
    // um QObjeto e derivar/herdar (d)ele
    Q_OBJECT

public:

    // Declara os construtores e destrutores
    // dessa classe
    explicit GerenciadorInformacoes(QObject *parent = 0);
    ~GerenciadorInformacoes();


    // Variável que guarda o banco de dados
    QSqlDatabase bancoDeDados;


    // Variável responsável por fornecer uma
    // interface independente do tipo e do banco
    // de dado em questão
    QSqlTableModel *interface_bancoDeDados;


    // String que guarda o local onde o banco de dados ficará
    QString caminhoBancoDeDados;

    // String que guarda o nome da tabela atual (NÃO USADO)
    QString tabelaAtual;

    // Lista de string que guarda as tabelas do banco atual
    QStringList listaDeTabelasAtuais;

    // Lista de string que guarda os drivers disponíveis no sistema
    QStringList listaDeDriversAtuais;

    // Modelos que permitem o uso da lista de tabelas e a lista
    // de drivers em um modelo de Visão/Modelo (View/Model), muito
    // comum no framework Qt (por isso estão aqui para evitar a fadiga
    // da conversão inline entre a visão "clássica" e o paragidma View/Model)
    QStringListModel driversDisponiveis;
    QStringListModel tabelasDisponiveis;


    // Define os slots (i.e.  funções a serem ativadas
    // quando o usuário efetua alguma ação pré-determinada)

public slots:
    
    // Função para abrir o banco de dados (retorna True em sucesso e False
    // caso não consiga abrir o banco de dados)
    bool abrirBancoDeDados(QString driver, QString caminho);

    // Versão mais curta da função de abrir o banco de dados
    bool abrirBancoDeDados(QString driver);

    // Função para abrir uma tabela (versão clássica)
    void abrirTabela(QString nomeDaTabela);

    // Função para abrir uma tabela (quando o usuário interage
    // com algum widget que usa o modelo View/Model)
    void abrirTabela(const QModelIndex &index);

    // Funções para obter a lista de tabelas e a lista de drivers
    QStringList obterTabelas();
    QStringList obterDrivers();

    // Funções para conectar Views aos modelos disponíveis
    void conectarTabelasModel(QAbstractItemView *view);
    void conectarDriversModel(QAbstractItemView *view);

    // Função para conectar uma table View no table Model disponível
    // para visualizar informações da tabela
    void conectarTableViewNaTabela(QTableView *tableView, QString tabela);
    
    // Funções para modificar, indiretamente, a representação
    // interna do caminho do banco de dados
    QString obterCaminhoBancoDeDados();
    void setarCaminhoBancoDeDados(QString novoCaminho);


    // Define sinais (i.e. sinais a serem emitidos
    // para que outras classes saibam que certos eventos ocorreram e
    // tomem as atitudes cabíveis)
signals:

    // Indica que a tabela aberta mudou (atualmente usado para
    // redimensionar os cabeçalhos/colunas de tal forma que acomodem bem
    // a informação disponível)
    void tabelaMudou();

};




// Indica o fim da proteção contra duplicidade
#endif
