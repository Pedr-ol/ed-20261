#ifndef CONTA_H
#define CONTA_H

#define LIMITE 100

typedef struct conta_t
{
    int numero_conta;
    char nome[100];
    double saldo;
} Conta;

typedef struct banco_t
{
    Conta contas[LIMITE];
    int quantidade;
} Banco;

Banco conta_criar();
void conta_depositar(Banco *banco, int numero_conta, double valor);
void conta_sacar(Banco *banco, int numero_conta, double valor);
double conta_ver_saldo(Banco *banco, int numero_conta);
void conta_destruir(Banco *banco);

#endif