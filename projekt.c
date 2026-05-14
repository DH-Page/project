// kell egy c program ami alap *insert prog nyelv* parancsot terminálba beírva, létrehoz egy exe fájlt. Ez a fájl legyen képes egy int main Hello world
//programot , már futtatható állapotban lenni. Ugyanazt a kódot NE ismételjük meg még egyszer! Pl. a C nyelv forráskódját, amit generálni akarunk, ne tároljuk el kétszer!
//A programunkban tárolt forráskódok legyenek könnyen módosíthatóak! Vagyis nem egyetlenegy sorba kellene belenyomni a komplett forráskódot!

#include <stdio.h>
#include<stdlib.h>
#include <string.h>

//verzioszam definialo micsoda

const char* version = "1.0.0";

//ide jonnek a templatek, ezek a forraskodok vagy mik.
//igy nem lesznek kulon szoveges fileban

const char* c_temp = 
"#include <stdio.h>\n"
"\n"
"const char* version = \"%s\";\n"
"\n"
"int main(){\n"
"    printf(\"verzio: %%s\\n\", version);\n"
"    printf(\"Hello World!\");\n"
"    return 0;\n"
"}";

const char* java_temp = 
"public class Main{\n"
"    static String version = \"%s\";\n"
"\n"
"   public static void main(String[] args){\n"
"        System.out.println(\"verzio: \" + version);\n"
"        System.out.println(\"Hello World!\");\n"
"    }\n"
"}\n";

const char* python_temp = 
"version = \"%s\"\n"
"def main():\n"
"    print(\"verzio: {}\".format(version))\n"
"    print(\"Hello World!\")\n"
"    return 0\n"
"if __name__ == \"__main__\":\n"
"  main()";

const char* bash_temp =

"#!/bin/bash\n"
"\n"
"VERSION=\"%s\"\n"
"\n"
"echo \"verzio: $VERSION\"\n"
"echo \"Hello World!\"";

// asszem ezek kellenek idk bash tho.. or java 

//no itt kolkl generalni a kis exe fileokat ig

void gen_code(const char* lang){
    FILE *pointer = NULL; //pointer a fileohoz
     if(strcmp(lang, "c") == 0){
        pointer = fopen("hello.c", "w");
        fprintf(pointer, c_temp, version);
     }
     else if(strcmp(lang, "java") == 0){
        pointer = fopen("Main.java", "w");
        fprintf(pointer, java_temp, version);
     }
     else if(strcmp(lang, "python") == 0){
        pointer = fopen("hello.py", "w");
        fprintf(pointer, python_temp, version);
     }
     else if(strcmp(lang, "bash") == 0){
        pointer = fopen("hello.sh", "w");
        fprintf(pointer, bash_temp, version);
     }
     else{
        printf("nem támogatott nyelv !\n");
        return;
     }
     fclose(pointer);
     printf("file sikeresen létrehozva %s névvel.\n", lang);
}
//main fuggveny vegre mar rohad auz ujjam

int main(){
    char lang[30];
    printf("adj meg egy nyelvet (c/java/python/bash):\n");
    scanf("%s", lang);
    gen_code(lang);

    return 0;
}
