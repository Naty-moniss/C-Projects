#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Chanson {
char titre[100];
char artiste[100];
struct Chanson* suivant; // Next
struct Chanson* precedent; // Prev
} Chanson;


// Funções principais:
Chanson* criar_musica(const char* titre, const char* artiste);
void adicionar_musica(Chanson** teto, const char* titre, const char* artiste);
void deletar_musica(Chanson** teto, const char* titre);
void limpar_playlist(Chanson** teto); 
void exibir_playlist(Chanson* teto);

// 1. Criar uma nova música (Alocação Dinâmica)
Chanson* criar_musica(const char* titre, const char* artiste) {
    Chanson* nouvelle = (Chanson*)malloc(sizeof(Chanson));
if (nouvelle == NULL) {
fprintf(stderr, "Erreur d'allocation mémoire.\n");
exit(1);
    }
    
strncpy(nouvelle->titre, titre, 99);
nouvelle->titre[99] = '\0';
strncpy(nouvelle->artiste, artiste, 99);
nouvelle->artiste[99] = '\0';
nouvelle->suivant = NULL;
nouvelle->precedent = NULL;
    return nouvelle;
}


void adicionar_musica(Chanson** teto, const char* titre, const char* artiste) {
    Chanson* nouvelle = criar_musica(titre, artiste);
    if (*teto == NULL) {
        *teto = nouvelle;
        return;
    }
    Chanson* temp = *teto;
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }
    temp->suivant = nouvelle;
    nouvelle->precedent = temp;
}

// 2. Exibir a playlist (Para frente e para trás para testar os ponteiros)
void exibir_playlist(Chanson* teto) {
    if (teto == NULL) {
    printf("La playlist est vide.\n");
        return;
    }
    Chanson* temp = teto;
    printf("\n--- PLAYLIST (Avance) ---\n");
    while (temp != NULL) {
    printf("[%s - %s]\n", temp->titre, temp->artiste);
        if (temp->suivant == NULL) break; // Guarda o último para voltar
        temp = temp->suivant;
    }
}

// 3. Deletar uma música específica (Cuidado com os ponteiros!)
void deletar_musica(Chanson** teto, const char* titre) {
    if (*teto == NULL) return;

    Chanson* temp = *teto;
    while (temp != NULL && strcmp(temp->titre, titre) != 0) {
        temp = temp->suivant;
    }

    if (temp == NULL) return; // Não encontrou

    if (temp == *teto) { // Se for o primeiro nó
        *teto = temp->suivant;
    }
    if (temp->suivant != NULL) {
        temp->suivant->precedent = temp->precedent;
    }
    if (temp->precedent != NULL) {
        temp->precedent->suivant = temp->suivant;
    }

    free(temp); // Libera a memória do nó deletado
}

// 4. Limpar a playlist toda (O herói do Valgrind!)
void limpar_playlist(Chanson** teto) {
    Chanson* actuel = *teto;
    Chanson* suivant = NULL;
    while (actuel != NULL) {
        suivant = actuel->suivant;
        free(actuel);
        actuel = suivant;
    }
    *teto = NULL;
}

// Função Main
int main() {
Chanson* ma_playlist = NULL;

    // Adicionando músicas para testar
    adicionar_musica(&ma_playlist, "Welcome to the Black Parade", "My Chemical Romance");
    adicionar_musica(&ma_playlist, "Sugar, We're Goin Down", "Fall Out Boy");
    adicionar_musica(&ma_playlist, "Cruel Summer", "Taylor Swift");
      adicionar_musica(&ma_playlist, "Llegaste Tu", "Luis Fonsi");

    exibir_playlist(ma_playlist);

    // Testando a remoção
    printf("\n--- Suppression de 'Sugar, We're Goin Down' ---\n");
    deletar_musica(&ma_playlist, "Sugar, We're Goin Down");
    
    exibir_playlist(ma_playlist);

    // Limpeza total antes de fechar (Obrigatório para não dar leak)
    limpar_playlist(&ma_playlist);
    
    return 0;
}