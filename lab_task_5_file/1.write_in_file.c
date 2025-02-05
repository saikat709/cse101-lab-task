#include <stdio.h>
#include <string.h>

int main(){
    char fileName[50], content[100];

    printf("Filename: ");
    fgets(fileName, sizeof(fileName), stdin);
    printf("Content : ");
    fgets(content, sizeof(content), stdin);

    FILE* fileStream = fopen(fileName, "w");

    if (fileStream == NULL) {
      perror("Error opening file");
      return 1;
   }

    // fwrite(content, sizeof(content), strlen(content), fileStream);
    fprintf(fileStream, "%s", content);

    fclose(fileStream);
}