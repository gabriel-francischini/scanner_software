/********************************************************************************
** Form generated from reading UI file 'apontar_banco_de_dados.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APONTAR_BANCO_DE_DADOS_H
#define UI_APONTAR_BANCO_DE_DADOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_layoutApontarBancoDeDados
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *caixaCaminhoBancoDeDados;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *etiquetaCaminhoDB;
    QPushButton *botaoMudarCaminhoDB;
    QGroupBox *caixaTipoDeBancoDeDados;
    QVBoxLayout *verticalLayout_3;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *botaoOk;
    QPushButton *botaoCancelar;

    void setupUi(QWidget *layoutApontarBancoDeDados)
    {
        if (layoutApontarBancoDeDados->objectName().isEmpty())
            layoutApontarBancoDeDados->setObjectName(QStringLiteral("layoutApontarBancoDeDados"));
        layoutApontarBancoDeDados->resize(400, 300);
        layoutApontarBancoDeDados->setFocusPolicy(Qt::NoFocus);
        verticalLayout = new QVBoxLayout(layoutApontarBancoDeDados);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        caixaCaminhoBancoDeDados = new QGroupBox(layoutApontarBancoDeDados);
        caixaCaminhoBancoDeDados->setObjectName(QStringLiteral("caixaCaminhoBancoDeDados"));
        verticalLayout_2 = new QVBoxLayout(caixaCaminhoBancoDeDados);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        etiquetaCaminhoDB = new QLabel(caixaCaminhoBancoDeDados);
        etiquetaCaminhoDB->setObjectName(QStringLiteral("etiquetaCaminhoDB"));
        etiquetaCaminhoDB->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(etiquetaCaminhoDB);

        botaoMudarCaminhoDB = new QPushButton(caixaCaminhoBancoDeDados);
        botaoMudarCaminhoDB->setObjectName(QStringLiteral("botaoMudarCaminhoDB"));

        verticalLayout_4->addWidget(botaoMudarCaminhoDB);


        verticalLayout_2->addLayout(verticalLayout_4);


        verticalLayout->addWidget(caixaCaminhoBancoDeDados);

        caixaTipoDeBancoDeDados = new QGroupBox(layoutApontarBancoDeDados);
        caixaTipoDeBancoDeDados->setObjectName(QStringLiteral("caixaTipoDeBancoDeDados"));
        verticalLayout_3 = new QVBoxLayout(caixaTipoDeBancoDeDados);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        comboBox = new QComboBox(caixaTipoDeBancoDeDados);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_3->addWidget(comboBox);


        verticalLayout->addWidget(caixaTipoDeBancoDeDados);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        botaoOk = new QPushButton(layoutApontarBancoDeDados);
        botaoOk->setObjectName(QStringLiteral("botaoOk"));

        horizontalLayout->addWidget(botaoOk);

        botaoCancelar = new QPushButton(layoutApontarBancoDeDados);
        botaoCancelar->setObjectName(QStringLiteral("botaoCancelar"));

        horizontalLayout->addWidget(botaoCancelar);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(layoutApontarBancoDeDados);

        QMetaObject::connectSlotsByName(layoutApontarBancoDeDados);
    } // setupUi

    void retranslateUi(QWidget *layoutApontarBancoDeDados)
    {
        layoutApontarBancoDeDados->setWindowTitle(QApplication::translate("layoutApontarBancoDeDados", "Selecionar Banco de Dados", 0));
        caixaCaminhoBancoDeDados->setTitle(QApplication::translate("layoutApontarBancoDeDados", "Caminho do Banco de Dados", 0));
        etiquetaCaminhoDB->setText(QApplication::translate("layoutApontarBancoDeDados", "[Selecione um banco de dados primeiro]", 0));
        botaoMudarCaminhoDB->setText(QApplication::translate("layoutApontarBancoDeDados", "Selecionar Banco de Dados", 0));
        caixaTipoDeBancoDeDados->setTitle(QApplication::translate("layoutApontarBancoDeDados", "Tipo do Banco de Dados", 0));
        botaoOk->setText(QApplication::translate("layoutApontarBancoDeDados", "Ok", 0));
        botaoCancelar->setText(QApplication::translate("layoutApontarBancoDeDados", "Cancelar", 0));
    } // retranslateUi

};

namespace Ui {
    class layoutApontarBancoDeDados: public Ui_layoutApontarBancoDeDados {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APONTAR_BANCO_DE_DADOS_H
