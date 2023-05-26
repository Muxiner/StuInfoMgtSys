//
// Created by HappyMuxiner on 2023/5/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "./stumgt/define.c"

int main() {
    system("color 03");
    FileOpen();
    AA:
    Menu();
    ChoiceMenu();
    goto AA;
    return 0;
}