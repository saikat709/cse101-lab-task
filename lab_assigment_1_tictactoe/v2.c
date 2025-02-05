#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

char a = ' ', b = ' ', c = ' ', 
     d = ' ', e = ' ', f = ' ', 
     g = ' ', h = ' ', i = ' ';

int curr_player = 1;

void show_positions(){
    printf( "Mind this positions: \n" );
    printf( " 1 | 2 | 3 \n" );
    printf( "---|---|---\n" );
    printf( " 4 | 5 | 6 \n" );
    printf( "---|---|---\n" );
    printf( " 7 | 8 | 9 \n" );
    printf( "Make moves according to this position. \n\n" );
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
    return ( ( a == b && b == c && a != ' ' ) ||
         ( d == e && e == f && d != ' ' ) ||
         ( g == h && h == i && g != ' ' ) ||
         ( a == d && d == g && a != ' ' ) ||
         ( c == f && f == i && c != ' ' ) ||
         ( a == e && e == i && a != ' ' ) ||
         ( c == e && e == g && c != ' ' ) 
    ); 
}

bool is_valid_move(int move){
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
    printf("Person(You)> Enter your move position: ");
    scanf(" %c", &move);

    if ( move == 'q' || move == 'Q') exit(0);

    move = move - '0';
    while(move < 1 || move > 9 || !is_valid_move(move)){
        printf("Person(You)> Enter valid position: ");
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
    while(move<1 || move>9 || !is_valid_move(move)) move = rand()%9+1;
    printf("Bot's move is: %d\n", move);
    return move;
}


void play_game(){
    bool is_playing = true;
    int move;
    int move_count = 0;

    printf("Player 1 uses 'O' \n");
    printf("And, Bot uses 'X' \n");
    printf("You can press 'q' or 'Q' to quit anytime. \n\n");
    show_positions();
    
    while (is_playing)
    {   
        print_the_grid();
        printf("\n");

        if ( move_count >= 9 ){
            printf("It is a draw!!\n");
            break;
        }

        if( curr_player == 1 ) move = get_user_move();
        else move = get_bot_move();

        move_count++;
        make_move(move);

        if( has_found_winner() ){
            print_the_grid();
            if ( curr_player == 1 )
                printf("You WON !!!!!!!!\n");
            else
                printf("Bot WON !!!!!!!!\n");
            break;
        }

        if ( curr_player == 1 ) curr_player = 2;
        else curr_player = 1;
    }
    
}

int main(){
    printf("=============Game Started============\n");
    bool is_playing = true;
    char wish;

    while (is_playing){
        play_game();

        printf("Do you with to play again? (y/n) \n>>>>>> ");
        scanf(" %c", &wish);

        if ( wish == 'y' || wish == 'Y'){
            is_playing = true;
            a = ' ', b = ' ', c = ' ', 
            d = ' ', e = ' ', f = ' ', 
            g = ' ', h = ' ', i = ' ';
        }
        else is_playing = false;
    }
    
    
    printf("==============Game Ended=============\n");
    return 0;
}