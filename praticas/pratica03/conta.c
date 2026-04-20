#include <stdio.h>
#include "conta.h"

Banco conta_criar()
{
    Banco banco;
    banco.quantidade = 0;
    return banco;
}

double conta_ver_saldo(Banco *banco, int numero_conta)
{
    for (int i = 0; i < banco->quantidade; i++)
    {
        if (banco->contas[i].numero_conta == numero_conta)
        {
            return banco->contas[i].saldo;
        }
    }
    printf("Nao foi possível realizar essa operacao!\n");
    return -1;
}

void conta_depositar(Banco *banco, int numero_conta, double valor)
{
    for (int i = 0; i < banco->quantidade; i++)
    {
        if (banco->contas[i].numero_conta == numero_conta)
        {
            banco->contas[i].saldo = banco->contas[i].saldo + valor;
            return;
        }
    }
    printf("Nao foi possível realizar essa operacao!\n");
}

void conta_sacar(Banco *banco, int numero_conta, double valor)
{
    for (int i = 0; i < banco->quantidade; i++)
    {
        if (banco->contas[i].saldo >= valor)
        {
            if (banco->contas[i].numero_conta == numero_conta)
            {
                banco->contas[i].saldo = banco->contas[i].saldo - valor;
            }
            else
            {
                printf("Não foi possivel sacar essa quantidade!\n");
            }
            return;
        }
    }
    printf("Nao foi possível realizar essa operacao!\n");
}

void conta_destruir(Banco *banco)
{
    banco->quantidade = 0;
}