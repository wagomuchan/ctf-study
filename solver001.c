//2026/4/22 k.h.

//文字を前後にずらして暗号解読

#include<stdio.h>
#include<stdbool.h>

bool is_alphabet(char c){
    return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

char shifted_alphabet(char c, int shift){
    if(!is_alphabet(c)) return c;
    else{
        char base;
        //大文字過去も時価を判定
        if('a' <= c && c <= 'z') base = 'a';
        else base = 'A';
        return ((c - base + shift) % 26 + base);
    }
}

int main(void){
    char cipherstr[100];
    printf("解読したいシーザー暗号文字列を入力\n");

    scanf("%s", cipherstr);

    int shift;

    printf("何文字後ろにずらす？\n");

    scanf("%d", &shift);
    
    int i = 0;
    for(i = 0; cipherstr[i] != '\0'; i++){
        cipherstr[i] = shifted_alphabet(cipherstr[i], shift);
    }
    printf("答えは%s\n", cipherstr);
    return 0;
}