#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct RGB{
    int r;
    int g; 
    int b;
    int last;
};

void rgbSet(struct RGB *, int, int, int);
void rgbInvert(struct RGB *);
char *rgbStr(struct RGB *);
struct RGB *get_inverted_colors(char *);

int main(int argc, char **argv){
    struct RGB *inverted = get_inverted_colors(argv[1]);
    int i = 0;
    char *s; 

    if(argc != 2){
        printf("Usage: 1 argument only\n");
        exit(-1); //Close Program
    }
    for(i = 0; !inverted[i].last; i++){
        s = rgbStr(&inverted[i]);
        printf("%s\n\n", s);
        free(s);
    }
    free(inverted);
}

void rgbSet(struct RGB *rgb, int r, int g, int b){
    if(r + g + b <= 255 * 3 && (r >= 0 && g >= 0 && b >= 0)){
        rgb->r = r;
        rgb->g = g;
        rgb->b = b;
    }
}

void rgbInvert(struct RGB *rgb){
    rgbSet(rgb, 255 - rgb->r, 255 - rgb->g, 255 - rgb->b);
}

char *rgbStr(struct RGB *rgb){
    char *str = malloc(sizeof(char) * 64);
    sprintf(
        str, "RGB: (%i, %i, %i)\nHEX: 0x%02x%02x%02x",
        rgb->r, rgb->g, rgb->b, 
        rgb->r, rgb->r, rgb->r
    );
    return str;
}

struct RGB *get_inverted_colors(char *file){
    int limit = 4;
    struct RGB *inverted = malloc(sizeof(struct RGB) * limit);
    int lineSize = 16;
    char *line = malloc(sizeof(char) * lineSize);
    int i = 0, j = 0;
    int values[3];
    char *split;

    FILE *f = fopen(file, "r");
    while(fgets(line, lineSize, f)){
        if(i >= limit - 1){
            limit *= 2;
            inverted = realloc(inverted, sizeof(struct RGB) * limit);
        }
        split = strdup(line);
        for(j = 0; j < 3; j++){
            values[j] = atoi(strsep(&split, " "));
        }
        rgbSet(&inverted[i], values[0], values[1], values[2]);
        inverted[i].last = 0; //False
        rgbInvert(&inverted[i++]);
    }
    inverted[i].last = 1; //True
    free(line);
    fclose(f);
    return inverted;
}
