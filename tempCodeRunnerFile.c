#include <stdio.h>
#include <string.h>

void encrypt_character(char char_to_encrypt, char *encrypted_text) {
    if (char_to_encrypt == '\t') {
        strcat(encrypted_text, "TT");
    } else if (char_to_encrypt != '\n') {
        char out_char = char_to_encrypt - 16;
        if (out_char < 32) {
            out_char = (out_char - 32) + 144;
        }
        char hex_value[3];
        snprintf(hex_value, sizeof(hex_value), "%02X", out_char);
        strcat(encrypted_text, hex_value);
    } else {
        strcat(encrypted_text, "\n");
    }
}

void encrypt_line(char *line, char *encrypted_line) {
    for (int i = 0; i < strlen(line); i++) {
        encrypt_character(line[i], encrypted_line);
    }
}

void process_file(const char *input_file, const char *output_file) {
    FILE *infile = fopen(input_file, "r");
    FILE *outfile = fopen(output_file, "w");
    if (infile == NULL || outfile == NULL) {
        printf("Error opening files.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), infile)) {
        char encrypted_line[512] = "";
        encrypt_line(line, encrypted_line);
        fprintf(outfile, "%s", encrypted_line);
    }

    fclose(infile);
    fclose(outfile);
    printf("Encryption successful. Encrypted data saved in %s\n", output_file);
}

int main() {
    const char *input_file = "encrypt_this2.txt";
    const char *output_file = "output.crp";
    process_file(input_file, output_file);
    return 0;
}
