#include <stdio.h>
#include <string.h>
#include "agenda.h"

int main(){
    Agenda agenda = criar_agenda(10);
    
    Contato contato;
    strcpy(contato.nome, "Caio");
    strcpy(contato.telefone, "1111-1111");

    adicionar_contato(&agenda, contato);

    listar_contato(&agenda);

    Contato outro;
    strcpy(outro.nome, "Mauricio");
    strcpy(outro.telefone, "2222-2222");
    
    adicionar_contato(&agenda, outro);

    listar_contato(&agenda);

    Contato outro2;
    strcpy(outro2.nome, "Rafael");
    strcpy(outro2.telefone, "3333-3333");

    adicionar_contato(&agenda, outro2);

    listar_contato(&agenda);
    return 0;
}