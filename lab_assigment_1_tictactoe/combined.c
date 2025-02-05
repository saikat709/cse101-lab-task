#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

char a = ' ', b = ' ', c = ' ', 
     d = ' ', e = ' ', f = ' ', 
     g = ' ', h = ' ', i = ' ';

int curr_player = 1;
int is_bot = false;

void show_positions(){
    printf( "\nMind these positions: \n" );
    printf( " 1 | 2 | 3 \n" );
    printf( "---|---|---\n" );
    printf( " 4 | 5 | 6 \n" );
    printf( "---|---|---\n" );
    printf( " 7 | 8 | 9 \n\n" );
    printf( "Make moves according to these positions. \n\n" );
}

void print_the_grid(){
    printf(" %c | %c | %c \n", a, b, c);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", d, e, f);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", g, h, i);
}

void make_move(int move){
    char curr_char = 'O';
    if ( curr_player == 2 ) curr_char = 'X'; 

    switch (move){
        case 1: a = curr_char; break;
        case 2: b = curr_char; break;
        case 3: c = curr_char; break;
        case 4: d = curr_char; break;
        case 5: e = curr_char; break;
        case 6: f = curr_char; break;
        case 7: g = curr_char; break;
        case 8: h = curr_char; break;
        case 9: i = curr_char; break;
        default: break;
    }
}

bool has_found_winner(){
    if ( ( a == b && b == c && a != ' ' ) ||
         ( d == e && e == f && d != ' ' ) ||
         ( g == h && h == i && g != ' ' ) ||
         ( a == d && d == g && a != ' ' ) ||
         ( b == e && e == h && b != ' ' ) ||
         ( c == f && f == i && c != ' ' ) ||
         ( a == e && e == i && a != ' ' ) ||
         ( c == e && e == g && c != ' ' ) 
    ) return true;
    return false;
}

bool is_valid_move(int move) {
    switch (move)
    {
        case 1: return a == ' ';
        case 2: return b == ' ';
        case 3: return c == ' ';
        case 4: return d == ' ';
        case 5: return e == ' ';
        case 6: return f == ' ';
        case 7: return g == ' ';
        case 8: return h == ' ';
        case 9: return i == ' ';
        default: return true;
    }
}

int get_user_move(){
    char move = -1;

    if ( is_bot ) printf("Person(You) > Enter your move position: ");
    else printf("Person %d > Enter your move position: ", curr_player);
    
    scanf(" %c", &move);

    if ( move == 'q' || move == 'Q') exit(0);

    move = move - '0';
    while(move < 1 || move > 9 || !is_valid_move(move)){
        if ( is_bot ) printf("Person(You)> Enter valid position: ");
        else printf("Person %d > Enter valid position: ", curr_player);
        scanf(" %c", &move);
        move = move - '0';
    }
    
    return move;
}

int get_bot_move(){

    printf("Bot is making move...\n");
    sleep(1);
    printf("Bot got a move...\n");
    sleep(1);
    int move = rand()%9+1;
    while( move<1 || move>9 || !is_valid_move(move) ) move = rand()%9+1;
    printf("Bot's move is: %d\n", move);
    return move;
    
}


void play_game(){
    bool is_playing = true;
    int move;
    int move_count = 0;

    printf("Player 1 uses 'O' \n");
    if ( is_bot ) printf("And, Bot uses 'X' \n");
    else printf("Player 2 uses 'X' \n");
    printf("You can press 'q' or 'Q' to quit anytime. \n");
    show_positions();
    
    while (is_playing)
    {   
        print_the_grid();
        printf("\n");

        if ( move_count >= 9 ){
            printf( "It is a draw!! \n" );
            break;
        }

        if( curr_player == 2 && is_bot) move = get_bot_move();
        else move = get_user_move();

        move_count++;
        make_move(move);

        if( has_found_winner() ){
            print_the_grid();
            if ( curr_player == 1 ){
                if ( is_bot ) printf("You WON !!!!!!!!\n");
                else printf("Player 1 WON !!!!!!!!\n");
            } else {
                if (is_bot ) printf("Bot WON !!!!!!!!\n");
                else printf("Player 2 WON !!!!!!!!\n");
            }
            break;
        }

        if ( curr_player == 1 ) curr_player = 2;
        else curr_player = 1;
    }
    
}


void select_playing_option(){
    int choice = -1;
    printf("You can play with Bot or Local friend. \n");\
    printf("1. Play with Bot \n");
    printf("2. Play with Local friend \n");

    printf("Enter your choice: \n");

    scanf("%d", &choice );

    while( choice < 1 && choice > 2){
        printf("Enter valid choice: \n");
        scanf("%d", &choice );
    }
    
    if (choice == 1) is_bot = true;
    else is_bot = false;
}


int main(){
    printf("=============Game Started============\n");
    bool is_playing = true;
    char wish;

    while (is_playing){

        select_playing_option();
        play_game();

        printf("Do you with to play again? (y/n) \n>>>>>> ");
        scanf(" %c", &wish);

        if ( wish == 'y' || wish == 'Y'){
            is_playing = true;
            is_bot = false;
            a = ' ', b = ' ', c = ' ', 
            d = ' ', e = ' ', f = ' ', 
            g = ' ', h = ' ', i = ' ';
        }
        else is_playing = false;
    }
    
    printf("==============Game Ended=============\n");
    return 0;
}