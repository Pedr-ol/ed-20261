#include <stdio.h>
#include <string.h>
#include "conta.h"

int main(){
    Banco banco = conta_criar();
    //Criação da conta Pedro
    Conta pedro;
    pedro.numero_conta = 128374950;
    strcpy(pedro.nome, "Pedro");
    pedro.saldo = 0.0;
    
    //Adicionando o banco de Pedro
    banco.contas[0] = pedro;
    banco.quantidade = 1;

    //Testes com Pedro
    conta_depositar(&banco, 128374950, 715.0);
    conta_sacar(&banco, 128374950, 120.0);

    double saldo1 = conta_ver_saldo(&banco, 128374950);
    printf("Saldo final de Pedro: %.2lf\n", saldo1);

    conta_destruir(&banco);


    //Criação da conta Alice
    Conta alice;
    alice.numero_conta = 344019273;
    strcpy(alice.nome, "Alice");
    alice.saldo = 110.0;
    
    //Adicionando o banco de Alice
    banco.contas[0] = alice;
    banco.quantidade = 1;

    //Testes com Alice
    conta_sacar(&banco, 344019273, 120.0);
    conta_depositar(&banco, 344019273, 715.0);
    conta_sacar(&banco, 344019273, 120.0);
    
    double saldo2 = conta_ver_saldo(&banco, 344019273);
    printf("Saldo final de Alice: %.2lf\n", saldo2);
    return 0;

}