#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdio.h>

// Estructura WAV

typedef struct {
  char chunkID[4];
  int chunkSize;
  char format[4];
  char subchunk1ID[4];
  int subchunk1Size;
  short int audioFormat;
  short int numChannels;
  int sampleRate;
  int byteRate;
  short int blockAlign;
  short int bitsPerSample;
  char subchunk2ID[4];
  int subchunk2Size;
} WAV;

int main(int argc, char *argv[])
{
  FILE *w;
  WAV archivo;
  double time_to_advance;
  uint32_t num_samples, bytes_to_advance;


  
  // Abrir archivo WAV 
  w = fopen("seno_1.wav", "rb");
  
  // Leer archivo WAV
  fread(&archivo, sizeof(WAV), 1, w);

  // Mostrar información del archivo WAV
  printf("Chunk ID: %.*s\n", 4, archivo.chunkID);
  printf("Chunk size: %d\n", archivo.chunkSize);
  printf("Format: %.*s\n", 4, archivo.format);
  printf("Subchunk 1 ID: %.*s\n", 4, archivo.subchunk1ID);
  printf("Subchunk 1 size: %d\n", archivo.subchunk1Size);
  printf("Audio format: %d\n", archivo.audioFormat);
  printf("Number of channels: %d\n", archivo.numChannels);
  printf("Sample rate: %d\n", archivo.sampleRate);
  printf("Byte rate: %d\n", archivo.byteRate);
  printf("Block align: %d\n", archivo.blockAlign);
  printf("Bits per sample: %d\n", archivo.bitsPerSample);
  printf("Subchunk 2 ID: %.*s\n", 4, archivo.subchunk2ID);
  printf("Subchunk 2 size: %d\n", archivo.subchunk2Size);


  
    // Calcular el número de muestras de audio
    num_samples = (archivo.chunkSize - 36) * 8         
    /archivo.bitsPerSample /archivo.numChannels;
  
    // Solicitar el tiempo a avanzar al usuario
    printf("Introduce el tiempo a avanzar (en segundos): ");
    scanf("%lf", &time_to_advance);

    // Calcular el número de bytes a avanzar
    while (time_to_advance<=3)
      {
        bytes_to_advance = time_to_advance * archivo.sampleRate * archivo.blockAlign;  
        printf("Bytes avanzados: %d\n", bytes_to_advance);
        ++time_to_advance;
      }


  
  return 0;
  }
