#include "header.h"

/** CONSTANTE S **/
#define CURRENT_HP 100.0
#define MAX_HP 100.0
#define CURRENT_EXP 0
#define MAX_EXP 50
#define LEVEL 1
#define ATK1_DMG 10
    #define ATK1_USE -1
    #define ATK1_SUCCESS 0.90
#define ATK2_DMG 15
    #define ATK2_USE 5
    #define ATK2_SUCCESS 0.75
#define ATK3_DMG 20
    #define ATK3_USE 3
    #define ATK3_SUCCESS 0.50
#define ATK4_DMG 25
    #define ATK4_USE 2
    #define ATK4_SUCCESS 0.25

int main(void)
{
    /** VARIABLES **/
    int col=COL, lin=LIN, i, menu_choice, random;
    int l,c, limit;
    int my_pokemon_id, random_pokemon_id, isAttack, isCaptured;
    float victory=0, defeat=0, ratio=0;
    char *title;
    char surrend='n';
    char car[1];
    struct player player1;
    struct pokeball pokeball[NB_POKEBALL]={
                                                {0, "Pokeball", 0, 0.125, 0.25, 0.50},
                                          };
    struct pokemon pokemon_list[NB_POKEMON]={
                                                {"Pikachu", LEVEL, {CURRENT_HP, MAX_HP}, {CURRENT_EXP, MAX_EXP}, {"Mimi-queue", ATK1_DMG, ATK1_USE, ATK1_SUCCESS}, {"Etincelle", ATK2_DMG, ATK2_USE, ATK2_SUCCESS}, {"Eclair", ATK3_DMG, ATK3_USE, ATK3_SUCCESS}, {"Tonnerre", ATK4_DMG, ATK4_USE, ATK4_SUCCESS}},
                                                {"Salameche", LEVEL, {CURRENT_HP, MAX_HP}, {CURRENT_EXP, MAX_EXP}, {"Griffe", ATK1_DMG, ATK1_USE, ATK1_SUCCESS}, {"Flammeche", ATK2_DMG, ATK2_USE, ATK2_SUCCESS}, {"Crocs feu", ATK3_DMG, ATK3_USE, ATK3_SUCCESS}, {"Feu d'enfer", ATK4_DMG, ATK4_USE, ATK4_SUCCESS}},
                                                {"Carapuce", LEVEL, {CURRENT_HP, MAX_HP}, {CURRENT_EXP, MAX_EXP}, {"Charge", ATK1_DMG, ATK1_USE, ATK1_SUCCESS}, {"Ecume", ATK2_DMG, ATK2_USE, ATK2_SUCCESS}, {"Hydroqueue", ATK3_DMG, ATK3_USE, ATK3_SUCCESS}, {"Hydrocanon", ATK4_DMG, ATK4_USE, ATK4_SUCCESS}},
                                                {"Bulbizarre", LEVEL, {CURRENT_HP, MAX_HP}, {CURRENT_EXP, MAX_EXP}, {"Charge", ATK1_DMG, ATK1_USE, ATK1_SUCCESS}, {"Fouet lianes", ATK2_DMG, ATK2_USE, ATK2_SUCCESS}, {"Canon graine", ATK3_DMG, ATK3_USE, ATK3_SUCCESS}, {"Damocles", ATK4_DMG, ATK4_USE, ATK4_SUCCESS}},
                                                {"Roucool", LEVEL, {CURRENT_HP, MAX_HP}, {CURRENT_EXP, MAX_EXP}, {"Charge", ATK1_DMG, ATK1_USE, ATK1_SUCCESS}, {"Tornade", ATK2_DMG, ATK2_USE, ATK2_SUCCESS}, {"Cyclone", ATK3_DMG, ATK3_USE, ATK3_SUCCESS}, {"Ouragan", ATK4_DMG, ATK4_USE, ATK4_SUCCESS}},
                                                {"Rattata", LEVEL, {CURRENT_HP, MAX_HP}, {CURRENT_EXP, MAX_EXP}, {"Charge", ATK1_DMG, ATK1_USE, ATK1_SUCCESS}, {"Morsure", ATK2_DMG, ATK2_USE, ATK2_SUCCESS}, {"Machouille", ATK3_DMG, ATK3_USE, ATK3_SUCCESS}, {"Damocles", ATK4_DMG, ATK4_USE, ATK4_SUCCESS}},
                                                {"Taupiqueur", LEVEL, {CURRENT_HP, MAX_HP}, {CURRENT_EXP, MAX_EXP}, {"Griffe", ATK1_DMG, ATK1_USE, ATK1_SUCCESS}, {"Boue-bombe", ATK2_DMG, ATK2_USE, ATK2_SUCCESS}, {"Tunnel", ATK3_DMG, ATK3_USE, ATK3_SUCCESS}, {"Seisme", ATK4_DMG, ATK4_USE, ATK4_SUCCESS}},
                                                {"Racaillou", LEVEL, {CURRENT_HP, MAX_HP}, {CURRENT_EXP, MAX_EXP}, {"Charge", ATK1_DMG, ATK1_USE, ATK1_SUCCESS}, {"Roulade", ATK2_DMG, ATK2_USE, ATK2_SUCCESS}, {"Jet-Pierres", ATK3_DMG, ATK3_USE, ATK3_SUCCESS}, {"Seisme", ATK4_DMG, ATK4_USE, ATK4_SUCCESS}},
                                            };

    struct pokemon my_pokemon[0];

    struct pokedex pokedex1[NB_POKEMON]={
                                            {0, pokemon_list[0].name, 0},
                                            {1, pokemon_list[1].name, 0},
                                            {2, pokemon_list[2].name, 0},
                                            {3, pokemon_list[3].name, 0},
                                            {4, pokemon_list[4].name, 0},
                                            {5, pokemon_list[5].name, 0},
                                            {6, pokemon_list[6].name, 0},
                                            {7, pokemon_list[7].name, 0},
                                        };

    display_loading(lin, col);
    title="I N T R O D U C T I O N"; display_interface(title);
    gotoxy(2, 19); printf("Bienvenue.");
    gotoxy(2, 20); printf("Comment t'appelles-tu ? (MAX:11)");
    gotoxy(2, 21); printf("> "); scanf("%11[^\n]s", player1.pseudo);
    display_interface(title);
    gotoxy(2, 19); printf("Bienvenue %s sur PokeFight !", player1.pseudo);
    getch(); display_interface(title);
    textbackground(RED); MYclrwin(14, 6, 26, 6); MYclrwin(12, 7, 28, 8); // Pokeball
    textbackground(BLACK); MYclrwin(12, 9, 28, 9); // Pokeball
    textbackground(DARKGRAY);MYclrwin(19, 9, 21, 9); // Pokeball
    textbackground(WHITE); MYclrwin(12, 10, 28, 11); MYclrwin(14, 12, 26, 12); // Pokeball

    textbackground(RED); MYclrwin(34, 6, 46, 6); MYclrwin(32, 7, 48, 8); // Pokeball
    textbackground(BLACK); MYclrwin(32, 9, 48, 9); // Pokeball
    textbackground(DARKGRAY);MYclrwin(39, 9, 41, 9); // Pokeball
    textbackground(WHITE); MYclrwin(32, 10, 48, 11); MYclrwin(34, 12, 46, 12); // Pokeball

    textbackground(RED); MYclrwin(54, 6, 66, 6); MYclrwin(52, 7, 68, 8); // Pokeball
    textbackground(BLACK); MYclrwin(52, 9, 68, 9); // Pokeball
    textbackground(DARKGRAY);MYclrwin(59, 9, 61, 9); // Pokeball
    textbackground(WHITE); MYclrwin(52, 10, 68, 11); MYclrwin(54, 12, 66, 12); // Pokeball
    gotoxy(2, 19); printf("Bien, maintenant il est l'heure de choisir ton compagnon.");
    gotoxy(2, 20); printf("1. Salameche");
    gotoxy(2, 21); printf("2. Carapuce");
    gotoxy(2, 22); printf("3. Bulbizarre");
    gotoxy(2, 23); printf(">");
    do
    {
        MYclrwin(4, 23, 80, 23);
        gotoxy(4, 23); fflush(stdin); car[0] = getch(); my_pokemon_id = atoi(car);
    }while(my_pokemon_id<1 || my_pokemon_id>3);
    display_interface(title);
    pokedex1[my_pokemon_id].captured=1; // Le pokémon a été découvert dans le pokedex
    my_pokemon[0]=pokemon_list[my_pokemon_id]; // Le pokémon est ajouté comme pokémon principal
    gotoxy(2, 19); printf("Tu as choisi %s comme compagnon !", my_pokemon[0].name);
    getch(); display_interface(title);
    gotoxy(2, 19);printf("Voici la liste de ses attaques:");
    gotoxy(3, 20); printf("- %s [DEGATS:%d]", my_pokemon[0].atk1.name, my_pokemon[0].atk1.damage);
    gotoxy(3, 21); printf("- %s [DEGATS:%d]", my_pokemon[0].atk2.name, my_pokemon[0].atk2.damage);
    gotoxy(3, 22); printf("- %s [DEGATS:%d]", my_pokemon[0].atk3.name, my_pokemon[0].atk3.damage);
    gotoxy(3, 23); printf("- %s [DEGATS:%d]", my_pokemon[0].atk4.name, my_pokemon[0].atk4.damage);
    getch(); display_interface(title);
    gotoxy(2, 19); printf("L'aventure peut commencer.");
    gotoxy(2, 20); printf("Mais avant de partir, accepte ces cadeaux.");
    gotoxy(2, 21); printf("Ce n'est pas grand chose, mais cela te sera utile !");
    getch();
    gotoxy(2, 22); textcolor(GREEN); player1.potion=2; printf("+%d potions", player1.potion);
    gotoxy(2, 23); textcolor(GREEN); player1.money=100.00; printf("+%.2f$", player1.money);
    gotoxy(2, 24); textcolor(GREEN); pokeball[0].quantity+=3; printf("+%d pokeball", pokeball[0].quantity);
    getch();

    do
    {
        srand(time(NULL));
        title="A C C U E I L"; display_interface(title);
        textbackground(LIGHTGRAY); textcolor(BLACK);
        gotoxy(2, 3); printf("%s [NIV:%d]", my_pokemon[0].name, my_pokemon[0].level);
        textbackground(RED); MYclrwin(9, 5, 21, 5); MYclrwin(7, 6, 23, 7); // Pokeball
        textbackground(BLACK); MYclrwin(7, 8, 23, 8); // Pokeball
        textbackground(DARKGRAY);MYclrwin(14, 8, 16, 8); // Pokeball
        textbackground(WHITE); MYclrwin(7, 9, 23, 10); MYclrwin(9, 11, 21, 11); // Pokeball
        health_bar(my_pokemon, 0, 13, 2, LNBAR);
        experience_bar(my_pokemon, 0, 14, 2, LNBAR);
        gotoxy(50, 3); printf("%s", player1.pseudo);
        gotoxy(50, 4); printf("Argent: %.2f$", player1.money);
        gotoxy(50, 5); printf("Victoires: %.0f", victory);
        gotoxy(50, 6); printf("Defaites: %.0f", defeat);
        if(defeat==0)
        {
            ratio=victory;
        }
        else
        {
            ratio=victory/defeat;
        }
        gotoxy(50, 7); printf("Ratio: %.2f", ratio);
        textbackground(WHITE);
        gotoxy(2, 19); printf("1. Combattre");
        gotoxy(2, 20); printf("2. Inventaire");
        gotoxy(2, 21); printf("3. Pokedex");
        gotoxy(2, 22); printf("4. PokeCenter");
        gotoxy(2, 23); printf("5. Boutique");
        gotoxy(20, 23); printf("9. Abandonner");
        gotoxy(2, 24); printf(">");
        gotoxy(4, 24); fflush(stdin); car[0] = getch(); menu_choice = atoi(car);
        switch(menu_choice)
        {
            case 1: // C O M B A T
                {
                    if(my_pokemon[0].hp.current_health>0)
                    {
                        my_pokemon[0].atk2.use=5;
                        my_pokemon[0].atk3.use=3;
                        my_pokemon[0].atk4.use=2;
                        title="C O M B A T";
                        display_interface(title);
                        Sleep(500);
                        random_pokemon_id=ennemy_finder(pokemon_list, 80, 17, 1);
                        getch();
                        my_pokemon[0].atk2.use=ATK2_USE;
                        my_pokemon[0].atk3.use=ATK3_USE;
                        my_pokemon[0].atk4.use=ATK4_USE;
                        pokemon_list[random_pokemon_id].hp.current_health=pokemon_list[random_pokemon_id].hp.max_health;
                        pokemon_list[random_pokemon_id].atk2.use=ATK2_USE;
                        pokemon_list[random_pokemon_id].atk3.use=ATK3_USE;
                        pokemon_list[random_pokemon_id].atk4.use=ATK4_USE;
                        isCaptured=0;

                        l = 0;
                        limit = 79;
                        while(l<=12)
                        {
                            c = 0;
                            if(l == 12) limit = 40;
                            while(c<=limit)
                            {
                                if(c%5 == 0) Sleep(1);
                                textbackground(BLACK); MYclrwin(1+c,1+l,1+c,1+l); MYclrwin(80-c,25-l,80-c,25-l);
                                c++;
                            }
                            l++;
                        }
                        Sleep(1000);
                        do
                        {
                            isAttack=0;
                            do
                            {
                                title=my_pokemon[0].name; menu_choice=display_fight_interface(my_pokemon, 0, pokemon_list, random_pokemon_id, title); // Mon tour
                                switch(menu_choice)
                                {
                                    case 1:
                                        {
                                            isAttack=1;
                                            gotoxy(5,14); textbackground(LIGHTGRAY); printf("%s attaque %s.", my_pokemon[0].name, pokemon_list[random_pokemon_id].name);
                                            Sleep(300);
                                            random=rand()%(100-1+1)+1;
                                            if(random>=1 && random<=(my_pokemon[0].atk1.success*100))
                                            {
                                                pokemon_list[random_pokemon_id].hp.current_health-=my_pokemon[0].atk1.damage;
                                                gotoxy(5,15); textbackground(LIGHTGRAY); printf("C'est une reussite ! -%dHP.", my_pokemon[0].atk1.damage);
                                            }
                                            else
                                            {
                                                gotoxy(5,15); textbackground(LIGHTGRAY); printf("C'est un echec ! %s a esquive l'attaque.", pokemon_list[random_pokemon_id].name);
                                            }
                                            getch();
                                            break;
                                        }
                                    case 2:
                                        {
                                            if(my_pokemon[0].atk2.use>0)
                                            {
                                                isAttack=1;
                                                gotoxy(5,14); textbackground(LIGHTGRAY); printf("%s attaque %s.", my_pokemon[0].name, pokemon_list[random_pokemon_id].name);
                                                Sleep(300);
                                                random=rand()%(100-1+1)+1;
                                                if(random>=1 && random<=my_pokemon[0].atk2.success*100)
                                                {
                                                    pokemon_list[random_pokemon_id].hp.current_health-=my_pokemon[0].atk2.damage;
                                                    gotoxy(5,15); textbackground(LIGHTGRAY); printf("C'est une reussite ! -%dHP.", my_pokemon[0].atk2.damage);
                                                }
                                                else
                                                {
                                                    gotoxy(5,15); textbackground(LIGHTGRAY); printf("C'est un echec ! %s a esquive l'attaque.", pokemon_list[random_pokemon_id].name);
                                                }
                                                my_pokemon[0].atk2.use--;
                                                getch();
                                            }
                                            break;
                                        }
                                    case 3:
                                        {
                                            if(my_pokemon[0].atk3.use>0)
                                            {
                                                isAttack=1;
                                                gotoxy(5,14); textbackground(LIGHTGRAY); printf("%s attaque %s.", my_pokemon[0].name, pokemon_list[random_pokemon_id].name);
                                                Sleep(300);
                                                random=rand()%(100-1+1)+1;
                                                if(random>=1 && random<=my_pokemon[0].atk3.success*100)
                                                {
                                                    pokemon_list[random_pokemon_id].hp.current_health-=my_pokemon[0].atk3.damage;
                                                    gotoxy(5,15); textbackground(LIGHTGRAY); printf("C'est une reussite ! -%dHP.", my_pokemon[0].atk3.damage);
                                                }
                                                else
                                                {
                                                    gotoxy(5,15); textbackground(LIGHTGRAY); printf("C'est un echec ! %s a esquive l'attaque.", pokemon_list[random_pokemon_id].name);
                                                }
                                                my_pokemon[0].atk3.use--;
                                                getch();
                                            }
                                            break;
                                        }
                                    case 4:
                                        {
                                            if(my_pokemon[0].atk4.use>0)
                                            {
                                                isAttack=1;
                                                gotoxy(5,14); textbackground(LIGHTGRAY); printf("%s attaque %s.", my_pokemon[0].name, pokemon_list[random_pokemon_id].name);
                                                Sleep(300);
                                                random=rand()%(100-1+1)+1;
                                                if(random>=1 && random<=my_pokemon[0].atk4.success*100)
                                                {
                                                    pokemon_list[random_pokemon_id].hp.current_health-=my_pokemon[0].atk4.damage;
                                                    gotoxy(5,15); textbackground(LIGHTGRAY); printf("C'est une reussite ! -%dHP.", my_pokemon[0].atk4.damage);
                                                }
                                                else
                                                {
                                                    gotoxy(5,15); textbackground(LIGHTGRAY); printf("C'est un echec ! %s a esquive l'attaque.", pokemon_list[random_pokemon_id].name);
                                                }
                                                my_pokemon[0].atk4.use--;
                                                getch();
                                            }
                                            break;
                                        }
                                    case 5:
                                        {
                                            do
                                            {
                                                menu_choice=0;
                                                title="I N V E N T A I R E";
                                                display_interface(title);
                                                textbackground(LIGHTRED); gotoxy(2, 3); printf("VOS OBJETS");
                                                textbackground(LIGHTGRAY);
                                                gotoxy(2, 4); printf("Potions: %d", player1.potion);
                                                gotoxy(2, 5); printf("Pokeball: %d", pokeball[0].quantity);
                                                textbackground(WHITE);
                                                gotoxy(2, 19); printf("1. Potion");
                                                gotoxy(2, 20); printf("2. Pokeball");
                                                gotoxy(2, 21); textcolor(BLACK); printf("9. Retour");
                                                gotoxy(2, 22); printf(">");
                                                gotoxy(4, 22); fflush(stdin); car[0] = getch(); menu_choice = atoi(car);
                                                switch(menu_choice)
                                                {
                                                    case 1: // utiliser une potion
                                                    {
                                                        if(player1.potion>0 && my_pokemon[0].hp.current_health<my_pokemon[0].hp.max_health)
                                                        {
                                                            player1.potion=player1.potion-1;
                                                            my_pokemon[0].hp.current_health=my_pokemon[0].hp.max_health;
                                                            display_interface(title);
                                                            gotoxy(2, 19); printf("Les PV de %s ont %ct%c restaur%cs.", my_pokemon[0].name, 130, 130, 130);
                                                        }
                                                        else if(player1.potion>0 && my_pokemon[0].hp.current_health==my_pokemon[0].hp.max_health)
                                                        {
                                                            display_interface(title);
                                                            gotoxy(2, 19); printf("Les PV de %s sont d%cja au maximum.", my_pokemon[0].name, 130);
                                                        }
                                                        else
                                                        {
                                                            display_interface(title);
                                                            gotoxy(2, 19); printf("Vous n'avez pas de potion.");
                                                        }
                                                        getch();
                                                        break;
                                                    }
                                                    case 2:
                                                        {
                                                            if(pokeball[0].quantity>=1)
                                                            {
                                                                textbackground(LIGHTGRAY);
                                                                if(pokedex1[random_pokemon_id].captured==0)
                                                                {
                                                                    isAttack=1;
                                                                    pokeball[0].quantity--;
                                                                    gotoxy(5,14); printf("Tentative de capture...");
                                                                    Sleep(1000);

                                                                    if(pokemon_list[random_pokemon_id].hp.current_health==pokemon_list[random_pokemon_id].hp.max_health)
                                                                    {
                                                                        random=rand()%(100+1-1)+1;
                                                                        if(random<=(100*pokeball[0].success1))
                                                                        {
                                                                            isCaptured=1;
                                                                        }
                                                                    }
                                                                    else if(pokemon_list[random_pokemon_id].hp.current_health>=pokemon_list[random_pokemon_id].hp.max_health/2)
                                                                    {
                                                                        random=rand()%(100+1-1)+1;
                                                                        if(random<=(100*pokeball[0].success2))
                                                                        {
                                                                            isCaptured=1;
                                                                        }
                                                                    }
                                                                    else if(pokemon_list[random_pokemon_id].hp.current_health<pokemon_list[random_pokemon_id].hp.max_health/2)
                                                                    {
                                                                        random=rand()%(100+1-1)+1;
                                                                        if(random<=(100*pokeball[0].success3))
                                                                        {
                                                                            isCaptured=1;
                                                                        }
                                                                    }

                                                                    if(isCaptured==1)
                                                                    {
                                                                        pokedex1[random_pokemon_id].captured=1;
                                                                        gotoxy(5,15); printf("Bravo ! %s a ete ajoute a votre pokedex.", pokedex1[random_pokemon_id].name);
                                                                    }
                                                                    else
                                                                    {
                                                                        gotoxy(5,15); printf("Dommage ! %s s'est libere.", pokedex1[random_pokemon_id].name);
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    gotoxy(5,15); printf("%s est deja dans votre pokedex.", pokedex1[random_pokemon_id].name);
                                                                }
                                                            }
                                                            else
                                                            {
                                                                display_interface(title);
                                                                gotoxy(2, 19); printf("Vous n'avez pas de pokeball.");
                                                            }
                                                            getch();
                                                            break;
                                                        }
                                                    default:
                                                    {
                                                        break;
                                                    }
                                                }
                                            }while(menu_choice!=10 && menu_choice!=2);
                                        }
                                }
                                if(pokemon_list[random_pokemon_id].hp.current_health<0)
                                {
                                    pokemon_list[random_pokemon_id].hp.current_health=0;
                                }
                            }while(isAttack==0);
                            isAttack=0;
                            if(isCaptured==0 && pokemon_list[random_pokemon_id].hp.current_health>0)
                            {
                                do
                                {
                                    title=pokemon_list[random_pokemon_id].name; display_interface(title); // Tour ennemi
                                    gotoxy(5,4); textbackground(LIGHTGRAY); printf("%s [NIV:%d]", my_pokemon[0].name, my_pokemon[0].level); health_bar(my_pokemon, 0, 5, 5, LNBAR);
                                    gotoxy(40,11); textbackground(LIGHTGRAY); printf("%s [NIV:%d]", pokemon_list[random_pokemon_id].name, pokemon_list[random_pokemon_id].level); health_bar(pokemon_list, random_pokemon_id, 12, 40, LNBAR);
                                    Sleep(1000);
                                    random=rand()%(4-1+1)+1;
                                    switch(random)
                                    {
                                        case 1:
                                            {
                                                isAttack=1;
                                                gotoxy(5,14); textbackground(LIGHTGRAY); printf("%s attaque %s.", pokemon_list[random_pokemon_id].name, my_pokemon[0].name);
                                                Sleep(300);
                                                random=rand()%(100-1+1)+1;
                                                if(random>=1 && random<=(pokemon_list[random_pokemon_id].atk1.success*100))
                                                {
                                                    my_pokemon[0].hp.current_health-=pokemon_list[random_pokemon_id].atk1.damage;
                                                    gotoxy(5,15);  textbackground(LIGHTGRAY); printf("C'est une reussite ! -%dHP.", pokemon_list[random_pokemon_id].atk1.damage);
                                                }
                                                else
                                                {
                                                    gotoxy(5,15); textbackground(LIGHTGRAY); printf("C'est un echec ! %s a esquive l'attaque.", my_pokemon[0].name);
                                                }
                                                getch();
                                                break;
                                            }
                                        case 2:
                                            {
                                                if(pokemon_list[random_pokemon_id].atk2.use>0)
                                                {
                                                    isAttack=1;
                                                    gotoxy(5,14); textbackground(LIGHTGRAY); printf("%s attaque %s.", pokemon_list[random_pokemon_id].name, my_pokemon[0].name);
                                                    Sleep(300);
                                                    random=rand()%(100-1+1)+1;
                                                    if(random>=1 && random<=pokemon_list[random_pokemon_id].atk2.success*100)
                                                    {
                                                        my_pokemon[0].hp.current_health-=pokemon_list[random_pokemon_id].atk2.damage;
                                                        gotoxy(5,15); textbackground(LIGHTGRAY); printf("C'est une reussite ! -%dHP.", pokemon_list[random_pokemon_id].atk2.damage);
                                                    }
                                                    else
                                                    {
                                                        gotoxy(5,15); textbackground(LIGHTGRAY); printf("C'est un echec ! %s a esquive l'attaque.", my_pokemon[0].name);
                                                    }
                                                    pokemon_list[random_pokemon_id].atk2.use--;
                                                    getch();
                                                }
                                                break;
                                            }
                                        case 3:
                                            {
                                                if(my_pokemon[0].atk3.use>0)
                                                {
                                                    isAttack=1;
                                                    gotoxy(5,14); textbackground(LIGHTGRAY); printf("%s attaque %s.", pokemon_list[random_pokemon_id].name, my_pokemon[0].name);
                                                    Sleep(300);
                                                    random=rand()%(100-1+1)+1;
                                                    if(random>=1 && random<=pokemon_list[random_pokemon_id].atk3.success*100)
                                                    {
                                                        my_pokemon[0].hp.current_health-=pokemon_list[random_pokemon_id].atk3.damage;
                                                        gotoxy(5,15); textbackground(LIGHTGRAY); printf("C'est une reussite ! -%dHP.", pokemon_list[random_pokemon_id].atk3.damage);
                                                    }
                                                    else
                                                    {
                                                        gotoxy(5,15); textbackground(LIGHTGRAY); printf("C'est un echec ! %s a esquive l'attaque.", my_pokemon[0].name);
                                                    }
                                                    pokemon_list[random_pokemon_id].atk3.use--;
                                                    getch();
                                                }
                                                break;
                                            }
                                        case 4:
                                            {
                                                if(my_pokemon[0].atk4.use>0)
                                                {
                                                    isAttack=1;
                                                    gotoxy(5,14); textbackground(LIGHTGRAY); printf("%s attaque %s.", pokemon_list[random_pokemon_id].name, my_pokemon[0].name);
                                                    Sleep(300);
                                                    random=rand()%(100-1+1)+1;
                                                    if(random>=1 && random<=pokemon_list[random_pokemon_id].atk4.success*100)
                                                    {
                                                        my_pokemon[0].hp.current_health-=pokemon_list[random_pokemon_id].atk4.damage;
                                                        gotoxy(5,15); textbackground(LIGHTGRAY); printf("C'est une reussite ! -%dHP.", pokemon_list[random_pokemon_id].atk4.damage);
                                                    }
                                                    else
                                                    {
                                                        gotoxy(5,15); textbackground(LIGHTGRAY); printf("C'est un echec ! %s a esquive l'attaque.", my_pokemon[0].name);
                                                    }
                                                    pokemon_list[random_pokemon_id].atk4.use--;
                                                    getch();
                                                }
                                                break;
                                            }
                                    }
                                    if(my_pokemon[0].hp.current_health<0)
                                    {
                                        my_pokemon[0].hp.current_health=0;
                                    }
                                }while(isAttack==0);
                            }
                        }while(my_pokemon[0].hp.current_health>0 && pokemon_list[random_pokemon_id].hp.current_health>0 && isCaptured==0);
                        title="C O M B A T";
                        display_interface(title);
                        textbackground(LIGHTGRAY);
                        if(isCaptured==1)
                        {
                            gotoxy(5,4); printf("Bravo ! Vous avez capture %s.", pokemon_list[random_pokemon_id].name);
                            random=rand()%(25+1-15)+15;
                            player1.money+=random;
                            gotoxy(5,5); printf("+%.2f$", (float)random);
                        }
                        else if(my_pokemon[0].hp.current_health>0)
                        {
                            victory++;
                            gotoxy(5,3); printf("%s est le vainqueur.", my_pokemon[0].name);
                            random=rand()%(35+1-15)+15;
                            player1.money+=random;
                            gotoxy(5,4); printf("+%.2f$", (float)random);
                            random=rand()%(25+1-15)+15;
                            my_pokemon[0].exp.current_experience+=random;
                            gotoxy(5,5); printf("+%d point d'experience", random);
                            if(update_level(&my_pokemon[0].exp.current_experience, &my_pokemon[0].exp.max_experience, &my_pokemon[0].level)==1)
                            {
                                gotoxy(5,6); textbackground(LIGHTGRAY); printf("%s est desormais au niveau %d", my_pokemon[0].name, my_pokemon[0].level);
                            }
                        }
                        else
                        {
                            defeat++;
                            update_level(&my_pokemon[0].exp.current_experience, &my_pokemon[0].exp.max_experience, &my_pokemon[0].level);
                            gotoxy(5,14); printf("%s est le vainqueur.", pokemon_list[random_pokemon_id].name);
                        }
                        getch();
                    }
                    break;
                }
            case 2: // I N V E N T A I R E
                {
                    do
                    {
                        menu_choice=0;
                        title="I N V E N T A I R E";
                        display_interface(title);
                        textbackground(LIGHTRED); gotoxy(2, 3); printf("VOS OBJETS");
                        textbackground(LIGHTGRAY);
                        gotoxy(2, 4); printf("Potions: %d", player1.potion);
                        gotoxy(2, 5); printf("Pokeball: %d", pokeball[0].quantity);
                        textbackground(WHITE);
                        gotoxy(2, 19); printf("1. Potion");
                        gotoxy(2, 20); printf("2. Pokeball");
                        gotoxy(2, 21); textcolor(BLACK); printf("9. Retour");
                        gotoxy(2, 22); printf(">");
                        gotoxy(4, 22); fflush(stdin); car[0] = getch(); menu_choice = atoi(car);
                        switch(menu_choice)
                        {
                            case 1: // utiliser une potion
                            {
                                if(player1.potion>0 && my_pokemon[0].hp.current_health<my_pokemon[0].hp.max_health)
                                {
                                    player1.potion=player1.potion-1;
                                    my_pokemon[0].hp.current_health=my_pokemon[0].hp.max_health;
                                    display_interface(title);
                                    gotoxy(2, 19); printf("Les PV de %s ont %ct%c restaur%cs.", my_pokemon[0].name, 130, 130, 130);
                                }
                                else if(player1.potion>0 && my_pokemon[0].hp.current_health==my_pokemon[0].hp.max_health)
                                {
                                    display_interface(title);
                                    gotoxy(2, 19); printf("Les PV de %s sont d%cja au maximum.", my_pokemon[0].name, 130);
                                }
                                else
                                {
                                    display_interface(title);
                                    gotoxy(2, 19); printf("Vous n'avez pas de potion.");
                                }
                                getch();
                                break;
                            }
                            case 2:
                                {
                                    display_interface(title);
                                    gotoxy(2, 19); printf("Vous n'etes pas en combat.");
                                    getch();
                                }
                            case 9: // retour au menu principal
                            {
                                break;
                            }
                            default:
                            {
                                break;
                            }
                        }
                    }while(menu_choice!=9);
                    break;
                }
            case 3: // P O K E D E X
                {
                    do
                    {
                        menu_choice=0;
                        title="P O K E D E X";
                        display_interface(title);
                        textbackground(LIGHTGRAY);
                        pokedex(pokedex1, LIN+2, COL+1);
                        textbackground(WHITE);
                        gotoxy(2, 19); printf("9. Retour");
                        gotoxy(2, 20); printf(">");
                        gotoxy(4, 20); fflush(stdin); car[0] = getch(); menu_choice = atoi(car);
                        switch(menu_choice)
                        {
                            case 9: // retour au menu principal
                                {
                                    break;
                                }
                            default:
                                {
                                    break;
                                }
                        }
                    }while(menu_choice!=9);
                    break;
                }
            case 4: // P O K E C E N T E R
                {
                    do
                    {
                        menu_choice=0;
                        title="P O K E C E N T E R";
                        display_interface(title);
                        textbackground(LIGHTGRAY);
                        textbackground(LIGHTRED); gotoxy(2, 3); printf("NOS SOINS");
                        textbackground(LIGHTGRAY);
                        gotoxy(2, 4); printf("Soins:");
                        gotoxy(3, 5); printf("restaure 100%% de la vie de votre pok%cmon", 130);
                        gotoxy(3, 6); printf("d%clai: 30 secondes", 130);
                        gotoxy(3, 7); printf("prix: gratuit");
                        gotoxy(2, 8); printf("PokeSoins:");
                        gotoxy(3, 9); printf("restaure 100%% de la vie de votre pok%cmon", 130);
                        gotoxy(3, 10); printf("d%clai: 4 secondes", 130);
                        gotoxy(3, 11); printf("prix: 100.00$");
                        textbackground(WHITE);
                        gotoxy(2, 19); printf("1. Soins");
                        gotoxy(2, 20); printf("2. PokeSoins");
                        gotoxy(2, 21); textcolor(BLACK); printf("9. Retour");
                        gotoxy(2, 22); printf(">");
                        gotoxy(4, 22); fflush(stdin); car[0] = getch(); menu_choice = atoi(car);
                        switch(menu_choice)
                        {
                            case 1: // soins
                            {
                                display_interface(title);
                                if(my_pokemon[0].hp.current_health<=0)
                                {
                                    for(i=30; i>=0; i--)
                                    {
                                        display_interface(title);
                                        textbackground(LIGHTGRAY);
                                        gotoxy(2, 3); printf("%s", my_pokemon[0].name);
                                        textbackground(RED); MYclrwin(9, 5, 21, 5); MYclrwin(7, 6, 23, 7); // Pokeball
                                        textbackground(BLACK); MYclrwin(7, 8, 23, 8); // Pokeball
                                        textbackground(DARKGRAY);MYclrwin(14, 8, 16, 8); // Pokeball
                                        textbackground(WHITE); MYclrwin(7, 9, 23, 10); MYclrwin(9, 11, 21, 11); // Pokeball
                                        health_bar(my_pokemon, 0, 13, 2, LNBAR);
                                        my_pokemon[0].hp.current_health+=my_pokemon[0].hp.max_health/30;
                                        textbackground(WHITE);
                                        gotoxy(2, 19); printf("Temps restant: %d", i);
                                        Sleep(1000);
                                    }
                                    my_pokemon[0].hp.current_health=my_pokemon[0].hp.max_health;
                                    display_interface(title);
                                    gotoxy(2, 19); printf("Les PV de %s ont %ct%c restaur%cs.", my_pokemon[0].name, 130, 130, 130);
                                }
                                else
                                {
                                    gotoxy(2, 19); printf("%s est encore en %ctat de combattre.", my_pokemon[0].name, 130);
                                }
                                getch();
                                break;
                            }
                            case 2: // pokesoins
                            {
                                display_interface(title);
                                if(my_pokemon[0].hp.current_health<=0 && player1.money>=100)
                                {
                                    for(i=4; i>=0; i--)
                                    {
                                        textbackground(LIGHTGRAY);
                                        gotoxy(2, 3); printf("%s", my_pokemon[0].name);
                                        textbackground(RED); MYclrwin(9, 5, 21, 5); MYclrwin(7, 6, 23, 7); // Pokeball
                                        textbackground(BLACK); MYclrwin(7, 8, 23, 8); // Pokeball
                                        textbackground(DARKGRAY);MYclrwin(14, 8, 16, 8); // Pokeball
                                        textbackground(WHITE); MYclrwin(7, 9, 23, 10); MYclrwin(9, 11, 21, 11); // Pokeball
                                        health_bar(my_pokemon, 0, 13, 2, LNBAR);
                                        my_pokemon[0].hp.current_health+=my_pokemon[0].hp.max_health/4;
                                        textbackground(WHITE);
                                        gotoxy(2, 19); printf("Temps restant: %d", i);
                                        Sleep(1000);
                                    }
                                    my_pokemon[0].hp.current_health=my_pokemon[0].hp.max_health;
                                    health_bar(my_pokemon, 0, 13, 2, LNBAR);
                                    player1.money=player1.money-100;
                                    display_interface(title);
                                    gotoxy(2, 19); printf("Les PV de %s ont %ct%c restaur%cs.", my_pokemon[0].name, 130, 130, 130);
                                }
                                else if(my_pokemon[0].hp.current_health<=0 && player1.money<100)
                                {
                                    gotoxy(2, 19); textbackground(LIGHTGRAY); printf("Vous n'avez pas assez d'argent.");
                                }
                                else
                                {
                                    gotoxy(2, 19); textbackground(LIGHTGRAY); printf("%s est encore en %ctat de combattre.", my_pokemon[0].name, 130);
                                }
                                getch();
                                break;
                            }
                            case 9: // retour au menu principal
                            {
                                break;
                            }
                            default:
                            {
                                break;
                            }
                        }
                    }while(menu_choice!=9);
                    break;
                }
            case 5: // B O U T I Q U E
                {
                    do
                    {
                        menu_choice=0;
                        title="B O U T I Q U E";
                        display_interface(title);
                        textbackground(LIGHTRED); gotoxy(2, 3); printf("NOS OBJETS");
                        textbackground(LIGHTGRAY);
                        gotoxy(2, 4); printf("Potion:");
                        gotoxy(3, 5); printf("restaure 100%% de la vie de votre pok%cmon", 130);
                        gotoxy(3, 6); printf("prix: 75.00$");
                        gotoxy(2, 8); printf("Pok%cball:",130);
                        gotoxy(3, 9); printf("permet de capturer des pok%cmons", 130);
                        gotoxy(3, 10); printf("prix: 25.00$");
                        textbackground(WHITE);
                        gotoxy(2, 19); printf("1. Potion");
                        gotoxy(2, 20); printf("2. Pok%cball", 130);
                        gotoxy(2, 21); textcolor(BLACK); printf("9. Retour");
                        gotoxy(2, 22); printf(">");
                        gotoxy(4, 22); fflush(stdin); car[0] = getch(); menu_choice = atoi(car);
                        switch(menu_choice)
                        {
                            case 1: // acheter une potion
                            {
                                if(player1.money>=75)
                                {
                                    player1.potion=player1.potion+1;
                                    player1.money=player1.money-75;
                                    display_interface(title);
                                    gotoxy(2, 19); printf("Vous avez achet%c une potion.", 130);
                                }
                                else
                                {
                                    display_interface(title);
                                    gotoxy(2, 19); printf("Vous n'avez pas assez d'argent.");
                                }
                                getch();
                                break;
                            }
                            case 2: // acheter une pokeball
                            {
                                if(player1.money>=25)
                                {
                                    pokeball[0].quantity++;
                                    player1.money=player1.money-25;
                                    display_interface(title);
                                    gotoxy(2, 19); printf("Vous avez achet%c une pok%cball.", 130, 130);
                                }
                                else
                                {
                                    display_interface(title);
                                    gotoxy(2, 19); printf("Vous n'avez pas assez d'argent.");
                                }
                                getch();
                                break;
                            }
                            case 9: // retour au menu principal
                            {
                                break;
                            }
                            default:
                            {
                                break;
                            }
                        }
                    }while(menu_choice!=9);
                    break;
                }
            case 9: // A B A N D O N N E R
                {
                    title="A B A N D O N N E R";
                    display_interface(title);
                    gotoxy(2, 19); printf("Es-tu certain de vouloir abandonner ? (o|n)");
                    gotoxy(2, 20); printf(">");
                    do
                    {
                        MYclrwin(4, 20, 80, 20);
                        gotoxy(4, 20); fflush(stdin); surrend = getch();
                    }while(surrend!='o' && surrend!='n');
                    break;
                }
            default:
                {
                    break;
                }
        }
    }while(surrend=='n');

    return (0);
}
