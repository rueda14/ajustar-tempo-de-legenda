# Ajuste de Tempo em Legendas SRT
## Utilitário simples em C para correção de sincronização

Este projeto é um pequeno utilitário desenvolvido em linguagem C para ajustar o tempo de legendas no formato `.srt`. Ele foi criado para resolver um problema prático de sincronização entre áudio e legenda, aplicando um deslocamento fixo de segundos diretamente nas marcações de tempo do arquivo.

O programa lê um arquivo de legenda, identifica as linhas que contêm marcações de tempo e gera um novo arquivo com os tempos ajustados, mantendo o texto original da legenda inalterado.

---

## Objetivo
- Corrigir legendas que estejam adiantadas ou atrasadas em relação ao áudio
- Aplicar um deslocamento fixo de tempo em segundos
- Gerar um novo arquivo `.srt` com os tempos corrigidos

---

## Funcionamento
- O arquivo `.srt` é lido linha por linha
- Linhas que contêm o separador `-->` são identificadas como marcações de tempo
- O tempo inicial e final são extraídos no formato `HH:MM:SS,mmm`
- Um valor fixo de segundos é adicionado ao tempo
- Segundos, minutos e horas são normalizados quando necessário
- O resultado é gravado em um novo arquivo de saída
- Linhas que não contêm marcações de tempo são copiadas sem modificação

---

## Estrutura do Código
- Função `adjust_time`
  - Converte a string de tempo em valores numéricos
  - Soma o deslocamento em segundos
  - Ajusta segundos, minutos e horas
  - Reescreve o tempo no formato padrão
- Função `process_srt_file`
  - Abre os arquivos de entrada e saída
  - Processa cada linha do arquivo
  - Aplica o ajuste apenas nas linhas de tempo
- Função `main`
  - Define o arquivo de entrada
  - Define o arquivo de saída
  - Define o valor do deslocamento em segundos
  - Executa o processamento do arquivo

---

## Compilação
Utilize o compilador GCC em sistemas Linux:

```bash
gcc -o srt_adjust srt_adjust.c
./srt_adjust
```

- O programa utiliza
  - Um arquivo .srt de entrada definido diretamente no código
  - Um arquivo .srt de saída gerado automaticamente
  - Um deslocamento fixo de 4 segundos

---

## Autor

Projeto desenvolvido por **Diego Rueda** para fins acadêmicos e de estudo, com o objetivo de praticar programação em linguagem C, manipulação de arquivos e resolução de problemas reais de forma simples e funcional.

