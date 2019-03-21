/* fonctions:
                ecran de damarrage
                barre de chargement
*/

#include "header.h"

void display_loading(int lin, int col) // Affiche l'interface de chargement
{
    char *title="P O K E F I G H T";

    display_interface(title);
    textbackground(RED); MYclrwin(34, 6, 46, 6); MYclrwin(32, 7, 48, 8); // Pokeball
    textbackground(BLACK); MYclrwin(32, 9, 48, 9); // Pokeball
    textbackground(DARKGRAY);MYclrwin(39, 9, 41, 9); // Pokeball
    textbackground(LIGHTGRAY); gotoxy(65, 16); printf("Version: %s", VERSION);
    textbackground(WHITE); MYclrwin(32, 10, 48, 11); MYclrwin(34, 12, 46, 12); // Pokeball
    textbackground(WHITE); MYclrwin(4, 2, 15, 2); MYclrwin(3, 3, 18, 4); MYclrwin(5, 5, 14, 5);
    textbackground(WHITE); MYclrwin(65, 4, 77, 4); MYclrwin(62, 5, 78, 6); MYclrwin(66, 7, 76, 7);
    loading_bar(80, 17, 1);
}

void loading_bar(int lnbar, int lin, int col) // Affiche une barre de chargement
{
    /* VARIABLES */
    int i;
    float pourcentage=0.0;

    srand(time(NULL));
    textbackground(DARKGRAY); MYclrwin(col, lin, lnbar, lin); // Bar grise totale
    for(i=0; i<=lnbar-1; i++)
    {
        textbackground(GREEN); MYclrwin(col+i, lin, col+i, lin); // Bar verte progressive
        pourcentage=pourcentage+(100.00/lnbar);
        gotoxy(col+27, lin+4); textattr(WHITE*16+BLACK); printf("Chargement du jeu: %.2f%%", pourcentage);
        Sleep(rand()%(150-10+1)+10);
    }
    gotoxy(col+22, lin+5); printf("appuyez sur <entree> pour continuer"); getch();
    MYclrwin(1, 1, 80, 25);
}

int ennemy_finder(struct pokemon pokemon_list[], int lnbar, int lin, int col) // Affiche la recherche d'un ennemi
{
    /* VARIABLES */
    int i, random_pokemon_id;

    srand(time(NULL));
    textbackground(DARKGRAY); MYclrwin(col, lin, lnbar, lin); // Bar grise totale
    for(i=0; i<=lnbar-1; i++)
    {
        textbackground(GREEN); MYclrwin(col+i, lin, col+i, lin); // Bar verte progressive
        gotoxy(col+27, lin+4); textattr(WHITE*16+BLACK); printf("Recherche d'un adversaire");
        random_pokemon_id=rand()%(NB_POKEMON+1-1)+1;
        Sleep(rand()%(50-10+1)+10);
    }
    random_pokemon_id--;
    MYclrwin(col+27, lin+4, col+60, lin+4);
    gotoxy(col+27, lin+4); textattr(WHITE*16+BLACK); printf("Un %s sauvage est apparu !", pokemon_list[random_pokemon_id].name);

    return(random_pokemon_id);
}

void display_interface(char *title) // Affiche l'interface par défaut
{
    /** VARIABLES **/
    int x, y, colx, coly;

    y=1;
    while(title[y]!='\0')
    {
        y++;
    }
    x=(80-y)/2;

    textbackground(LIGHTGRAY); MYclrwin(1, 1, 80 ,25);
    textbackground(DARKGRAY); MYclrwin(1, 17, 80, 17);
    textbackground(WHITE); MYclrwin(1, 18, 80 ,25);
    colx=39-(y/2); coly=41+(y/2);
    textbackground(WHITE); MYclrwin(colx, 1, coly,1);
    textcolor(BLACK); gotoxy(x+1,1); printf("%s", title);
}

int display_fight_interface(struct pokemon my_pokemon[], int my_id, struct pokemon pokemon_list[], int id, char *title) // Affiche l'interface par défaut
{
    /** VARIABLES **/
    int x, y, colx, coly, menu_choice;
    char car[1];

    y=1;
    while(title[y]!='\0')
    {
        y++;
    }
    x=(80-y)/2;

    textbackground(LIGHTGRAY); MYclrwin(1, 1, 80 ,25);
    textbackground(DARKGRAY); MYclrwin(1, 17, 80, 17);
    textbackground(WHITE); MYclrwin(1, 18, 80 ,25);
    colx=39-(y/2); coly=41+(y/2);
    textbackground(WHITE); MYclrwin(colx, 1, coly,1);
    textcolor(BLACK); gotoxy(x+1,1); printf("%s", title);
    textcolor(BLACK);
    gotoxy(15, 19); printf("1. %s [DEGATS:%d]", my_pokemon[my_id].atk1.name, my_pokemon[my_id].atk1.damage);
    gotoxy(50, 19); printf("2. %s (%d) [DEGATS:%d]", my_pokemon[my_id].atk2.name, my_pokemon[my_id].atk2.use, my_pokemon[id].atk2.damage);
    gotoxy(15, 21); printf("3. %s (%d) [DEGATS:%d]", my_pokemon[my_id].atk3.name, my_pokemon[my_id].atk3.use, my_pokemon[id].atk3.damage);
    gotoxy(50, 21); printf("4. %s (%d) [DEGATS:%d]", my_pokemon[my_id].atk4.name, my_pokemon[my_id].atk4.use, my_pokemon[id].atk4.damage);
    gotoxy(15, 23); printf("5. Inventaire");
    gotoxy(5,4); textbackground(LIGHTGRAY); printf("%s [NIV:%d]", my_pokemon[my_id].name, my_pokemon[my_id].level); health_bar(my_pokemon, my_id, 5, 5, LNBAR);
    gotoxy(40,11); textbackground(LIGHTGRAY); printf("%s [NIV:%d]", pokemon_list[id].name, pokemon_list[id].level); health_bar(pokemon_list, id, 12, 40, LNBAR);
    textbackground(WHITE);
    gotoxy(2, 19); printf("> "); fflush(stdin); car[0] = getch(); menu_choice = atoi(car);

    return(menu_choice);
}

void health_bar(struct pokemon pokemon_list[], int pokemon_id, int lin, int col, int lnbar) // Affiche la vie du pokémon
{
    /* VARIABLES */
    int pv_bar;

    pv_bar=lnbar*pokemon_list[pokemon_id].hp.current_health/pokemon_list[pokemon_id].hp.max_health;
    textbackground(DARKGRAY); MYclrwin(col, lin, col+lnbar, lin);

    if(pokemon_list[pokemon_id].hp.current_health>=(pokemon_list[pokemon_id].hp.max_health/2))
    {
        textbackground(GREEN);
    }
    else if(pokemon_list[pokemon_id].hp.current_health<(pokemon_list[pokemon_id].hp.max_health/2) && pokemon_list[pokemon_id].hp.current_health>=(pokemon_list[pokemon_id].hp.max_health/4))
    {
        textbackground(YELLOW);
    }
    else if(pokemon_list[pokemon_id].hp.current_health<(pokemon_list[pokemon_id].hp.max_health/4) && pokemon_list[pokemon_id].hp.current_health>0)
    {
        textbackground(RED);
    }
    else if(pokemon_list[pokemon_id].hp.current_health<=0)
    {
        textbackground(DARKGRAY);
    }

    MYclrwin(col, lin, col+pv_bar, lin);
    gotoxy(col+lnbar+2, lin); textattr(LIGHTGRAY*16+BLACK); printf("%.0f/%.0f HP", pokemon_list[pokemon_id].hp.current_health, pokemon_list[pokemon_id].hp.max_health);
    textbackground(WHITE);
}

void experience_bar(struct pokemon pokemon_list[], int pokemon_id, int lin, int col, int lnbar) // Affiche l'expérience du pokémon
{
    /* VARIABLES */
    int exp_bar=lnbar*pokemon_list[pokemon_id].exp.current_experience/pokemon_list[pokemon_id].exp.max_experience;

    textbackground(DARKGRAY); MYclrwin(col, lin, col+lnbar, lin);
    if(pokemon_list[pokemon_id].exp.current_experience>0)
    {
        textbackground(LIGHTBLUE);
    }
    else if(pokemon_list[pokemon_id].exp.current_experience<=0)
    {
        textbackground(DARKGRAY);
    }
    MYclrwin(col, lin, col+exp_bar, lin);
    gotoxy(col+lnbar+2, lin); textattr(LIGHTGRAY*16+BLACK); printf("%d/%d EXP", pokemon_list[pokemon_id].exp.current_experience, pokemon_list[pokemon_id].exp.max_experience);
}

void pokemon_stats(struct pokemon pokemon_list[], int pokemon_id, int lin, int col) // Affiche les statistique du pokémon
{
    gotoxy(col,lin); printf("%s [NIV:%d]", pokemon_list[pokemon_id].name, pokemon_list[pokemon_id].level);
    health_bar(pokemon_list, pokemon_id, lin+1, col, LNBAR);
    experience_bar(pokemon_list, pokemon_id, lin+2, col, LNBAR);
    gotoxy(col,lin+4); printf("%s", pokemon_list[pokemon_id].atk1.name);
    gotoxy(col,lin+5); printf("Degats: %d", pokemon_list[pokemon_id].atk1.damage);

    gotoxy(col+19,lin+4); printf("%s (%d)", pokemon_list[pokemon_id].atk2.name, pokemon_list[pokemon_id].atk2.use);
    gotoxy(col+19,lin+5); printf("Degats: %d", pokemon_list[pokemon_id].atk2.damage);

    gotoxy(col,lin+7); printf("%s (%d)", pokemon_list[pokemon_id].atk3.name, pokemon_list[pokemon_id].atk3.use);
    gotoxy(col,lin+8); printf("Degats: %d", pokemon_list[pokemon_id].atk3.damage);

    gotoxy(col+19,lin+7); printf("%s (%d)", pokemon_list[pokemon_id].atk4.name, pokemon_list[pokemon_id].atk4.use);
    gotoxy(col+19,lin+8); printf("Degats: %d", pokemon_list[pokemon_id].atk4.damage);
}

void pokedex(struct pokedex pokedex1[], int lin, int col) // Affiche les statistique du pokémon
{
    /** VARIABLES **/
    int i;

    for(i=0; i<=NB_POKEMON-1; i++)
    {
        if(pokedex1[i].captured==1)
        {
            textbackground(GREEN); MYclrwin(col, lin+i, col+1, lin+i);
        }
        else
        {
            textbackground(DARKGRAY); MYclrwin(col, lin+i, col+1, lin+i);
        }
        gotoxy(col+3,lin+i); textbackground(LIGHTGRAY); printf("%d %s", pokedex1[i].id, pokedex1[i].name);
    }
}

int update_level(int *current_experience, int *max_experience, int *level)
{
    /** VARIABLES **/
    int overflow_experience, isLevelUp;

    isLevelUp=0;
    if(*current_experience>=0 && *max_experience>0 && *level>=0)
    {
        if(*current_experience==*max_experience)
        {
            srand(time(NULL));
            *level=(*level)+1;
            isLevelUp=1;
            *current_experience=0;
            *max_experience=*max_experience+(*level)*(rand()%(15-5+1)+5);
        }
        else if(*current_experience>*max_experience)
        {
            overflow_experience=*current_experience-*max_experience;
            srand(time(NULL));
            *level=(*level)+1;
            isLevelUp=1;
            *current_experience=overflow_experience;
            *max_experience=*max_experience+(*level)*(rand()%(15-5+1)+5);
        }
    }
    else if(*current_experience<0)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Erreur: current_experience<0");
    }
    else if(*max_experience<0)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Erreur: max_experience<1");
    }
    else if(*level<0)
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Erreur: level<0");
    }
    else
    {
        gotoxy(1, 1); textattr(BLACK*16+LIGHTRED); printf("[MYGAMES] Erreur");
    }

    return(isLevelUp);
}
