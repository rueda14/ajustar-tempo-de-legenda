#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adjust_time(char *time_str, int seconds_to_add) {
    int hours, minutes, seconds, milliseconds;

    // Ler horas, minutos, segundos e milissegundos da string de tempo
    sscanf(time_str, "%02d:%02d:%02d,%03d", &hours, &minutes, &seconds, &milliseconds);

    // Adicionar os segundos
    seconds += seconds_to_add;

    // Ajustar minutos e horas conforme o caso
    if (seconds >= 60) {
        minutes += seconds / 60;
        seconds = seconds % 60;
    }
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes = minutes % 60;
    }

    // Escrever o novo tempo formatado na string original
    sprintf(time_str, "%02d:%02d:%02d,%03d", hours, minutes, seconds, milliseconds);
}

void process_srt_file(const char *input_filename, const char *output_filename, int seconds_to_add) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    if (!input_file || !output_file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), input_file)) {
        // Verificar se a linha contém uma marcação de tempo
        if (strstr(line, "-->") != NULL) {
            // Extrair os tempos de início e fim
            char start_time[13], end_time[13];
            sscanf(line, "%12s --> %12s", start_time, end_time);

            // Ajustar os tempos
            adjust_time(start_time, seconds_to_add);
            adjust_time(end_time, seconds_to_add);

            // Escrever a linha ajustada no arquivo de saída
            fprintf(output_file, "%s --> %s\n", start_time, end_time);
        } else {
            // Escrever linhas que não são marcações de tempo sem modificação
            fputs(line, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    const char *input_filename = "Back.to.the.Future.Part.2.1989.1080p.Brrip.x264.Deceit.YIFY.srt";
    const char *output_filename = "arquivo_ajustado.srt";
    int seconds_to_add = 4;

    process_srt_file(input_filename, output_filename, seconds_to_add);

    printf("Arquivo ajustado com sucesso!\n");
    return 0;
}
