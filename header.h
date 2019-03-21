#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

/**********************************
*        Denis Christopher        *
*                                 *
*            POKEFIGHT            *
*            2017-2018            *
*                                 *
*           OPEN SOURCE           *
**********************************/

/// Désolé, le code est un peu en bordel. J'ai baclé la fin, pour me concentrer sur la création d'une bibliothèque.
/// Le programme fonctionne, mais n'est pas surement pas optimisé.
/// Vous pouvez reprendre mon code, l'améliorer, ...

/** INCLUDES **/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <conioplus.h>

/** CONSTANTES **/
#define VERSION "2.2.0.1"
#define PLAYER_NAME 11
#define NB_POKEMON 8
#define NB_POKEBALL 1
#define COL 1
#define LIN 1
#define LNBAR 25

/** STRUCTURES **/
struct health
{
    float current_health;
    float max_health;
};

struct experience
{
    int current_experience;
    int max_experience;
};

struct attack
{
    char *name;
    int damage;
    int use;
    float success;
};

struct pokemon
{
    char *name;
    int level;
    struct health hp;
    struct experience exp;
    struct attack atk1;
    struct attack atk2;
    struct attack atk3;
    struct attack atk4;
};

struct pokedex
{
    int id;
    char *name;
    int captured;
};

struct pokeball
{
    int id;
    char *name;
    int quantity;
    float success1;
    float success2;
    float success3;
};

struct player
{
    char pseudo[PLAYER_NAME];
    float money;
    int potion;
};

/** FONCTIONS **/
extern void display_loading(int lin, int col);
extern void loading_bar(int lnbar, int lin, int col);
extern int ennemy_finder(struct pokemon pokemon_list[], int lnbar, int lin, int col);
extern void display_interface(char *title);
extern int display_fight_interface(struct pokemon my_pokemon[], int my_id, struct pokemon pokemon_list[], int id, char *title);
extern void health_bar(struct pokemon pokemon_list[], int pokemon_id, int lin, int col, int lnbar);
extern void experience_bar(struct pokemon pokemon_list[], int pokemon_id, int lin, int col, int lnbar);
extern void pokemon_stats(struct pokemon [], int pokemon_id, int lin, int col);
extern void pokedex(struct pokedex pokedex1[], int lin, int col);
extern int update_level(int *current_experience, int *max_experience, int *level);

#endif // HEADER_H_INCLUDED
