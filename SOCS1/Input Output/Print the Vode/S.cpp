#include <stdio.h>

int main(int argc, char const *argv[])
{
    char kalimat[100];

    scanf("%[^\n]", kalimat);

    printf(
        "#include <stdio.h>\nint main()\n{\n    printf(\"%%s\\n\",\"%s\");\n    return 0;\n}\n", kalimat
    );

    return 0;
}
