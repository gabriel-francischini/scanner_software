/********************************************************************************
** Form generated from reading UI file 'janela_principal.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef JANELA_PRINCIPAL_H
#define JANELA_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JanelaPrincipal
{
public:
    QAction *action_selecionar_banco;
    QAction *action_configurar_tabela;
    QAction *action_abrir_outro_projeto;
    QAction *action_sair;
    QAction *action_apontar_tabela;
    QAction *action_nova_tabela;
    QAction *action_novo_banco;
    QAction *action_remover_tabela;
    QAction *action_imprimir;
    QAction *action_salvar;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QTableView *listaImpressoras;
    QHBoxLayout *horizontalLayout;
    QPushButton *botaoImprimir;
    QPushButton *botaoConfigurar;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *barraMenus;
    QMenu *menuArquivos;
    QMenu *menuBanco_de_Dados;
    QStatusBar *barraStatus;
    QToolBar *barraFerramentas;
    QDockWidget *dockListaDeTabelas;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout_2;
    QListView *listaDeTabelas;

    void setupUi(QMainWindow *JanelaPrincipal)
    {
        if (JanelaPrincipal->objectName().isEmpty())
            JanelaPrincipal->setObjectName(QStringLiteral("JanelaPrincipal"));
        JanelaPrincipal->resize(656, 551);
        JanelaPrincipal->setFocusPolicy(Qt::TabFocus);
        action_selecionar_banco = new QAction(JanelaPrincipal);
        action_selecionar_banco->setObjectName(QStringLiteral("action_selecionar_banco"));
        action_configurar_tabela = new QAction(JanelaPrincipal);
        action_configurar_tabela->setObjectName(QStringLiteral("action_configurar_tabela"));
        action_abrir_outro_projeto = new QAction(JanelaPrincipal);
        action_abrir_outro_projeto->setObjectName(QStringLiteral("action_abrir_outro_projeto"));
        action_sair = new QAction(JanelaPrincipal);
        action_sair->setObjectName(QStringLiteral("action_sair"));
        action_apontar_tabela = new QAction(JanelaPrincipal);
        action_apontar_tabela->setObjectName(QStringLiteral("action_apontar_tabela"));
        action_nova_tabela = new QAction(JanelaPrincipal);
        action_nova_tabela->setObjectName(QStringLiteral("action_nova_tabela"));
        action_novo_banco = new QAction(JanelaPrincipal);
        action_novo_banco->setObjectName(QStringLiteral("action_novo_banco"));
        QIcon icon;
        QString iconThemeName = QStringLiteral("Normal");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("resources/database_blue.png"), QSize(), QIcon::Normal, QIcon::Off);
            icon.addFile(QStringLiteral("../resources/database_blue.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        action_novo_banco->setIcon(icon);
        action_remover_tabela = new QAction(JanelaPrincipal);
        action_remover_tabela->setObjectName(QStringLiteral("action_remover_tabela"));
        action_imprimir = new QAction(JanelaPrincipal);
        action_imprimir->setObjectName(QStringLiteral("action_imprimir"));
        action_salvar = new QAction(JanelaPrincipal);
        action_salvar->setObjectName(QStringLiteral("action_salvar"));
        centralWidget = new QWidget(JanelaPrincipal);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(1, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listaImpressoras = new QTableView(centralWidget);
        listaImpressoras->setObjectName(QStringLiteral("listaImpressoras"));

        verticalLayout->addWidget(listaImpressoras);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        botaoImprimir = new QPushButton(centralWidget);
        botaoImprimir->setObjectName(QStringLiteral("botaoImprimir"));

        horizontalLayout->addWidget(botaoImprimir);

        botaoConfigurar = new QPushButton(centralWidget);
        botaoConfigurar->setObjectName(QStringLiteral("botaoConfigurar"));

        horizontalLayout->addWidget(botaoConfigurar);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(1, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        JanelaPrincipal->setCentralWidget(centralWidget);
        barraMenus = new QMenuBar(JanelaPrincipal);
        barraMenus->setObjectName(QStringLiteral("barraMenus"));
        barraMenus->setGeometry(QRect(0, 0, 656, 21));
        menuArquivos = new QMenu(barraMenus);
        menuArquivos->setObjectName(QStringLiteral("menuArquivos"));
        menuBanco_de_Dados = new QMenu(barraMenus);
        menuBanco_de_Dados->setObjectName(QStringLiteral("menuBanco_de_Dados"));
        JanelaPrincipal->setMenuBar(barraMenus);
        barraStatus = new QStatusBar(JanelaPrincipal);
        barraStatus->setObjectName(QStringLiteral("barraStatus"));
        JanelaPrincipal->setStatusBar(barraStatus);
        barraFerramentas = new QToolBar(JanelaPrincipal);
        barraFerramentas->setObjectName(QStringLiteral("barraFerramentas"));
        barraFerramentas->setEnabled(false);
        barraFerramentas->setMinimumSize(QSize(1, 1));
        barraFerramentas->setAutoFillBackground(false);
        barraFerramentas->setMovable(false);
        barraFerramentas->setFloatable(false);
        JanelaPrincipal->addToolBar(Qt::TopToolBarArea, barraFerramentas);
        dockListaDeTabelas = new QDockWidget(JanelaPrincipal);
        dockListaDeTabelas->setObjectName(QStringLiteral("dockListaDeTabelas"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QStringLiteral("dockWidgetContents_3"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listaDeTabelas = new QListView(dockWidgetContents_3);
        listaDeTabelas->setObjectName(QStringLiteral("listaDeTabelas"));

        verticalLayout_2->addWidget(listaDeTabelas);

        dockListaDeTabelas->setWidget(dockWidgetContents_3);
        JanelaPrincipal->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockListaDeTabelas);

        barraMenus->addAction(menuArquivos->menuAction());
        barraMenus->addAction(menuBanco_de_Dados->menuAction());
        menuArquivos->addAction(action_novo_banco);
        menuArquivos->addAction(action_selecionar_banco);
        menuArquivos->addSeparator();
        menuArquivos->addAction(action_abrir_outro_projeto);
        menuArquivos->addAction(action_salvar);
        menuArquivos->addAction(action_sair);
        menuBanco_de_Dados->addAction(action_apontar_tabela);
        menuBanco_de_Dados->addAction(action_configurar_tabela);
        menuBanco_de_Dados->addSeparator();
        menuBanco_de_Dados->addAction(action_nova_tabela);
        menuBanco_de_Dados->addAction(action_remover_tabela);
        menuBanco_de_Dados->addSeparator();
        menuBanco_de_Dados->addAction(action_imprimir);
        barraFerramentas->addAction(action_novo_banco);

        retranslateUi(JanelaPrincipal);

        QMetaObject::connectSlotsByName(JanelaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *JanelaPrincipal)
    {
        JanelaPrincipal->setWindowTitle(QApplication::translate("JanelaPrincipal", "Gerenciador de Scanners", 0));
        action_selecionar_banco->setText(QApplication::translate("JanelaPrincipal", "Selecion&ar banco", 0));
#ifndef QT_NO_TOOLTIP
        action_selecionar_banco->setToolTip(QApplication::translate("JanelaPrincipal", "Selecione outro banco para usar, substituindo o atual por ele", 0));
#endif // QT_NO_TOOLTIP
        action_selecionar_banco->setShortcut(QApplication::translate("JanelaPrincipal", "Ctrl+B", 0));
        action_configurar_tabela->setText(QApplication::translate("JanelaPrincipal", "&Configurar tabela", 0));
        action_configurar_tabela->setShortcut(QApplication::translate("JanelaPrincipal", "Ctrl+T", 0));
        action_abrir_outro_projeto->setText(QApplication::translate("JanelaPrincipal", "Abrir &outro projeto...", 0));
        action_abrir_outro_projeto->setShortcut(QApplication::translate("JanelaPrincipal", "Ctrl+A", 0));
        action_sair->setText(QApplication::translate("JanelaPrincipal", "Sai&r", 0));
        action_sair->setShortcut(QApplication::translate("JanelaPrincipal", "Ctrl+Q", 0));
        action_apontar_tabela->setText(QApplication::translate("JanelaPrincipal", "&Apontar tabela", 0));
        action_nova_tabela->setText(QApplication::translate("JanelaPrincipal", "&Nova tabela", 0));
        action_novo_banco->setText(QApplication::translate("JanelaPrincipal", "&Novo banco", 0));
        action_remover_tabela->setText(QApplication::translate("JanelaPrincipal", "&Remover tabela", 0));
        action_imprimir->setText(QApplication::translate("JanelaPrincipal", "&Imprimir", 0));
        action_imprimir->setShortcut(QApplication::translate("JanelaPrincipal", "Ctrl+P", 0));
        action_salvar->setText(QApplication::translate("JanelaPrincipal", "&Salvar altera\303\247\303\265es no banco", 0));
        action_salvar->setShortcut(QApplication::translate("JanelaPrincipal", "Ctrl+S", 0));
        botaoImprimir->setText(QApplication::translate("JanelaPrincipal", "Imprimir", 0));
        botaoConfigurar->setText(QApplication::translate("JanelaPrincipal", "Configurar Base de Dados", 0));
        menuArquivos->setTitle(QApplication::translate("JanelaPrincipal", "&Arquivos", 0));
        menuBanco_de_Dados->setTitle(QApplication::translate("JanelaPrincipal", "Banco de &Dados", 0));
        dockListaDeTabelas->setWindowTitle(QApplication::translate("JanelaPrincipal", "Lista de Tabelas", 0));
    } // retranslateUi

};

namespace Ui {
    class JanelaPrincipal: public Ui_JanelaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // JANELA_PRINCIPAL_H
