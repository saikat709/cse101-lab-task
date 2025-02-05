#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

const char texts[10][1000] = {
    "The quick brown fox jumps over the lazy dog, showcasing the agility of the fox and the relaxed demeanor of the dog, making it a perfect sentence to test every letter in the English language while improving typing speed and accuracy.",
    "Typing fast requires regular practice with a focus on accuracy, as developing muscle memory and proper finger placement over time allows the typist to achieve both speed and efficiency while reducing the risk of repetitive strain injuries.",
    "Artificial intelligence continues to revolutionize various industries, from healthcare to finance, by enabling machines to learn from data, make decisions, and perform tasks that traditionally required human intelligence, thus reshaping our digital landscape.",
    "Coding challenges are an effective way to enhance problem-solving skills, improve logical reasoning, and develop a deep understanding of algorithms, data structures, and programming concepts essential for technical interviews and competitive programming."
    "Consistency plays a vital role in mastering any skill, as regular and deliberate practice over an extended period helps solidify habits, build confidence, and ultimately lead to noticeable improvement in performance across various fields.",
    "A journey of a thousand miles begins with a single step, emphasizing that even the most ambitious goals can be achieved by starting small, staying persistent, and breaking complex tasks into manageable steps along the way.",
    "Stay curious, keep learning, and never stop growing, for personal growth is a lifelong journey where the pursuit of knowledge and self-improvement often opens doors to new opportunities and transformative experiences.",
    "The art of communication involves not just speaking clearly but also listening actively, understanding diverse perspectives, and conveying ideas in a way that fosters collaboration, mutual respect, and positive relationships in both personal and professional settings.",
    "Success is not merely the result of hard work alone but often a combination of perseverance, adaptability, and the ability to stay motivated through challenges, setbacks, and continuous learning along the way.",
    "Perseverance, hard work, and self-discipline often serve as the foundation for extraordinary achievements, as consistent effort in the face of adversity and failure can lead to personal growth, resilience, and remarkable success stories."
};

int main(){
    int play = 1;
    char textToWriteInd, textWrittenInd = 0;
    size_t time_start, time_end;

    while( play ){
        char textWritten[1000] = {};
        int totalLength = 0, writtenLength = 0, correct = 0, incorrect = 0, writtenWords = 0;
        float accuracy = 0.0, wpm = 0.0;

        textToWriteInd = rand() % 10;

        printf("%d\n", textToWriteInd);
        printf( "\n=========TEXT TO WRITE============\n" );
        printf( "%s\n", texts[textToWriteInd] );
        printf( "================================\n\n" );
        printf( "Start writing.. [ Pressing ENTER means writing finished.. ]\n" );

        totalLength = strlen(texts[textToWriteInd]);
        time_start = time(NULL);
        scanf("%[^\n]%*c", textWritten);
        time_end = time(NULL);
        writtenLength = strlen(textWritten);

        for( int i = 0; i < writtenLength + 1 + 1; ++i ){
            if ( textWritten[i] == ' ' || (  textWritten[i-1] != ' ' && textWritten[i] == '\0' ) ){
                writtenWords++;
            }
        }

        for( int i = 0; i < writtenLength; ++i ){
            if ( texts[textToWriteInd][i] == textWritten[i] ) correct++;
            else incorrect++;
        }

        wpm = writtenWords * 60 /( time_end - time_start + 0.0);
        accuracy = correct * 100 / ( float ) writtenLength;
        printf("\n#############  Report\n");
        printf("$$ Correct   : %d\n", correct);
        printf("$$ Incorrect : %d\n", incorrect);
        printf("$$ WPM       : %d\n", writtenWords);
        printf("$$ Accuracy  : %f%%\n", accuracy);
        printf("$$ Time taken: %d\n", (int) ( time_end - time_start ) );
        printf("#############    \n");

        printf("Do you wan to write again(y) or exit ( q ): " );
        char res; scanf(" %c", &res);
        if ( res == 'y' || res == 'Y' ) play = 1;
        else play = 0;
    }

    return 0;
}