/*
 * Esse arquivo cuida do interfaceamento entre a
 * plataforma Qt e o Sistema Operacional (Windows)
 * através da definição de main() e do uso do objeto
 * QApplication.
 *
 */

// Incluimos o gerenciador de janelas, que é responsável
// pela implementação e administração das janelas e dos
// widgets principais do programa
#include "gerenciador_janelas.h"
#include <QApplication>



// Todo código em C/C++ é iniciado pela função main1
int main(int argc, char *argv[])
{

    // Definimos uma QApplication (necessária para
    // iniciar o Qt e suas ferramentas)
    QApplication a(argc, argv);


    // Criamos o nosso gerenciador de janelas
    GerenciadorWidgets gerenciadorWidgets;


    // Deixamos o gerenciador de janelas visível
    gerenciadorWidgets.show();


    // Ocultamos a barra de ferramentas pois ela
    // ainda não está finalizada e funcional
    gerenciadorWidgets.esconderBarraDeFerramentas();

    return a.exec();
}
